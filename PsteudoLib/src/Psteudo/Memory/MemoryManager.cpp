#include "MemoryManager.h"

void* operator new(size_t size) {
	return malloc(size);
}

void operator delete (void* mem) {
	free(mem);
}

void* operator new[](size_t size) {
	return malloc(size);
}

void operator delete[](void* mem) {
	free(mem);
}

namespace psteudo {

}