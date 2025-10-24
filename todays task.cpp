#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DLL {
private:
    Node* head;
    Node* tail;

public:
    DLL() : head(nullptr), tail(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~DLL() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            cout << "Deleting Node: " << temp->data << endl;
            delete temp;
        }
        cout << "All nodes deleted successfully!" << endl;
    }
};

int main() {
    DLL list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();
   

    return 0;
}