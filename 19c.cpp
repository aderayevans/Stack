#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include "pqueuelib.h"

int readFile(Queue *Q, int line_num) 
{
    FILE *f = fopen("19.txt", "r");
    char* line = (char*)malloc(255*(sizeof(char)));
    char* tmp = (char*)malloc(255*(sizeof(char)));
    if (f) 
    {
        while (line_num > 0) {
            fgets(tmp, 255, f);
            line_num--;
        }
        fgets(line, 255, f);
        EnQueue(line, Q);
        return 0;
    }
    else 
    {
        printf("File is empty.\n");
        fclose(f);
        return 1;
    }
}
int printFile(Queue *Q) 
{
    if (!Empty_Queue(*Q)) 
    {
        printf("%s", Front(*Q));
        DeQueue(Q);
        return 0;
    }
    else 
    {
        printf("Queue is empty.\n");
        return 1;
    }
}
int main()
{
    Queue Q;
    MakeNull_Queue(&Q);
    int line_num = 0;
    int _file = 0, _queue = 0;
    while(true)
    {
        if (_file == _queue && _file == 1) break;
        int n = rand()%2;
        switch(n) 
        {
            case 0:
                _file = readFile(&Q, line_num++);
                break;
            case 1:
                _queue = printFile(&Q);
                break;
            default:
                break;
        }
    }
}