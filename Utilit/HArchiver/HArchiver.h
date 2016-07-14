#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cliext/vector> 
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace std;


ref class Archiver
{
	//code struct
	ref struct Code
	{
		short value;
		char size;
		Code() :value(0), size(0) {}
		Code(Code% c) :value(c.value), size(c.size) {}

		Code operator+(char b);
		//Code% Get(int i) { return ^(this); }
	};

	//Item of tree
	ref struct Item
	{
		long count;
		int value;
		Item^ left = nullptr, ^right = nullptr;
		Item();
		Item(int value) { this->value = value; }
		Item(int value, long count) { this->value = value; this->count = count; }
		~Item();
		//fill buf
		void collapse(Archiver::Code^ code, List<Code^>^bu);
	};
	//buf is extension table
	List<Code^ >^ buf;
	Item^ CreateTree();
	Item^ CreateTree(Archiver::Code code);
	void CreateTree(char* data, long size);
	bool more(Item^ i, Item^ j)
	{
		return ((i->count) < (j->count));
	}
public:
	Archiver();
	//archive file
	void Archive(System::String^ input, System::String^ output);
	//unarchive file
	void UnArchive(System::String^ input, System::String^ output);
	//cli::String to std::string
	void MarshalString(System::String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
};

