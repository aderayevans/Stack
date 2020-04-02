#include <iostream>
#include <vector>
#include <fstream>
#include "DynamicBuffer.h"

using namespace std;

bool readFile(Queue &Q) {
    ifstream infile ("19.txt");
    string line;
    if (infile) {
        while (getline(infile, line)) {
            //cout << line << endl;
            enQueue(line, Q);
        }
        infile.close();
        return true;
    }
    else {
        cout << "Unable to read file.";
        return false;
    }
}
void printFile(Queue Q) {
    while(!empty_Queue(Q)) {
        cout << getFront(Q) << endl;
        deQueue(Q);
    }
}
int main() {
    Queue Q;
    makeNull_Queue(Q);
    readFile(Q);
    printFile(Q);
}