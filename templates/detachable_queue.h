// Queue with detachable nodes.

#ifndef DETACHABLE_QUEUE_H
#define DETACHABLE_QUEUE_H

#include <cstddef>

namespace Mechanika
{
	template <class T>
	class Queue;
	template <class T>
	class QueueNoCopy;

	template <class T>
	class QueueNode
	{
		friend class Queue<T>;
		friend class QueueNoCopy<T>;

	public:
		QueueNode() : NextNode(NULL)
		{
		}

		inline QueueNode<T> *Next()  { return NextNode; }

	private:
		QueueNode<T> *NextNode;

	public:
		T Value;
	};

	// Queue.  A single linked list.
	#include "detachable_queue_util.h"

	// QueueNoCopy.  A single linked list with a private copy constructor and assignment operator.
	#define MECHANIKA_DETACHABLE_QUEUE_NOCOPYASSIGN
	#include "detachable_queue_util.h"
	#undef MECHANIKA_DETACHABLE_QUEUE_NOCOPYASSIGN
}

#endif  /* DETACHABLE_QUEUE_H */
