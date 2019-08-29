#include <iostream>
#include "Psteudo.h"

psteudo::mem::StackAllocator gStackAllocator(256);

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
	char* a = new char;
	psteudo::Marker _a = gStackAllocator.getMarker();
	*a = 1;
	char* b = new char;
	*b = 2;
	char* c = new char;
	*c = 3;
	gStackAllocator.freeToMarker((psteudo::Marker)b);
	char* d = new char(4);
	d[0] = 4;
	d[1] = 4;
	d[2] = 4;
	d[3] = 4;
	while (true);
}
