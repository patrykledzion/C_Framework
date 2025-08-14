#include <stdio.h>
#include "Utils/alloc_monitor/my_alloc.h"
#include "Utils/Utils.h"
#include "classes/Utils/Vector/Vector.h"
#include "classes/XMLReader/XMLReader.h"


int main(void)
{
	set_alloc_monitor(1);
	
	XMLReader reader;

	xml_reader_init(&reader, "src/test.xml");
	xml_reader_delete(&reader);

	detect_leaks();

	return 0;
}