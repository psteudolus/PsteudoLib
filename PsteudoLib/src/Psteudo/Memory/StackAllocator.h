#pragma once
#include <cstdint>

namespace psteudo {
	namespace memory {
		class StackAllocator {
		public:
			//represents the pointer to the top of the currently allocated stack
			typedef std::uint32_t Marker;

			//don't want to type std::uint32_t all the time
			typedef std::uint32_t U32;

			explicit StackAllocator(U32 stackSize_bytes);

			void* alloc(U32 size_bytes);

			Marker getMarker();

			void freeToMarker(Marker marker);

			void clear();

		private:
			char* m_pBuffer;
			U32 m_bufferSize;
			U32 m_currentOffset;
			Marker marker;
		};
	}
}