#pragma once
#include <cstdint>
#include <cstdlib>
#include <cassert>

namespace psteudo {
	namespace memory {
		class StackAllocator {
		public:
			//represents the pointer to the top of the currently allocated stack
			typedef std::uint32_t Marker;

			//don't want to type std::uint32_t all the time
			typedef std::uint32_t U32;

			//constructs a stack allocator of specified size
			explicit StackAllocator(U32 stackSize_bytes);

			//allocates the the specified amount of memory from the top of the stack
			void* alloc(U32 size_bytes);

			//returns the current position in the stack
			Marker getMarker();

			//frees memory back to the selected marker
			void freeToMarker(Marker marker);

			//frees all memory in stack
			void clear();

		private:
			char* m_pBuffer;
			U32 m_bufferSize;
			U32 m_currentSize;
			Marker m_currentMarker;
		};
	}
}