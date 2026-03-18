#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Front and Rear pointers
Node* front = NULL;
Node* rear = NULL;

// Enqueue (Insert element)
void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {   // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued\n";
}

// Dequeue (Remove element)
void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << front->data << " dequeued\n";
    front = front->next;

    if (front == NULL)   // Queue becomes empty
        rear = NULL;

    delete temp;
}

// Display Queue
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}

