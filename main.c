#include <stdio.h>
#include "Utils/alloc_monitor/my_alloc.h"
#include "XMLReader/XMLReader.h"
#include "Utils/Utils.h"
#include "classes/File/File.h"

int main(void)
{
	File file;
	file_open(&file, "src/test.xml");
	file_delete(&file);
	return 0;
}