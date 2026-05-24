#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

class Queue { private:
Node* front;
Node* rear;

public:
Queue() {
front = rear = NULL;
}

bool isEmpty() {
return front == NULL;
}

void enqueue(int val) {
Node* newNode = new Node(); newNode->data = val; newNode->next = NULL;

if (rear == NULL) {
front = rear = newNode; return;
}

rear->next = newNode; rear = newNode;
}
int dequeue() {
 
if (isEmpty()) {
cout << "Queue Underflow!" << endl; return -1;
}

Node* temp = front; int val = temp->data; front = front->next;

if (front == NULL) rear = NULL;

delete temp; return val;
}

int getFront() {
if (isEmpty()) {
cout << "Queue is Empty!" << endl; return -1;
}
return front->data;
}

void display() {
Node* temp = front;

while (temp != NULL) {
cout << temp->data << " "; temp = temp->next;
}
cout << endl;
}
};

int main() {
Queue q;

q.enqueue(10); q.enqueue(20); q.enqueue(30);

q.display();

q.dequeue();

q.display();

cout << "Front Element: " << q.getFront() << endl;

return 0;
}
