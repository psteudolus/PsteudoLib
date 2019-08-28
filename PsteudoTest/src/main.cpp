#include <iostream>
#include "Psteudo.h"

psteudo::memory::StackAllocator gStackAllocator(256);

void* operator new(size_t size) {
	void* test = gStackAllocator.alloc(size);
	return test;
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

int main()
{
	int* a = new int;
	std::uint32_t _a = gStackAllocator.getMarker();
	*a = 4;
	int* b = new int;
	*b = 4;
	int* c = new int;
	*c = 4;
	gStackAllocator.freeToMarker(_a);
	int* d = new int(4);
	d[0] = 4;
	d[1] = 4;
	d[2] = 4;
	d[3] = 4;
	while (true);
}
