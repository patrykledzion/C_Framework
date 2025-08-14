#include <stdlib.h>

#include "XMLReader.h" 
#include "return_codes.h"
#include "Utils/Utils.h"
#include "File/File.h"

int xml_reader_init(XMLReader* out, const char* filepath)
{
	file_open(&out->inputfile, filepath);
	TODO(vector_init(out->tags, sizeof(XMLTag), 8 /*start size*/)); out->tags = NULL;
	TODO(xml_reader_tokenizer_init(out->tokenizer)); out->tokenizer = NULL;

	return 0;
}

int xml_reader_delete(XMLReader* it)
{
	TODO("XMLReader destructor");
	return 0;
}

 