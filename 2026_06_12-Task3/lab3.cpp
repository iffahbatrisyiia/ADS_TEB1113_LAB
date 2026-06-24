#include <iostream>
using namespace std;

struct Node{
    string name;
    Node* next = NULL;
};

void insertFront(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;
    newNode->next = NULL;

    //if empty list
    if (head == NULL){
        head = newNode;
        return;
    }

    //traverse from head to last node
    Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    //insert newNode next to last node
    current->next = newNode;
}

void insertAfter(Node* head, string targetNode, string newName){
    Node* current = head;

    //traverse until reach the targetNode
    while (current != NULL && current->name != targetNode){
        current = current->next;
    }

    if (current == NULL) return; //not found target

    Node* newNode = new Node();
    newNode->name = newName;

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(Node*& head, string targetNode){
    //empty list
    if (head == NULL){
        return;
    }

    //if targetNode is head
    if (head->name == targetNode){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;

    while(current->next != NULL && current->next->name != targetNode){ //check current->next, not current to stop right before target
        current = current->next;
    }

    //found target
    if (current->next != NULL){
        Node* temp = current->next; 
        current->next = current->next->next;
        delete temp;
    }
}

void display(Node* head){
    Node* current = head;
    while (current != NULL){
        cout << current->name << endl;
        current = current->next;
    }
}

int main(){
    
    Node* node1 = new Node(); 
    Node* node2 = new Node(); 
    Node* node3 = new Node(); 
    Node* node4 = new Node(); 
    
    node1->name = "Ali";
    node1-> next = node2;
    node2->name = "Batrisyia";
    node2-> next = node3;
    node3->name = "Claire";
    node3-> next = node4;
    node4->name = "Dmitri";

    Node* head = node1;
    cout << "Original list:\n";
    display(head);

    //insert
    insertFront(head, "Zara");
    cout << "\nAfter inserting Zara at the front:\n";
    display(head);

    insertEnd(head, "Kelly");
    cout << "\nAfter inserting Kelly at the end:\n";
    display(head);

    insertAfter(head, "Dmitri", "Eleanor");
    cout << "\nAfter inserting Eleanor after Dmitri:\n";
    display(head);
    
    //delete
    deleteNode(head, "Claire");
    cout << "\nAfter deleting Claire:\n";
    display(head);
    
    return 0;
}