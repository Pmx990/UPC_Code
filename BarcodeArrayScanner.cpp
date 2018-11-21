#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include "DataType.cpp"
#include <time.h>

using namespace std;

int main() {
	cout << "Loading the data..." << endl;
	//upc arr[1045914]; wont works
	//↑ I try this for a smaller number, and it works
	//google told me this is because the complier limit the max length
	upc* arr = new upc[1045914];
	//since the file is provided, i just skip the process of finding the length of the file
	//***********************
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
	//***********************
	int c = 0;
	string temp2;
	string key;
	string value;
	ifstream readFile("upc_corpus.txt");
	while (getline(readFile, temp2)) {
		istringstream ss(temp2);
		getline(ss, key, ',');
		getline(ss, value, '\n');
		upc temp(key, value);
		arr[c] = temp;
		c++;
	}
	c = 0;
		int ti;
		int ti3;
			string output;
	clock_t start,end;
	double tOutput;

	//**************check the ChooseRamNum.cpp***********
	//array will take 4*1000 for 1 time, and 10 times in total
		for(ti=0;ti<10;ti++){
		start = clock();
		for(ti3=0;ti3<4;ti3++){
			for(count1=0;count1<1000;count1++){
				c=0;
				key = ramNum[count1];
				upc tt2(key,value);
				while (true) {
					if (arr[c].rKey() == key) {
					output = arr[c].rValue();
					break;
				}
				c++;
				}
				//cout << output << endl;
				
}
	}
		end = clock();
		tOutput = (double)end - start;
		//cout<<tOutput<<endl;
		cout << "Use Time:"<<(tOutput/CLOCKS_PER_SEC) << endl;

}//***********************************************************

	
	/*
	//***************************
	string test = "74333470625";
	string test2 = "1";
	upc temp3(test, test2);
	//******test value***********
	clock_t t;
	t = clock();  //timer for the search
	while (true) {
		if (arr[c] == temp3) {
			cout << arr[c] << endl;
			break;
		}
		c++;
		if (c == 1045914) {
			cout << "not found" << endl;
			break;
		}
	}
	t = clock() - t;
	cout << "array time: " << t << " miliseconds" << endl;
	*/


	readFile.close();
	return 0;

}