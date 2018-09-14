#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void CreateFile() {
	//1 ->ofstream File;

	fstream File;//2

	string Name = "Test.txt";
	//1 -> File.open(Name);
	File.open(Name, ios::out);//2
	if (File.is_open()) {
		//File << "xddd" << endl;
		File << "wowwwrks fine !!" << endl;

		File.close();
	}
	else {
		cout << " could not open :" << Name << endl;
	}
}
void OpenFile() {
	string Name = "Test.txt";
	ifstream inFile;
	inFile.open(Name);//ios::in);
	if (inFile.is_open()) {
		string line;
		while (inFile) { // or (!inFile.eof())
			getline(inFile, line);
			//inFile >> line;
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cout << "Cannot open file :" << Name<< endl;
	}
}
int AdvancedRead() 
{
	string filename = "Test.txt";
	ifstream input;
	input.open(filename);
	if (!input.is_open()) {
		return 1;
	}
	while (input)
	{
		string line;
		getline(input, line, ':');
		int population;
		input >> population;

		//input.get();
		input >> ws; //white space

		cout << "'" << line << "'" << " -- " << "'" << population << "'" << endl;
	}
}
#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)

int main() {

	Person someone = {"Frodo",220,0.89};
	string filename = "Test.bin";
	//////////////////////////////
	//write file//////////////////
	//////////////////////////////
	ofstream File;
	File.open(filename, ios::binary);
	
	if (File.is_open()) {

		//1)File.write((char *)&someone,sizeof(Person)); // in write we add pointer thats why we use '&' to get struck adress
		//2)
		File.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		File.close();
	}
	else {
		cout << "Could not create file " + filename << endl;
		//cout << "Could not create file " << filename << endl; -same

	}
	//////////////////////////////
	//Read file//////////////////
	//////////////////////////////
	Person someoneElse = {};
	ifstream inputFile;
	inputFile.open(filename, ios::binary);

	if (inputFile.is_open()) {

		//1)File.write((char *)&someone,sizeof(Person)); // in write we add pointer thats why we use '&' to get struck adress
		//2)
		inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
		inputFile.close();
	}
	else {
		cout << "Could not read file " + filename << endl;
		//cout << "Could not create file " << filename << endl; -same

	}
	cout << someoneElse.name << "," << someoneElse.age << "," << someoneElse.height << endl;

	//AdvancedRead();
	//CreateFile();
	//OpenFile();
	return 0;
}
