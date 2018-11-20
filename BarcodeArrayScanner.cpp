#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "DataType.cpp"
#include <time.h>

using namespace std;

int main(){
			cout<<"Loading the data..."<<endl;
			upc arr[1045914];
			int c = 0;
			string temp2;
			string key;
			string value;

			ifstream readFile("upc_corpus.txt");

			while(getline(readFile,temp2)){
				istringstream ss(temp2);
				getline(ss,key,',');
				getline(ss,value,',');
				upc temp(key,value);
				arr[c] = temp;
				c++;
			}
			c=0;
			string test="689076484763";
			string test2 = "1";

			upc temp3(test,test2);
			while(true){
				if(arr[c]==temp3){
					cout<<arr[c]<<endl;
					break;
					}
				c++;
				if(c==sizeof(arr)){
					cout<<"not found"<<endl;
					break;
				}
			}
			cout<<"bbb"<<endl;
			return 0;
		}