#include "PerformanceInfo.h"

namespace PANDA_BOOSTER
{
	namespace PandaBooster
	{

		long long PerformanceInfo::GetPhysicalAvailableMemoryInMiB()
		{
			PerformanceInfo::PerformanceInformation pi;
			if (PerformanceInfo::GetPerformanceInfo(pi, System::Runtime::InteropServices::Marshal::SizeOf(pi)))
			{
				return static_cast<long long>(pi.PhysicalAvailable.ToInt64() * pi.PageSize.ToInt64() / 1048576LL.0);
			}
			return -1LL;
		}

		long long PerformanceInfo::GetTotalMemoryInMiB()
		{
			PerformanceInfo::PerformanceInformation pi;
			if (PerformanceInfo::GetPerformanceInfo(pi, System::Runtime::InteropServices::Marshal::SizeOf(pi)))
			{
				return static_cast<long long>(pi.PhysicalTotal.ToInt64() * pi.PageSize.ToInt64() / 1048576LL.0);
			}
			return -1LL;
		}
	}
}
