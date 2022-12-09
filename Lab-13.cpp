#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;
public:
    Linkedlist(int* a, int size) {
        for (int i = 0; i < size; i++) {
            insertNode(a[i]);
        }
    }
    Linkedlist(Linkedlist& other) {
        Node* temp = other.head;
        if (other.head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        while (temp != NULL) {
            insertNode(temp->data);
            temp = temp->next;
        }
    }
    ~Linkedlist() {
        while (head != NULL) {
            deleteNode(1);
        }
    }
    void ClearLinkedList() {
        while (head != NULL) {
            deleteNode(1);
        }
    }
    Linkedlist() { head = NULL; }
    void insertNode(int);
    void printList();
    void deleteNode(int);
};
void Linkedlist::deleteNode(int nodeOffset)
{
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }
    temp1 = head;
    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }
    while (nodeOffset-- > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}
void Linkedlist::insertNode(int data)
{
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        // Update temp
        temp = temp->next;
    }
    temp->next = newNode;
}
void Linkedlist::printList()
{
    Node* temp = head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Linkedlist list1;
    list1.insertNode(1);
    list1.insertNode(2);
    list1.insertNode(3);
    Linkedlist list2 = list1;
    list2.printList();
    cout << endl;
    list1.printList();
    return 0;
}