#include <iostream>
using namespace std;

class StackArray { private:
int arr[10]; int top;

public:
StackArray() { top = -1;
}

bool isEmpty() { return top == -1;
}

bool isFull() { return top == 9;
}

void push(int val) { if (isFull()) {
 
cout << "Stack Overflow!" << endl; return;
}
arr[++top] = val;
}

int pop() {
if (isEmpty()) {
cout << "Stack Underflow!" << endl; return -1;
}
return arr[top--];
}

int peek() {
if (isEmpty()) {
cout << "Stack is Empty!" << endl; return -1;
}
return arr[top];
}

void display() {
for (int i = top; i >= 0; i--) { cout << arr[i] << " ";
}
cout << endl;
}
};

struct Node {
int data;
Node* next;
};

class StackLinkedList { private:
Node* top;

public:
StackLinkedList() { top = NULL;
}

bool isEmpty() {
return top == NULL;
}

void push(int val) {
Node* newNode = new Node(); newNode->data = val; newNode->next = top;
top = newNode;
}

int pop() {
if (isEmpty()) {
cout << "Stack Underflow!" << endl; return -1;
}

int val = top->data; Node* temp = top; top = top->next; delete temp;
return val;
}

int peek() {
if (isEmpty()) {
cout << "Stack is Empty!" << endl; return -1;
 
}
return top->data;
}

void display() { Node* temp = top;
while (temp != NULL) {
cout << temp->data << " "; temp = temp->next;
}
cout << endl;
}
};

int main() {
StackArray s1;
StackLinkedList s2;

for (int i = 1; i <= 5; i++) { s1.push(i * 10);
s2.push(i * 10);
}

cout << "Array Stack: "; s1.display();

cout << "Linked List Stack: "; s2.display();

s1.pop();
s1.pop();

s2.pop();
s2.pop();
cout << "After popping 2 elements:" << endl; s1.display();
s2.display();

cout << "Peek Array Stack: " << s1.peek() << endl; cout << "Peek Linked Stack: " << s2.peek() << endl;

return 0;
}
