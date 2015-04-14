#include "../lib/main.h"

int main(){

	// Database db("db");

	// db.close();
	
	fstream *file = new fstream("db.db", ios::in | ios::out );
	if(*file){
		file->seekg (0, file->beg);
		cout << "Banco de dados aberto com sucesso\n";
		Bucket *bucket = new Bucket(file,0,2);
		cout << "bucket\nslots: " << bucket->numberOfTheDataEntry <<"\nVazios: "<< bucket->numberOfTheDataEntryEmpty <<"\nposition: " << bucket->position << "\nnivel: " << bucket->localDepth << endl;
		for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
			cout << bucket->isUse[i] << endl;
		cout << "Entradas de dados:\n";
		for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
			cout << "entrada: " << i<< " Valor:" << bucket->teste[i] << endl;
		bucket->write();
		file->close();
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}


	return 0;

}