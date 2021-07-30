#include "Hussein.xaml.h"

namespace PANDA_BOOSTER
{

Hussein *Hussein::m_ins;

	Hussein *Hussein::getIns()
	{
		bool flag = Hussein::m_ins == nullptr;
		if (flag)
		{
			Hussein::m_ins = new Hussein();
		}
		return Hussein::m_ins;
	}

	void Hussein::image1_MouseMove(std::any sender, MouseEventArgs *e)
	{
		image1->Effect = new DropShadowEffect With {.Color = Colors::Red, .BlurRadius = 12, .ShadowDepth = 1};
	}

	void Hussein::image1_Mousel(std::any sender, MouseEventArgs *e)
	{
		image1->Effect = nullptr;
	}

	void Hussein::image1_Moused(std::any sender, MouseEventArgs *e)
	{
		Process::Start(L"https://discord.gg/6wfNWWNVRc");

	}

	void Hussein::Window_Closing(std::any sender, System::ComponentModel::CancelEventArgs *e)
	{
		e->Cancel = true;
		Hide();
	}
}
