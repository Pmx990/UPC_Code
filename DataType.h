#include <iostream>

using namespace std;

#ifndef DATATYPE_H
#define DATATYPE_H
class upc{
private:
	string key;
	string value;

public:
	upc();
	upc(string k, string v);
	string rAll();
	string rValue();
	string rKey();
	bool operator<(const upc& t);
	bool operator>(const upc& t);
	bool operator==(const upc& t); 
	friend ostream& operator <<(ostream& os, const upc& t);
};
#endif
