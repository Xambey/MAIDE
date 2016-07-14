#include "HArchiver.h"

typedef unsigned char byte;


void Archiver::Archive(System::String^ input, System::String^ output)
{
	try {
		string inp, format;
		
		MarshalString(input, inp); //String to string transform

		//write format file
		for (auto it = inp.rbegin(); it != inp.rend(); it++) {
			if (*it == '.')
				break;
			format += *it;
		}
		ifstream in(inp, ios_base::binary);
		if (!in.is_open())
			throw "File not found";

		in.seekg(0, ios::end);
		long size = (long)in.tellg();
		in.seekg(0, 0);

		char* DataFile = new char[size];
		in.read(DataFile, size);
		in.close();

		buf = gcnew List<Code^ >(256);
		for (size_t i = 0; i < 256; i++)
			buf->Add(gcnew Code);
		CreateTree(DataFile, size);

		char* EncryptDate = new char[size];
		memset(EncryptDate, 0, sizeof(EncryptDate));

		char offest = 0;
		long j = 0;

		
		for (long i = 0; i < size; i++)
		{
			Code^ code = buf[(byte)DataFile[i]];

			EncryptDate[j] |= code->value << offest;
			offest += code->size;
			while (offest > 7)
			{
				offest -= 8;
				EncryptDate[++j] = code->value >> (code->size - offest);
			}
		}
		delete[] DataFile;

		string ou;
		MarshalString(output, ou);
		ofstream out(ou, ios_base::binary);

		//write format
		int len = format.length();
		char s = (char) len;

		out.write(&s, 1);
		for (auto it = format.rbegin(); it != format.rend(); it++)
		{
			out.write(&(*it), 1);
		}
		
		//write buf
		for (size_t i = 0; i < 256; i++)
		{
			if (buf[i] != nullptr) {
				char u = buf[i]->size;
				short v = buf[i]->value;
				out.write(&u, 1);
				if (u)
					out.write((char*)&v, sizeof(Code::value));
			}
		}
		//write encrypt data
		out.write(&offest, 1);
		out.write(EncryptDate, j + 1);
		//delete[] EncryptDate;
		out.close();
	}
	catch (exception&e)
	{
		cerr << e.what();
	}
}

Archiver::Item ^ Archiver::CreateTree()
{
	Item^ node = gcnew Item;
	node->left = CreateTree(Code() + 0);
	node->right = CreateTree(Code() + 1);
	return node;
}

Archiver::Item ^ Archiver::CreateTree(Archiver::Code code)
{
	for (size_t i = 0; i < 256; i++)
	{
		if (buf[i]->size == code.size && buf[i]->value == code.value)
			return gcnew Item((char)i);
	}

	Item^ node = gcnew Item;
	node->left = CreateTree(code + 0);
	node->right = CreateTree(code + 1);
	return node;
}

Archiver::Code Archiver::Code::operator+(char b)
{
	Code c;
	c.size = this->size + 1;
	c.value = value | (b << this->size);
	return c;
}


void Archiver::CreateTree(char * data, long size)
{
	if (!size)
		return;

	long count_buffer[256];
	memset(count_buffer, 0, sizeof(count_buffer));
	for (long i = 0; i < size; i++)
		count_buffer[(byte)data[i]]++;

	//vector<Item^> ls;

	List<Item^>^ls = gcnew List<Item^>(256);

	for (size_t i = 0; i < 256; i++)
	{
		if (count_buffer[(byte)i]) {
			ls->Add(gcnew Item((byte)i, count_buffer[(byte)i]));
			//ls.push_back(gcnew Item((byte)i, count_buffer[(byte)i]));
		}
	}
	while (ls->Count != 1)
	{
		//sort(ls.begin(), ls.end(), more/*[](Item^ i, Item^ j) {return i->count < j->count; }*/);
		long msize = ls->Count;
		for (int i = 0; i < ls->Count - 1; i++) {
			for (int j = 0; j < ls->Count - 1 - i; j++) {
				if (ls[j]->count > ls[j + 1]->count) {
					long t = ls[j]->count;
					ls[j]->count = ls[j + 1]->count;
					ls[j + 1]->count = t;
					//swap(ls[j], ls[j + 1]);
				}
			}
		}
		//:warning!!!!!!!
		Item^ tr = gcnew Item();
		tr->left = ls[0];
		tr->right = ls[1];
		tr->count = tr->left->count + tr->right->count;
		ls->RemoveRange(0, 2);
		/*List<Item^>^ls2 = gcnew List<Item^>(ls->Count);*/
		ls->Add(tr);
		//ls.erase(ls.erase(ls.begin()));
		//ls.push_back(tr);
		//ls2->res
		//long len = ls2->Length;
		//ls2[len] = tr;
		//ls = ls2;
	}
	ls[0]->collapse(gcnew Code(),buf);
}

Archiver::Archiver()
{
}


void Archiver::UnArchive(System::String^ input, System::String^ output)
{
	string inp;
	MarshalString(input, inp);
	ifstream in(inp, ios_base::binary);
	if (!in.is_open())
		throw "File not found";

	buf = gcnew List<Code^ >(256);
	char si;
	in.read(&si, 1);
	int siInt = (int)si;
	for (int i = 0; i < siInt; i++) {
		in.read(&si, 1);
	}
	for (size_t i = 0; i < 256; i++)
	{
		buf->Add(gcnew Code);
		char t;
		short v;
		in.read(&t, 1);
		buf[i]->size = t;
		if (t) {
			in.read((char*)&v, sizeof(Code::value));
			buf[i]->value = v;
		}
	}
	char overOffest;
	in.read(&overOffest, 1);

	long size = (long)in.tellg();
	in.seekg(0, ios::end);
	size = (long)in.tellg() - size;
	in.seekg(-size, ios::cur);

	char* data = new char[size];
	in.read(data, size);
	in.close();

	Item^ root = CreateTree();
	Item^ tr = root;

	char* result = new char[size * 8];

	int offest = 0;
	long j = 0;
	for (long i = 0; i < size;)
	{
		bool bit = data[i] & (1 << offest);
		offest++;
		if (offest > 7)
		{
			offest -= 8;
			i++;
		}
		tr = bit ? tr->right : tr->left;
		if (!tr->left)
		{
			result[j++] = tr->value;
			tr = root;
			if (i + 1 == size && offest == overOffest)
				break;
		}
	}

	delete[] data;
	delete root;

	string ou;
	MarshalString(output, ou);

	ofstream ofs(ou, ios_base::binary);
	ofs.write(result, j);
	ofs.close();

	delete[] result;
}

Archiver::Item::Item()
{
}

Archiver::Item::~Item()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

void Archiver::Item::collapse(Archiver::Code^ code, List<Code^>^bu)
{
	if (left && right)
	{
		left->collapse(%(code + 0), bu);
		right->collapse(%(code + 1), bu);
	}
	else
		bu[(byte)value] = code;
		
}


