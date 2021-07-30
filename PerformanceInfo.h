#pragma once

#include <cstdint>

namespace PANDA_BOOSTER::PandaBooster { class PerformanceInformation; }

namespace PANDA_BOOSTER
{
	namespace PandaBooster
	{
		class PerformanceInfo final
		{
		public:
			__declspec(dllimport) static <MarshalAs(UnmanagedType::Bool)> bool *GetPerformanceInfo(PerformanceInfo::PerformanceInformation &PerformanceInformation, int Size);

			static long long GetPhysicalAvailableMemoryInMiB();

			static long long GetTotalMemoryInMiB();

		public:
			class PerformanceInformation
			{
			public:
				int Size = 0;

				std::intptr_t CommitTotal;

				std::intptr_t CommitLimit;

				std::intptr_t CommitPeak;

				std::intptr_t PhysicalTotal;

				std::intptr_t PhysicalAvailable;

				std::intptr_t SystemCache;

				std::intptr_t KernelTotal;

				std::intptr_t KernelPaged;

				std::intptr_t KernelNonPaged;

				std::intptr_t PageSize;

				int HandlesCount = 0;

				int ProcessCount = 0;

				int ThreadCount = 0;
			};
		};
	}

}
