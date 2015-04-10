#include "../lib/main.h"
class Page{
	Page(int lenghtPage,int lenghtRecord,ifstream *file){
		this.lenghtPage = lenghtPage;
		this.lenghtRecord = lenghtRecord;
		this.numberRecords = (lenghtPage - sizeof(int)) / (1 + lenghtRecord);
		this.records = new Record*[numberRecords];
		this.position = file.end;
		this.file = file;
	}
}