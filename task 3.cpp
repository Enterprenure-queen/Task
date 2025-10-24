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

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteFB() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;      
        head = head->next;   
        delete temp;            
        cout << "First node deleted successfully"<<endl;
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
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Before deletion: ";
    list.display();

    list.deleteFB();

    cout << "After deletion:  ";
    list.display();

    return 0;
}