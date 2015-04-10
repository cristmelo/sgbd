/**
file: page.h
class: Page
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Page{

	ifstream *file;	
	int position;
	int lenghtPage;
	Record **records;
	bool **slotVector;
	int numberRecords;
	int lengthRecord;
	int type;


public:
	Page(int lenghtPage,int lengthRecord,ifstream *file);

	static Page* read(int pageId,ifstream *file);

	void write();
	void setPageId(int pageId);

	int getPageId();

	void insertObject(Record object);

	Record findObject(int slot);

	void removeObject(int slot);

};