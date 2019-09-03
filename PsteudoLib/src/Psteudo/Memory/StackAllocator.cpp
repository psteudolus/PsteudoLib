#pragma once
#include "StackAllocator.h"

namespace psteudo {
	namespace mem {
		//constructs a stack allocator of specified size
		StackAllocator::StackAllocator(U32 stackSize_bytes) {
			m_pBuffer = (char*)malloc(sizeof(char) * stackSize_bytes);
			m_maxMarker = (Marker)m_pBuffer + sizeof(char) * stackSize_bytes;
			m_currentMarker = (Marker)m_pBuffer;
		}

		//allocates the the specified amount of memory from the top of the stack
		void* StackAllocator::alloc(U32 size_bytes) {
			assert(m_currentMarker + sizeof(char) * size_bytes < m_maxMarker);
			void* pMem = (void*)m_currentMarker;
			m_currentMarker += sizeof(char) * size_bytes;
			return pMem;
		}

		//returns the current position in the stack
		Marker StackAllocator::getMarker() {
			return m_currentMarker;
		}

		//frees memory back to the selected marker
		void StackAllocator::freeToMarker(Marker marker) {
			m_currentMarker = marker;
		}

		//frees all memory in stack
		void StackAllocator::clear() {
			m_currentMarker = (Marker)m_pBuffer;
		}
	}
}