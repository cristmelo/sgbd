#include "../lib/main.h"

int main(){

	// Database db("db.db");

	// db.close();
	
	fstream *file = new fstream("db.db", ios::in | ios::out );
	if(*file){
		file->seekg (0, file->beg);
		cout << "Banco de dados aberto com sucesso\n";
		Page *page = Page::read(0,file);
		cout << "Page\ntype: " << page->type << "\nslots: " << page->numberRecords <<"\nposition: " << page->position << endl;
		for(int i = 0 ; i < page->numberRecords ; i++)
			cout << page->slotVector[i] << endl;
		file->close();
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}
	return 0;

}