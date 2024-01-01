// Cross-platform application information.  For Unicode application strings, see 'UTF8::AppInfo'.

#ifndef MECHANIKA_ENVIRONMENT_APPINFO
#define MECHANIKA_ENVIRONMENT_APPINFO

#include <cstdint>

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
	#include <windows.h>
#else
	#include <sys/types.h>
	#include <unistd.h>
	#include <pthread.h>
#endif

namespace Mechanika
{
	namespace Environment
	{
#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
		typedef DWORD ProcessIDType;
		typedef DWORD ThreadIDType;
#else
		typedef pid_t ProcessIDType;
		typedef pthread_t ThreadIDType;
#endif

		class AppInfo
		{
		public:
			static ProcessIDType GetCurrentProcessID();
			static ThreadIDType GetCurrentThreadID();
			static std::uint64_t GetUnixMicrosecondTime();
		};
	}
}

#endif
