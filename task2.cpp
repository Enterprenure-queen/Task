#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPos(int position, int value) {
        Node* newNode = new Node{value, nullptr};

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtPos(1, 10);
    list.insertAtPos(2, 20);
    list.insertAtPos(3, 30);
    list.insertAtPos(4, 40);
    list.insertAtPos(5, 50);  
    list.display();  
    return 0;
}