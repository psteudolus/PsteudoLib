#pragma once

#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <forward_list>

namespace psteudo {
	namespace mem {

		class PoolAllocator
		{
		public:
			//don't want to type std::uintxx_t all the time
			typedef std::uint32_t U32;
			typedef std::uint64_t U64;

			//constructs pool allocator for specified blocksize
			explicit PoolAllocator(U32 blockSize_bytes, U32 blockCount);

			//allocates first free memory block
			void* alloc();

			//returns block of memory to linked list of freeblocks
			void dealloc(void* block);

		private:
			U32 m_blockSize_bytes;
			U32 m_blockCount;
			std::forward_list<void*> freeList;
			char* m_buffer;
		};
	}
}

