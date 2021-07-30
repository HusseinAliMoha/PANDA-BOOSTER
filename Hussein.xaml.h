#pragma once

#include <any>

namespace PANDA_BOOSTER
{
	class Hussein
	{
	private:
		static Hussein *m_ins;

	public:
		static Hussein *getIns();
	private:

		void image1_MouseMove(std::any sender, MouseEventArgs *e);

		void image1_Mousel(std::any sender, MouseEventArgs *e);

		void image1_Moused(std::any sender, MouseEventArgs *e);

		void Window_Closing(std::any sender, System::ComponentModel::CancelEventArgs *e);
	};

}
