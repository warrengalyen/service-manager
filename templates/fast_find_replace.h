// Binary data single pattern finder with templated replace function.  Mostly for arrays of plain ol' data (POD) types.
// General performance is probably better than std::search and even possibly better than Boyer-Moore and Knuth-Morris-Pratt.

#ifndef FAST_FIND_REPLACE_H
#define FAST_FIND_REPLACE_H

#include <cstddef>
#include <new>

namespace Mechanika
{
	// FastFind and FastReplace.
	#include "fast_find_replace_util.h"

	// FastFind and FastReplace with custom allocator.
	#define MECHANIKA_FAST_FIND_REPLACE_MEMALLOC
	#include "fast_find_replace_util.h"
	#undef MECHANIKA_FAST_FIND_REPLACE_MEMALLOC

	// FastFind and FastReplace with custom element comparison.
	#define MECHANIKA_FAST_FIND_REPLACE_COMPAREFUNC
	#include "fast_find_replace_util.h"
	#undef MECHANIKA_FAST_FIND_REPLACE_COMPAREFUNC

	// FastFind and FastReplace with custom allocator and custom element comparison.
	#define MECHANIKA_FAST_FIND_REPLACE_MEMALLOC
	#define MECHANIKA_FAST_FIND_REPLACE_COMPAREFUNC
	#include "fast_find_replace_util.h"
	#undef MECHANIKA_FAST_FIND_REPLACE_COMPAREFUNC
	#undef MECHANIKA_FAST_FIND_REPLACE_MEMALLOC
}

#endif  /* FAST_FIND_REPLACE_H */
