#include "DataType.h"
#include <iostream>

upc::upc(){
	key = "null";
	value = "null";
}
upc::upc(string k, string v){
	this->key = k;
	this->value = v;
}

string upc:: rAll(){
	return key + "," + value;
}

string upc::rValue(){
	return value;
}

string upc::rKey(){
	return key;
}

bool upc::operator<(const upc &t){
	return key<t.key;
}

bool upc::operator>(const upc &t){
	return key>t.key;
}

bool upc::operator==(const upc &t){
	return key==t.key;
}

ostream& operator <<(ostream& os, const upc& t){
	cout<<t.value;
	return os;
}
