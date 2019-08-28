#pragma once
#include "StackAllocator.h"

namespace psteudo {
	namespace memory {
		//constructs a stack allocator of specified size
		StackAllocator::StackAllocator(U32 stackSize_bytes) {
			m_pBuffer = (char*)malloc(sizeof(char) * stackSize_bytes);
			m_bufferSize = (U32) m_pBuffer + stackSize_bytes;
			m_currentSize = 0;
			m_currentMarker = (Marker)m_pBuffer;
		}

		//allocates the the specified amount of memory from the top of the stack
		void* StackAllocator::alloc(U32 size_bytes) {
			assert(m_currentMarker + size_bytes < m_bufferSize);
			void* pMem = m_pBuffer + m_currentSize;
			m_currentSize += size_bytes;
			return pMem;
		}

		//returns the current position in the stack
		StackAllocator::Marker StackAllocator::getMarker() {
			return m_currentMarker;
		}

		//frees memory back to the selected marker
		void StackAllocator::freeToMarker(StackAllocator::Marker marker) {
			m_currentMarker = marker;
		}

		//frees all memory in stack
		void StackAllocator::clear() {
			m_currentMarker = (Marker) m_pBuffer;
		}
	}
}