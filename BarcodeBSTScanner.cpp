#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "BinarySearchTree.h"
#include "DataType.cpp"
#include <time.h>

using namespace std;

int main() {
	cout << "Loading the data..." << endl;
	//*********Check the ChooseRamNum.cpp file******************
	string rNum;
	string* ramNum = new string[1000];
	int count1 = 0;
	ifstream readFile2("100ram.txt");
	while (getline(readFile2, rNum)) {
		ramNum[count1] = rNum;
		//cout<<ramNum[count1]<<endl;
		count1++;
	}
	readFile2.close();
	//**********************************************************
	BinarySearchTree<upc> tree = BinarySearchTree<upc>();
	ifstream readFile("upc_corpus.txt");
	string temp2;
	string key;
	string value;
	int a = 0;
	while (getline(readFile, temp2)) {
		istringstream ss(temp2);

		getline(ss, key, ',');
		//read the data and insert them into the tree as type upc
		getline(ss, value, '\n');
		upc temp(key, value);
		tree.insert(temp);
	}


//***************************************
	string output;
	clock_t start,end;
	double tOutput;
	int ti;
	int ti3;
	/*
	the following loop will load 1000 prepared keys
	and each clock will count 1000*4 times searches 
	(for BST,per search take a really short time that can not be recorded
	so I record per time for 4000 times searches)
	I took 10 times in total for the graph.
	 */
	for(ti=0;ti<10;ti++){
		start = clock();
		for(ti3=0;ti3<4;ti3++){
			for(count1=0;count1<1000;count1++){
				key = ramNum[count1];
				upc tt2(key,value);
				output = tree.search(tt2).rValue();
				//cout << output << endl;
}
	}
		end = clock();
		tOutput = (double)end - start;
		//cout<<tOutput<<endl;
		cout << "Use Time:"<<(tOutput/CLOCKS_PER_SEC) << endl;

}

	//*****************This is the input function****************//
	/*
	while (true) { //program begin unitl exit
		string tes;
		cout << endl << "Please Enter a upc number" << endl;
		cout << "Type E to exit the program" << endl;
		cin >> tes;
		if (tes == "E" ) {
			break;
		}
		string nn = "n";
		upc tt2(tes, nn);
		clock_t t;
		t = clock();  //timer for the search
		cout << tree.search(tt2) << endl;
		t = clock() - t;
		cout << "BST time: " << t << " miliseconds" << endl;
	}
	*/
	readFile.close();

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


