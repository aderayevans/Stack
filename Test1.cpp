#include <iostream>
#include "NodeStack.h"

void Print(Stack T) {
    while (!EMPTY_STACK(T)) {
        std::cout << T->Element;
        POP(T);
    }
}
void Dec(int a){
    Stack T;
    MAKENULL_STACK(T);
    while(true) {
        if (a == 0) break;
        if (a%2 == 0) {
            PUSH(T, 0);
        }
        else {
            PUSH(T, 1);
        }
        a = a/2;
    }
    Print(T);
}
int main() {
    int a;
    std::cin >> a;
    Dec(a);
}