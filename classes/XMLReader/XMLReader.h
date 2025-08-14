#pragma once
#include "File/File.h" 

struct Tokenizer;
struct XMLTag;

typedef struct xml_reader_t {
	File inputfile;
	struct Tokenizer* tokenizer;
	struct XMLTag* tags;
} XMLReader;

int xml_reader_init(XMLReader* out, const char* filepath); 
int xml_reader_delete(XMLReader* it);

