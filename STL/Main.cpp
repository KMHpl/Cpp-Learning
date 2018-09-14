#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	//cout << strings[2] << endl;

	strings[2] = "dog";
	//cout << strings[2] << endl;
	//cout << strings.size();
	vector<string>::iterator it = strings.begin();

	//it++;
	//cout << *it << endl;
	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}
	strings.resize(100);
	return 0;
}