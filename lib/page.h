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
	int numberRecords;
	int lenghtRecord;



public:
	Page(int lenghtPage,int lenghtRecord,ifstream *file);

	static Page* read(int pageId,ifstream *file);

	void write();
	void setPageId(int pageId);

	int getPageId();



}