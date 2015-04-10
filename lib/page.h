/**
file: page.h
class: Page
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Page{

	fstream *file;	
	int position;
	int lenghtPage;
	Record **records;
	bool *slotVector;
	int numberRecords;
	int lengthRecord;
	int type;


public:
	Page();
	Page(int lenghtPage,int lengthRecord,fstream *file);

	static Page* read(int pageId,fstream *file);

	void write();
	void setPageId(int pageId);

	int getPageId();

	void insertObject(Record object);

	Record findObject(int slot);

	void removeObject(int slot);

};