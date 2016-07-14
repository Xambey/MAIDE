#include "ArchiverForm.h"
#include "AboutProgram.h"
//#include "HArchiver.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(cli::array<String^> ^argc)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HArchiver::ArchiverForm form;
	Application::Run(%form);
}
