#include "../lib/main.h"
Database::Database(string path){
	openDB(path);

}

int Database::search(int key){

}

void Database::insert(int reg){

}

bool Database::remove(int key){

}

bool Database::open(string path){
	this->close();
	openDB(path);

}

bool Database::close(){
	if(*(this->DB)){
		// salvar tudo da memória
		// DB->seekg(1,DB->beg);
		// char *buffer = new char[2];
		// DB->read(buffer,2);
		// cout << buffer <<endl;

		DB->close();
		Dic->close();
		cout << "banco de dados fechado com sucesso\n";
	}
	else
		cout << "Nenhum Banco de dados aberto\n";
}

void Database::openDB(string path){
	string dbName,dicName;
	dbName = path + ".db";
	dicName = path + ".dic";
	fstream *file = new fstream(dbName.c_str(), ios::in | ios::out );
	fstream *dic = new fstream(dicName.c_str(),ios::in | ios::out);
	if(*file && *dic){
		file->seekg (0, file->beg);
		this->DB = file;
		dic->seekg(0,file->beg);
		this->Dic = dic;
		

		// *DB << true;
		// DB->seekp(1,DB->beg);
		// *DB << 23;

		cout << "Banco de dados aberto com sucesso\n";
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}
}