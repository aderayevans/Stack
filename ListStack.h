#include <iostream>

#define Maxlength 127
typedef int ElementType;
struct Stack {
    ElementType Elements[Maxlength];
    int top_idx;
};
//declarations
void MAKENULL_STACK(Stack &S);
bool TOP(Stack S, ElementType &X);
bool POP(Stack &S);
bool PUSH(Stack &S, ElementType X);
bool EMPTY_STACK(Stack &S);
//definitions
void MAKENULL_STACK(Stack &S) {
    S.top_idx = Maxlength;
}
bool TOP(Stack S, ElementType &X) {
    if (S.top_idx == Maxlength) return false;
    else {
        X = S.Elements[S.top_idx];
        return true;
    }
}
bool POP(Stack &S) {
    if (S.top_idx == Maxlength) return false;
    else {
        S.top_idx = S.top_idx + 1;
        return true;
    }
}
bool PUSH(Stack &S, ElementType X) {
    if (S.top_idx == 0) return false;
    else {
        S.top_idx = S.top_idx - 1;
        S.Elements[S.top_idx] = X;
        return true;
    }
}
bool EMPTY_STACK(Stack &S) {
    return S.top_idx == Maxlength;
}