#include "my_alloc.h"

static struct _alloc_monitor_t* g_AllocMonitor = NULL;

void _alloc_monitor_addMem(size_t size, const char* file, const char* function, int line, void* ptr);
void _alloc_monitor_delMem(void* ptr);

#undef malloc
#undef free
#undef realloc

static g_allocMonitorOn = 0;

void _alloc_monitor_addMem(size_t size, const char* file, const char* function, int line, void* ptr)
{
	struct _alloc_monitor_t* curr = (struct _alloc_monitor_t*)malloc(sizeof(struct _alloc_monitor_t));
	if (curr == NULL)
	{
		printf("\nMEM ALLOCATION ERROR\n");
		exit(1);
	}

	curr->size = size;
	curr->file = file;
	curr->function = function;
	curr->line = line;
	curr->ptr = ptr;
	curr->next = g_AllocMonitor;
	g_AllocMonitor = curr;
}

void _alloc_monitor_delMem(void* ptr)
{
	struct _alloc_monitor_t** curr = &g_AllocMonitor;
	while (*curr) {
		if ((*curr)->ptr == ptr) {
			struct _alloc_monitor_t* toFree = *curr;
			*curr = (*curr)->next;
			free(toFree);
			return;
		}
		curr = &(*curr)->next;
	}
}

void _alloc_monitor_showMem()
{
	struct _alloc_monitor_t* curr = g_AllocMonitor;

	while (curr != NULL)
	{
		if(curr->ptr)printf("Memory allocated in %s::%s:%d (%llu bytes)\n", curr->file, curr->function, curr->line, curr->size);
		curr = curr->next;
	}
}

void set_alloc_monitor(int on)
{
	g_allocMonitorOn = on;
}

void* _alloc_monitor_my_alloc_debug(size_t size, const char* file, const char* function, int line)
{
	void* mem = malloc(size);
	if (g_allocMonitorOn)
	{
		if (mem == NULL)
		{
			printf("MEMORY ALLOCATION ERROR");
			exit(1);
		}
		_alloc_monitor_addMem(size, file, function, line, mem);
	}
	return mem;
}

void _alloc_monitor_my_free_debug(void* ptr)
{
	if (g_allocMonitorOn)
	{
		if (ptr == NULL)return;
	}
	_alloc_monitor_delMem(ptr);
	free(ptr);
}

void* _alloc_monitor_my_realloc_debug_(void* ptr, size_t size)
{
	struct _alloc_monitor_t** curr = &g_AllocMonitor;
	while (*curr) {
		if ((*curr)->ptr == ptr) { 
			(*curr)->size = size;
			void* new_ptr = realloc(ptr, size);
			(*curr)->ptr = new_ptr;
			return new_ptr;
		}
		curr = &(*curr)->next;
	}

	return NULL;
}

