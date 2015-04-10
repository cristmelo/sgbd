#include "../lib/main.h"

class Page{
	Page(int lenghtPage,int lengthObject,ifstream *file){
		this.lenghtPage = lenghtPage;
		this.lengthObject = lengthObject;
		this.numberRecords = floor( (lenghtPage - 2 * sizeof(int)) / (1 + lengthObject) );
		this.records = new Record*[numberRecords];
		this.position = file.end;
		this.file = file;
	}
};