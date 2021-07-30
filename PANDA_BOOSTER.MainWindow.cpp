#include "PANDA_BOOSTER.MainWindow.h"
#include "Globals1.h"
#include "PerformanceInfo.h"
#include "Hussein.xaml.h"

using namespace Microsoft::Win32;
using namespace PANDA_BOOSTER::PandaBooster;

namespace PANDA_BOOSTER
{

	MainWindow::MainWindow()
	{

		// This call is required by the designer.
		InitializeComponent();
		GetTemp();
		if (Process::GetProcessesByName(L"PANDA BOOSTER").size() > 1)
		{
			exit(0);
		}
		RegistryKey *key = nullptr;
		ServiceController *controller = nullptr;
		key = Registry::LocalMachine->OpenSubKey(L"Software\\Microsoft\\PANDA BOOSTER", true);

		if (key == nullptr)
		{
			Registry::LocalMachine->CreateSubKey(L"Software\\Microsoft\\PANDA BOOSTER");
			key = Registry::LocalMachine->OpenSubKey(L"Software\\Microsoft\\PANDA BOOSTER", true);
			key->SetValue(L"RAM", L"60");
			Globals1::RAMPercent = 59;
			key->SetValue(L"timer", L"60");
			Globals1::timerinterval = 60000;
		}
		else
		{
			Globals1::RAMPercent = std::any_cast<int>(key->GetValue(L"RAM")) - 1;
			Globals1::timerinterval = std::any_cast<int>(key->GetValue(L"timer")) * 1000;
		}


		timer1 = new DispatcherTimer();
		timer1->Interval = TimeSpan::FromMilliseconds(Globals1::timerinterval);
		AddHandler timer1->Tick, TickMe;
		timer1->Start();

		timer2 = new DispatcherTimer();
		timer2->Interval = TimeSpan::FromMilliseconds(5000);
		AddHandler timer2->Tick, TickMe2;
		timer2->Start();


		timer3 = new DispatcherTimer();
		timer3->Interval = TimeSpan::FromMilliseconds(1000);
		AddHandler timer3->Tick, TickMe3;
		timer3->Start();
		key->Close();

		if (get_Is64BitOperatingSystem())
		{

			try
			{
				key = Registry::LocalMachine->OpenSubKey(L"SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Run", true);
				key->SetValue(L"PANDA BOOSTER", L"\"" + System::Reflection::Assembly::GetExecutingAssembly()->Location + L"\"");
				key->Close();
			}
			catch (...)
			{
			}
		}
		else
		{

			try
			{
				key = Registry::CurrentUser->OpenSubKey(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);
				key->SetValue(L"PANDA BOOSTER", L"\"" + System::Reflection::Assembly::GetExecutingAssembly()->Location + L"\"");
				key->Close();
			}
			catch (...)
			{
			}
		}

		try
		{
			controller = new ServiceController(L"XblAuthManager");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"XblGameSave");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"XboxGip");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"XboxGipSvc");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"XboxNetApiSvc");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"edgeupdate");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"edgeupdatem");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"wuauserv");
			controller->Stop();
		}
		catch (...)
		{
		}

		try
		{
			controller = new ServiceController(L"WaaSMedicSvc");
			controller->Stop();
		}
		catch (...)
		{
		}

		DirectoryInfo *directory = new DirectoryInfo(Path::GetTempPath());

		for (auto file : *directory->GetFiles())
		{

			try
			{
				file->Delete();
			}
			catch (...)
			{
			}
		}

		for (auto dir : *directory->GetDirectories())
		{

			try
			{
				dir->Delete(true);
			}
			catch (...)
			{
			}
		}

		directory = new DirectoryInfo(Environment::GetEnvironmentVariable(L"TEMP", EnvironmentVariableTarget::Machine));

		for (auto file : *directory->GetFiles())
		{

			try
			{
				file->Delete();
			}
			catch (...)
			{
			}
		}

		for (auto dir : *directory->GetDirectories())
		{

			try
			{
				dir->Delete(true);
			}
			catch (...)
			{
			}
		}
