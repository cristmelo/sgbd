class DataEntry{
	int key;
	Rid *rid;
public:
	DataEntry(int key, Rid *rid);
	int getKey();
	Rid* getRid(); 
}