#include <stdio.h>
#include "Utils/alloc_monitor/my_alloc.h"
#include "Utils/Utils.h"
#include "classes/Utils/Vector/Vector.h"


int main(void)
{
	set_alloc_monitor(1);
	Vector vec;
	vector_init(&vec, 4);

	for (int i = 0; i < 9; i++)
	{
		vector_push(&vec, i * i);
		printf("%d", (int)vec.data[i]);
		int x = 2137;
	}

	printf("\n");

	for (int i = 0; i < 9; i++)
	{
		int c = vector_pop(&vec);
		printf("%d", c);
		int x = 2137;
	}

	vector_delete(&vec);

	detect_leaks();

	return 0;
}