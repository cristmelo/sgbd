#include "../lib/main.h"



int main(){

	string path;
	int op;
	cout << "entre com o nome do banco:\n";
	cin >> path;


	Database *db = new Database(path);
	cout << "Criar novo índice?\n0)Não\t1)Sim\n";
	cin >> op;
	if(op)
		db->create();
	op = 1;
	int key;
	while(op != 0){
		cout << "----------------------------------------------------------------------------------------------\nestado:\n";
		db->status();
		cout << "Escolha a ação:\n0)Sair\n1)Inserir\n2)Busca\n3)Remover\n";
		cin >> op;
		switch(op){
			case 1:
				cout << "Entre com a chave que deseja inserir\n";
				cin >> key;
				db->insert(key);
			break;
			case 2:
				cout << "Entre com a chave que deseja buscar\n";
				cin >> key;
				cout << db->search(key) << endl;
			break;
			case 3:
				cout << "Entre com a chave que deseja remover\n";
				cin >> key;
				db->remove(key);
			break;
		}
	}

	db->close();

	return 0;

}
string stringNBytes(int num, int bytes){
	string numS = to_string(num);
	int addDigit = bytes - numS.length();
	string r = "";
	for(int i = 0 ; i < addDigit ; i++)
		r+="0";
	r+=numS;
	return r;
}



void testes(){
	// set<int> *generatedRids = new set<int> ();
	// cout << "foi\n";
	// db->insert(1);
	// cout << db->search(1) << endl;
	// db->remove(0);
	// cout << db->search(0) << endl;
	// fstream *file = new fstream("db2.db", ios::in | ios::out );
	// if(*file){
		// file->seekg (0, file->beg);
		// cout << "Banco de dados aberto com sucesso\n";
		// Bucket *bucket = new Bucket("db2.db",0,2);
		// bucket->removeDataEntry(3);
		// cout << "bucket\nslots: " << bucket->numberOfTheDataEntry <<"\nVazios: "<< bucket->numberOfTheDataEntryEmpty <<"\nposition: " << bucket->position << "\nnivel: " << bucket->localDepth << endl;
		// for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
		// 	cout << bucket->isUse[i] << endl;
		// cout << "Entradas de dados:\n";
		// for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
		// 	cout << "entrada: " << i<< " Valor:" << bucket->dataEntry[i]->getEntry() << endl;
		// cout << "Busca com chave 2 :" << bucket->findDataEntry(3)->getRid() << endl;
		// bucket->write();


		// Bucket *novo = new Bucket("db2.db",2);
		// novo->insertDataEntry(2,generatedRids);
		// novo->insertDataEntry(3,generatedRids);
		// novo->insertDataEntry(4,generatedRids);
		// novo->insertDataEntry(2,generatedRids);
		// cout << "novo\nslots: " << novo->numberOfTheDataEntry <<"\nVazios: "<< novo->numberOfTheDataEntryEmpty <<"\nposition: " << novo->position << "\nnivel: " << novo->localDepth << endl;
		// for(int i = 0 ; i < novo->numberOfTheDataEntry ; i++)
		// 	cout << novo->isUse[i] << endl;
		// novo->write();

		// Bucket *bucket2 = new Bucket("db.db",256,2);
		// cout << "bucket2\nslots: " << bucket2->numberOfTheDataEntry <<"\nVazios: "<< bucket2->numberOfTheDataEntryEmpty <<"\nposition: " << bucket2->position << "\nnivel: " << bucket2->localDepth << endl;
		// for(int i = 0 ; i < bucket2->numberOfTheDataEntry ; i++)
		// 	cout << bucket2->isUse[i] << endl;
		// cout << "Entradas de dados:\n";
		// for(int i = 0 ; i < bucket2->numberOfTheDataEntry ; i++)
		// 	cout << "entrada: " << i << " Valor:" << bucket2->teste[i] << endl;

		// Directory *dic = Directory::readDirectory(0,"db.dic"); // ler
		// Directory *dic = new Directory(2,"db.dic"); // cria

		// cout << "Diretório " << dic->position << "\nProfundidade: " << dic->globalDepth << "\nNúmero de buckets: " << dic->numberOfBuckets << "\nNúmero de Bytes: " << dic->bytes << endl;
		// for(int i = 0; i < dic->numberOfBuckets; i++ )
		// 	cout << "Bucket :" << dic->positionBucket[i] << "\tProfundidade: " << dic->localDepthBucket[i] << endl;
		// dic->duplicate(1024,0);
		// cout << "Diretório duplicado " << dic->position << "\nProfundidade: " << dic->globalDepth << "\nNúmero de buckets: " << dic->numberOfBuckets << "\nNúmero de Bytes: " << dic->bytes << endl;
		// for(int i = 0; i < dic->numberOfBuckets; i++ )
		// 	cout << "Bucket :" << dic->positionBucket[i] << "\tProfundidade: " << dic->localDepthBucket[i] << endl;
		// dic->duplicate(1280,1);
		// cout << "Diretório duplicado 2 " << dic->position << "\nProfundidade: " << dic->globalDepth << "\nNúmero de buckets: " << dic->numberOfBuckets << "\nNúmero de Bytes: " << dic->bytes << endl;
		// for(int i = 0; i < dic->numberOfBuckets; i++ )
		// 	cout << "Bucket :" << dic->positionBucket[i] << "\tProfundidade: " << dic->localDepthBucket[i] << endl;
		// dic->write();
		// cout << dic->findBucket(0)[0] << "     " << dic->findBucket(0)[1]<< "     " << dic->findBucket(0)[2] << endl;
		// cout << dic->findBucket(1)[0] << "     " << dic->findBucket(1)[1]<< "     " << dic->findBucket(1)[2] << endl;
		// cout << dic->findBucket(2)[0] << "     " << dic->findBucket(2)[1]<< "     " << dic->findBucket(2)[2] << endl;
		// cout << dic->findBucket(3)[0] << "     " << dic->findBucket(3)[1]<< "     " << dic->findBucket(3)[2] << endl;
		// cout << dic->findBucket(4)[0] << "     " << dic->findBucket(4)[1]<< "     " << dic->findBucket(4)[2] << endl;
		// cout << dic->findBucket(5)[0] << "     " << dic->findBucket(5)[1]<< "     " << dic->findBucket(5)[2] << endl;
		// cout << dic->findBucket(6)[0] << "     " << dic->findBucket(6)[1]<< "     " << dic->findBucket(6)[2] << endl;
		// cout << dic->findBucket(7)[0] << "     " << dic->findBucket(7)[1]<< "     " << dic->findBucket(7)[2] << endl;
		// cout << dic->findBucket(8)[0] << "     " << dic->findBucket(8)[1]<< "     " << dic->findBucket(8)[2] << endl;
		// cout << dic->findBucket(9)[0] << "     " << dic->findBucket(9)[1]<< "     " << dic->findBucket(9)[2] << endl;
	// 	file->close();
	// }else{
	// 	cout << "Erro Banco de dados não encontrado" << endl;
	// }

	//DataEntry *data = new DataEntry(23);
	// DataEntry *data = new DataEntry(1, generatedRids);
	
	// cout << generatedRids->count(1000) << endl;

	//cout << data->getKey()<<endl<<data->getRid()<<endl<<data->getEntry() << endl;
}