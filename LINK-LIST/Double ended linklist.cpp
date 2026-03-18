#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class DBL_Linkedlist_queue {
    Node* front;
    Node* rear;

public:
    DBL_Linkedlist_queue() {
        front = rear = NULL;
    }

    // Insert at rear
    void insert_back(int n) {
        Node* newnode = new Node;
        newnode->data = n;
        newnode->next = NULL;

        if (rear == NULL) { // Empty list
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    // Insert at front
    void insert_front(int n) {
        Node* newnode = new Node;
        newnode->data = n;
        newnode->next = NULL;

        if (rear == NULL) { // Empty list
            front = rear = newnode;
        } else {
            newnode->next = front;
            front = newnode;
        }
    }

    // Remove from front
    int remove_front() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        int temp = front->data;
        Node* del = front;

        if (front == rear) { // Only one node
            front = rear = NULL;
        } else {
            front = front->next;
        }

        delete del;
        return temp;
    }

    // Remove from rear
    int remove_rear() {
        if (rear == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        int temp = rear->data;

        if (front == rear) { // Only one node
            delete rear;
            front = rear = NULL;
            return temp;
        }

        Node* current = front;
        while (current->next != rear) {
            current = current->next;
        }

        delete rear;
        rear = current;
        rear->next = NULL;

        return temp;
    }

    // Display list
    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main menu
int main() {
    DBL_Linkedlist_queue q;
    int choice, option, value;

    do {
        cout << "\n1.Input Restricted Deque\n2.Output Restricted Deque\n3.Display\n4.Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
        case 1: // Input restricted
            cout << "1.Insert at Rear\n2.Remove from Front\n3.Remove from Rear\n4.Back\nChoose: ";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter value: "; cin >> value;
                q.insert_back(value);
                break;
            case 2:
                cout << "Removed from front: " << q.remove_front() << endl;
                break;
            case 3:
                cout << "Removed from rear: " << q.remove_rear() << endl;
                break;
            case 4:
                break;
            default:
                cout << "Invalid!\n";
            }
            break;

        case 2: // Output restricted
            cout << "1.Insert at Front\n2.Insert at Rear\n3.Remove from Front\n4.Back\nChoose: ";
            cin >> option;
            switch (option) {
            case 1:
                cout << "Enter value: "; cin >> value;
                q.insert_front(value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                q.insert_back(value);
                break;
            case 3:
                cout << "Removed from front: " << q.remove_front() << endl;
                break;
            case 4:
                break;
            default:
                cout << "Invalid!\n";
            }
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice!\n";
        }

    } while (true);

    return 0;
}

