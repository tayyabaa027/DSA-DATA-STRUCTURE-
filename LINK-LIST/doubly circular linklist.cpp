#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* last;
};

class DoublyCircularList {
    Node* front;
    Node* rear;

public:
    DoublyCircularList() {
        front = rear = NULL;
    }

    // Insert at rear
    void insert(int val) {
        Node* ptr = new Node;
        ptr->data = val;
        ptr->next = ptr->last = NULL;

        if (rear == NULL) { // Empty list
            front = rear = ptr;
            ptr->next = ptr->last = ptr;
        } else {             // Non-empty list
            ptr->next = front;
            ptr->last = rear;
            rear->next = ptr;
            front->last = ptr;
            rear = ptr;
        }
    }

    // Remove from front
    int removeFront() {
        if (front == NULL) { // Empty list
            cout << "List is empty\n";
            return -1;
        }

        int val = front->data;
        Node* curr = front;

        if (front == rear) { // Only one node
            front = rear = NULL;
        } else {             // More than one node
            front = front->next;
            front->last = rear;
            rear->next = front;
        }

        delete curr;
        return val;
    }

    // Display list
    void display() {
        if (front == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Circular Doubly Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

// Well-defined main function
int main() {
    DoublyCircularList list;
    int choice, value;

    do {
        cout << "\n===== Circular Doubly Linked List Menu =====\n";
        cout << "1. Insert at Rear\n";
        cout << "2. Remove from Front\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
            value = list.removeFront();
            if (value != -1)
                cout << "Removed value: " << value << endl;
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Exiting program...\n";
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (true);

    return 0;
}
