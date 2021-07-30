#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <any>
#include <cstdint>
#include "exceptionhelper.h"
#include "bankersrounding.h"

using namespace Microsoft::Win32;
using namespace PANDA_BOOSTER::PandaBooster;

namespace PANDA_BOOSTER
{
	class MainWindow
	{
	private:
		DispatcherTimer *timer1;
		DispatcherTimer *timer2;
		DispatcherTimer *timer3;



	public:
		virtual ~MainWindow()
		{
			delete timer1;
			delete timer2;
			delete timer3;
			delete backgroundWorker1;
		}

		MainWindow();
	private:
		void TickMe();
		void TickMe3();
		System::ComponentModel::BackgroundWorker *backgroundWorker1 = new System::ComponentModel::BackgroundWorker();

		void backgroundWorker1_DoWork(std::any sender, DoWorkEventArgs *e);

	public:
		__declspec(dllimport) static int EmptyWorkingSet(std::intptr_t handle);

	private:
		__declspec(dllimport) static std::intptr_t GetProcAddress(std::intptr_t hModule, const std::wstring &methodName);

		__declspec(dllimport) static std::intptr_t GetModuleHandle(const std::wstring &moduleName);


	public:
		__declspec(dllimport) static std::intptr_t GetCurrentProcess();

		static bool DoesWin32MethodExist(const std::wstring &moduleName, const std::wstring &methodName);

		__declspec(dllimport) static bool IsWow64Process(std::intptr_t hSourceProcessHandle, bool &isWow64);

		static bool get_Is64BitOperatingSystem();
	private:
		void exit_Click(std::any sender, EventArgs *e);

		void show_Click(std::any sender, EventArgs *e);

		void Window_Loaded(std::any sender, RoutedEventArgs *e);
		void GraphUpdate();
		void ComboBox1_SelectedIndexChanged(std::any sender, EventArgs *e);

		void ComboBox2_SelectedIndexChanged(std::any sender, EventArgs *e);


		void TickMe2();
	public:
		void GetTemp();
	private:
		void btnlbl_MouseDown(std::any sender, MouseButtonEventArgs *e);

		void killbl_MouseDown(std::any sender, MouseButtonEventArgs *e);

		void killbl_MouseMove(std::any sender, MouseEventArgs *e);
		void killbl_MouseLevae(std::any sender, MouseEventArgs *e);

		void image1_MouseMove(std::any sender, MouseEventArgs *e);
		void image1_Mousel(std::any sender, MouseEventArgs *e);
		void image1_Moused(std::any sender, MouseEventArgs *e);
		static MainWindow *m_ins;



	public:
		static MainWindow *getIns();
	};
}
