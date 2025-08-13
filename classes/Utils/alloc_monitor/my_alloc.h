#pragma once 
#include <stdio.h>
#include <stdlib.h>

struct _alloc_monitor_t {
	void* ptr;
	size_t size;
	const char* file;
	const char* function;
	int line; 
	struct _alloc_monitor_t* next;
};

static int _alloc_monitor_on = 0;

void* _alloc_monitor_my_alloc_debug(size_t size, const char* file, const char* function, int line);
void _alloc_monitor_my_free_debug(void* ptr);
void* _alloc_monitor_my_realloc_debug_(void* ptr, size_t size);
void _alloc_monitor_showMem();
void set_alloc_monitor(int on);

#define malloc(size) _alloc_monitor_my_alloc_debug(size, __FILE__, __func__, __LINE__)
#define free(ptr) _alloc_monitor_my_free_debug(ptr)
#define realloc(ptr, size) _alloc_monitor_my_realloc_debug_(ptr, size)
#define detect_leaks() _alloc_monitor_showMem()



