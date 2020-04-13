#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "DynamicBuffer.h"

using std::cout;
using std::endl;
using std::string;

bool readFile(Queue &Q, int line_num)
{
    ifstream infile ("19.txt");
    string line;
    int index = 0;
    if (infile)
    {
        while (getline(infile, line)) {
            if (index == line_num) 
            {
                enQueue(line, Q);
                infile.close();
                return true;
            }
            else index++;
        }
        //cout << "File is empty." << endl;
        return false;
    }
    else
    {
        //cout << "File is empty." << endl;
        return false;
    }
}
bool printFile(Queue &Q)
{
    if(!empty_Queue(Q))
    {
        cout << Front(Q) << endl;
        deQueue(Q);
        return true;
    }
    else
    {
        //cout << "Queue is empty." << endl;
        return false;
    }
}
int main()
{
    Queue Q;
    makeNull_Queue(Q);
    int line_num = 0;
    bool _file = true;
    bool _queue = true;
    while(true)
    {
        if (_file == _queue && _file == false) break;
        int n = rand()%2;
        switch(n) 
        {
            case 0:
                _file = readFile(Q, line_num++);
                break;
            case 1:
                _queue = printFile(Q);
                break;
            default:
                break;
        }
    }
}