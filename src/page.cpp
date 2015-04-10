#include "../lib/main.h"

Page::Page(int lenghtPage,int lengthRecord,ifstream *file){
	this->lenghtPage = lenghtPage;
	this->lengthRecord = lengthRecord;
	this->numberRecords = floor( (lenghtPage - 2 * sizeof(int)) / (1 + lengthRecord) );
	this->records = new Record*[numberRecords];
	
	file->seekg(file->end);
	this->position = file->tellg();
	file->seekg(file->beg);
	
	this->file = file;
}