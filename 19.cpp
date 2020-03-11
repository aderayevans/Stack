#include <iostream>
#include <vector>
#include <fstream>
#include "NodeStack.h"

using namespace std;

bool readFile(Stack &S) {
    ifstream infile ("19.txt");
    string line;
    if (infile) {
        while (getline(infile, line)) {
            //cout << line << endl;
            PUSH(S, line);
            cout << S->Element << endl;
        }
        infile.close();
        return true;
    }
    else {
        cout << "Unable to read file.";
        return false;
    }
}
int main() {
    Stack S;
    MAKENULL_STACK(S);
    readFile(S);
}