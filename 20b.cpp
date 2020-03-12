#include <iostream>
#include "NodeStack.h"

using namespace std;

int Fibo(int n) {
    ElementType temp;
    int result = 0;
    Stack S;
    MAKENULL_STACK(S);
    PUSH(S, n);
    while (!EMPTY_STACK(S)) {
        TOP(S, temp);
        POP(S);
        if (temp == 0 || temp == 1) result++;
        else {
            PUSH(S, temp-2);
            PUSH(S, temp-1);
        }
    }
    return result;
}
int main() {
    cout << Fibo(6);
}