#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* Next;
};

class CircularList {
    Node* front;
    Node* rear;

public:
    CircularList() {
        front = rear = NULL;
    }

    // Insert at rear
    void insertRear(int n) {
        Node* ptr = new Node;
        ptr->data = n;
        ptr->Next = NULL;

        if (rear == NULL) {
            front = rear = ptr;
            rear->Next = front;
        } else {
            rear->Next = ptr;
            rear = ptr;
            rear->Next = front;
        }
    }

    // Insert at front
    void insertFront(int n) {
        Node* ptr = new Node;
        ptr->data = n;
        ptr->Next = NULL;

        if (rear == NULL) {
            front = rear = ptr;
            rear->Next = front;
        } else {
            ptr->Next = front;
            front = ptr;
            rear->Next = front;
        }
    }

    // Remove from front
    int removeFront() {
        if (front == NULL) {
            cout << "List is empty\n";
            return -1;
        }

        int val;
        if (front == rear) {
            val = front->data;
            delete front;
            front = rear = NULL;
            return val;
        }

        Node* del = front;
        val = del->data;
        front = front->Next;
        rear->Next = front;
        delete del;
        return val;
    }

    // Remove from rear
    int removeRear() {
        if (rear == NULL) {
            cout << "List is empty\n";
            return -1;
        }

        int val;
        if (front == rear) {
            val = rear->data;
            delete rear;
            front = rear = NULL;
            return val;
        }

        Node* temp = front;
        while (temp->Next != rear) {
            temp = temp->Next;
        }

        val = rear->data;
        delete rear;
        rear = temp;
        rear->Next = front;
        return val;
    }

    // Display list
    void display() {
        if (front == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->Next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularList c;
    
   c.insertRear(34);
    c.insertRear(54);
   c.insertRear(64);
    c.insertFront(14);

    c.display();

    c.removeRear();
    c.display();

    c.removeFront();
    c.removeFront();
    c.display();

    return 0;
}

