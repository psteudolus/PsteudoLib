#include "PoolAllocator.h"

namespace psteudo {
	namespace mem {

		PoolAllocator::PoolAllocator(U32 blockSize_bytes, U32 blockCount) {
			m_buffer = (char*)malloc(sizeof(char) * blockSize_bytes * blockCount);

			for (U32 currentBlock = 0; currentBlock < blockCount; ++currentBlock) {
				freeList.push_front(m_buffer + ((U64)blockSize_bytes * (U64)currentBlock));
			}
		}

		void* PoolAllocator::alloc() {
			auto front = freeList.front();
			void* ret = front;
			freeList.pop_front();
			return ret;
		}

		void PoolAllocator::dealloc(void* block) {
			freeList.push_front(block);
		}
	}
}


