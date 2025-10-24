#include <iostream>
#include <iomanip>   
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void DisplayNode(Node* node) {
    if (node == nullptr) {
        cout << "Node is empty (NULL)." << endl;
        return;
    }

    cout << "------------------------------------------------------" << endl;
    cout << setw(20) << left << "Prev Address"
         << " | " << setw(7) << left << "Data"
         << " | " << setw(17) << left << "Next Address"
         << " | " << "Node Address" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "  "
         << setw(20) << left << node->prev
         << " | " << setw(7) << left << node->data
         << " | " << setw(17) << left << node->next
         << " | " << node << endl;

    cout << "------------------------------------------------------" << endl;
}
int main() {
   
    Node node1, node2, node3;

    node1.data = 25;
    node2.data = 50;
    node3.data = 75;

    node1.prev = nullptr;
    node1.next = &node2;

    node2.prev = &node1;
    node2.next = &node3;

    node3.prev = &node2;
    node3.next = nullptr;

    cout << "Displaying a single node:\n";
    DisplayNode(&node2);  

    return 0;
}