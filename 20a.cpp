#include <iostream>
#include "NodeStack.h"

using namespace std;

int TH(ElementType e) {
    ElementType temp, temp2;
    int result = 0;
    Stack S;
    MAKENULL_STACK(S);
    PUSH(S, e);
    while (!EMPTY_STACK(S)) {
        TOP(S, temp);
        POP(S);
        if(temp.k == 0 ||temp.k == temp.n ) result++;
        else {
            temp2.k = temp.k-1;
            temp2.n = temp.n-1;
            PUSH(S, temp2);
            temp2.k = temp.k;
            temp2.n = temp.n-1;
            PUSH(S, temp2);
        }
    }
    return result; 
}
int main() {
    ElementType e;
    e.k = 3;
    e.n = 6;
    cout << TH(e);
}