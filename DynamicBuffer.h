#include <iostream>
using namespace std;
typedef string ElementType;
struct Node {
    ElementType Element;
    Node* Next;
};
typedef Node* Position;
struct Queue {
    Position Front;
    Position Rear;
};
void makeNull_Queue(Queue &Q);
ElementType getFront(Queue Q);
void enQueue(ElementType X, Queue &Q);
bool deQueue(Queue &Q);
bool empty_Queue(Queue Q);
bool full_Queue(Queue Q);

void makeNull_Queue(Queue &Q) {
    Position Header = new Node();
    Header->Next = NULL;
    Q.Front = Header;
    Q.Rear = Header;
}
ElementType getFront(Queue Q) {
    return Q.Front->Next->Element;
}
void enQueue(ElementType X, Queue &Q) {
    Q.Rear->Next = new Node();
    Q.Rear = Q.Rear->Next;
    Q.Rear->Element = X;
    Q.Rear->Next = NULL;
}
bool deQueue(Queue &Q) {
    if (empty_Queue(Q)) return false;
    Position temp = Q.Front;
    Q.Front = Q.Front->Next;
    delete temp;
    return true;
}
bool empty_Queue(Queue Q) {
    return Q.Front==Q.Rear;
}
bool full_Queue(Queue Q) {
    return false;
}