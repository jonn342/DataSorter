#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <exception>
using namespace std;

void openandread(set<string> & s) {
	string filename;
	cout << "Enter the path to read from file:";
	cin >> filename;
	try {
		ifstream fin(filename, ios::binary | ios::in);
		if (fin.fail()) throw exception();
		string str;
		for (s; getline(fin, str, '\n');) {
			s.emplace(str);
		}
		fin.close();
	}
	catch (exception const & e) {
		cout << e.what();
	}
}


void openandwrite(set<string> & s) {
	string filename;
	cout << "Enter the path to write to file:";
	cin >> filename;
	try {
		ofstream fout(filename, ios::binary | ios::out | ios::trunc);
		if (fout.fail()) throw exception();
		for (auto el : s) {
			fout << el << '\n';
		}
		fout.close();
	}
	catch (exception const & e) {
		cout << e.what();
	}

}


int main() {
	set<string> s;
	openandread(s);
	openandwrite(s);
	return 0;
}