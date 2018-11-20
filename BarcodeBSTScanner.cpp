#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "BinarySearchTree.h"
#include "DataType.cpp"
#include <time.h>

using namespace std;

int main(){
			cout<<"Loading the data..."<<endl;
			BinarySearchTree<upc> tree = BinarySearchTree<upc>();
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
				upc temp(key,value);
				tree.insert(temp);
			}
			while(true){
			string tes;
			cout<<endl<<"Please Enter a upc number"<<endl;
			cout<<"Type E to exit the program"<<endl;
			cin>>tes;
			if (tes=="E")
				break;
			string nn = "n";
			upc tt2(tes,nn);

			clock_t t;
			t = clock();
			cout<<tree.search(tt2)<<endl;
			t = clock() - t;
			cout << "BST time: " << t << " miliseconds" << endl;
			readFile.close();
		}
			return 0;
}





/*#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main(){
			BinarySearchTree<string> tree;
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

				tree.insert2(key,value);

			}

			cout<<tree.height()<<endl;
			readFile.close();
			return 0;
}
*/


