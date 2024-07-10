#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int ReadData(const string &fn, int a[]) {
    ifstream f;
    char line[100];
    f.open(fn.c_str(), ios::in);

    int n = 0;
    while (!f.eof()) {
        f.getline(line, 100);
        a[n++] = atoi(line);
    }
    return n;
}

void ShowHead(string &fn, int amount) {
    ifstream file(fn);
    if (!file.is_open()) {
        cerr << "Không th? m? t?p: " << fn << endl;
        return;
    }

    string line;
    for (int i = 0; i < amount; i++) {
        getline(file, line);
        line.erase(line.end()-1, line.end());
        cout << line << endl;
    }

    file.close();
}

void SortElements(string &fn, int amount) {
    ifstream file(fn);
    if (!file.is_open()) {
        cerr << "Không th? m? t?p: " << fn << endl;
        return;
    }

    string line;
    int n=0;
    int a[10000];
    while (!file.eof()) {
        getline(file, line);
        if (line.find("\r") != string::npos){
            line.erase(line.end()-1, line.end());
            a[n++] = stoi(line);   
        }
    }
    
    interchangSort(a, n);
    for (int i=0; i<amount; i++){
        cout << a[i] << endl;
    }
    file.close();
}


int main(int argc, char* argv[]){	
	string fn = "test.txt";
	int a[1000];
	int n = ReadData(fn, a);
	
	cout << n;
	return 0;
}
