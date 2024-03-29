// Cross-platform, optionally named (cross-process), reader/writer lock.

#ifndef MECHANIKA_SYNC_READWRITELOCK
#define MECHANIKA_SYNC_READWRITELOCK

#include "sync_util.h"

namespace Mechanika
{
	namespace Sync
	{
		class ReadWriteLock
		{
		public:
			ReadWriteLock();
			~ReadWriteLock();

			bool Create(const char *Name = NULL);

			// Wait is in milliseconds.  Granularity is in 5ms-15ms intervals on some platforms.
			bool ReadLock(std::uint32_t Wait = INFINITE);

			// Wait is in milliseconds.  Granularity is in 5ms-15ms intervals on some platforms.
			bool WriteLock(std::uint32_t Wait = INFINITE);

			bool ReadUnlock();
			bool WriteUnlock();

			// Automatically unlock a read lock when leaving the current scope.
			class AutoReadUnlock
			{
			public:
				AutoReadUnlock(ReadWriteLock *LockPtr);
				~AutoReadUnlock();

			private:
				// Deny copy constructor and assignment operator.  Use a (smart) pointer instead.
				AutoReadUnlock(const AutoReadUnlock &);
				AutoReadUnlock &operator=(const AutoReadUnlock &);

				ReadWriteLock *MxLock;
			};

			// Automatically unlock a write lock when leaving the current scope.
			class AutoWriteUnlock
			{
			public:
				AutoWriteUnlock(ReadWriteLock *LockPtr);
				~AutoWriteUnlock();

			private:
				// Deny copy constructor and assignment operator.  Use a (smart) pointer instead.
				AutoWriteUnlock(const AutoWriteUnlock &);
				AutoWriteUnlock &operator=(const AutoWriteUnlock &);

				ReadWriteLock *MxLock;
			};

		private:
			// Deny copy constructor and assignment operator.  Use a (smart) pointer instead.
			ReadWriteLock(const ReadWriteLock &);
			ReadWriteLock &operator=(const ReadWriteLock &);

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
			HANDLE MxWinRSemMutex, MxWinRSemaphore, MxWinRWaitEvent, MxWinWWaitMutex;
#else
			bool MxNamed;
			char *MxMem;
			Util::UnixSemaphoreWrapper MxPthreadRCountMutex;
			volatile std::uint32_t *MxRCount;
			Util::UnixEventWrapper MxPthreadRWaitEvent;
			Util::UnixSemaphoreWrapper MxPthreadWWaitMutex;
#endif
		};
	}
}

#endif
