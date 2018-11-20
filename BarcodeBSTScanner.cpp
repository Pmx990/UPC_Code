#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "DataType.h"

using namespace std;

int main(){
			BinarySearchTree<upc> tree;
			ifstream readFile("upc_corpus.txt");
			string blank = "n";
			string temp2;
			string key;
			string value;
			int a = 0;
			while(getline(readFile,temp2)){
				istringstream ss(temp2);
				getline(ss,key,',');
				getline(ss,value,',');
				upc temp = {key,value};

				tree.insert(temp);
			}
			readFile.close();
			return 0;
}



