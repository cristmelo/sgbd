#include "../lib/main.h"

Page::Page(){

}
Page::Page(int lenghtPage,int lengthRecord,fstream *file){
	this->lenghtPage = lenghtPage;
	this->lengthRecord = lengthRecord;
	this->numberRecords = floor( (lenghtPage - 4) / (1 + lengthRecord) );
	this->records = new Record*[numberRecords];
	
	file->seekg(file->end);
	this->position = file->tellg();
	file->seekg(file->beg);
	
	this->file = file;
}
Page* Page::read(int pageId,fstream *file){
	Page *page = new Page();
	page->position = pageId * LENGTH_PAGE;
	page->file = file;
	page->lenghtPage = LENGTH_PAGE;

	char *buffer = new char[LENGTH_PAGE];
	file->seekg(page->position,file->beg);
	file->read(buffer,LENGTH_PAGE);

	string ntype;
	ntype = buffer[0];
	page->type = stoi(ntype);

	string nRecords;
	nRecords = buffer[1];
	nRecords += buffer[2];
	nRecords += buffer[3];

	page->numberRecords = stoi(nRecords);

	page->slotVector = new bool[page->numberRecords];
	page->records = new Record*[page->numberRecords];
	for(int i = 0; i < page->numberRecords ;i++){
		string current;
		current = buffer[4+i];
		if(current == "1")
			page->slotVector[i] = true;
		else
			page->slotVector[i] = false;
	}

	// switch(page->type){
	// 	case TYPE_DIRECTORY:
	// 		page->records = new Directory*[page->numberRecords];
	// 		page->lengthRecord = Directory.getLength();
	// 	break;
	// 	case TYPE_BUCKET:
	// 		page->records = new Bucket*[page->numberRecords];
	// 		page->lengthRecord = Directory.getLength();
	// 	break;
	// 	case TYPE_RECORD:
	// 		// page->records = new Directory*[page->numberRecords];
	// 		// page->lengthRecord = Directory.getLength();
	// 	break;
	// }
	return page;
}

void Page::write(){

}
void Page::setPageId(int pageId){

}

// int Page::getPageId(){

// }

void Page::insertObject(Record object){

}

// Record Page::findObject(int slot){

// }

void Page::removeObject(int slot){

}