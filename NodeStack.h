#include <iostream>

typedef int ElementType;
struct Node {
    ElementType Element;
    Node* Prev;
};
typedef Node* Position;
typedef Position Stack;
//declarations
void MAKENULL_STACK(Stack &S);
bool TOP(Stack S, ElementType &X);
bool POP(Stack &S);
bool PUSH(Stack &S, ElementType X);
bool EMPTY_STACK(Stack &S);
//definitions
void MAKENULL_STACK(Stack &S) {
    S = new Node();
    S->Element = 0;
    S->Prev = NULL;
}
bool TOP(Stack S, ElementType &X) {
    if (S->Prev == NULL) return false;
    else {
        X = S->Element;
        return true;
    }
}
bool POP(Stack &S) {
    if (S->Prev == NULL) return false;
    else {
        Node* temp = new Node();
        temp = S;
        S = S->Prev;
        delete temp;
        return true;
    }
}
bool PUSH(Stack &S, ElementType X) {
    Node* newone = new Node();
    newone->Element = X;
    newone->Prev = S;
    S = newone;
    return true;
}
bool EMPTY_STACK(Stack &S) {
    return S->Prev == NULL;
}