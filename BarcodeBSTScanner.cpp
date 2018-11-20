#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main(){
			BinarySearchTree<string> tree;
			ifstream readFile("upc_corpus.txt");
			string temp;
			int a = 0;
			while(getline(readFile,temp)){
				tree.insert(temp);
				a++;
			}
							cout<<a<<endl;

			readFile.close();
			return 0;
}