#include <iostream>
using namespace std;

struct Node{
    string name;
    Node* prev = NULL;
    Node* next = NULL;
};

void insertFront(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;
    
    newNode->prev = NULL; 
    newNode->next = head;

    if (head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void insertEnd(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;
    newNode->next = NULL;
    newNode->prev = head;

    if (head == NULL){
        head = newNode;
        return;
    }

    //traverse till last node
    Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }

    //current is last node
    current->next = newNode;
    newNode->prev = current;
}

void insertAfter(Node* head, string targetNode, string newName){
    Node* current = head;
    //traverse till the last node
    while (current != NULL && current->name != targetNode){ //current = targetNode
        current = current->next;
    } 

    if (current == NULL){
        return;
    }

    Node* newNode = new Node();
    newNode->name = newName;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL){
        current->next->prev = newNode;
    }
    current->next = newNode; 
}

void deleteNode(Node*& head, string targetNode){
    //empty list
    if (head == NULL){return;}

    //target is head
    if (head->name == targetNode){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node* current = head;
    //traverse until reach targetNode
    while (current->next != NULL && current->next->name != targetNode){
        current = current->next;
    }  
    //target is found
    if (current->next != NULL){
        Node* temp = current->next;
        current->next = temp->next;

        if(temp->next != NULL){
            temp->next->prev = current;
        }
        delete temp;
    }
}

void displayForward(Node* head){
    Node* current = head;
    //traverse forward
    while (current != NULL){
        cout << current->name << endl;
        current = current->next;
    }
    cout << endl;
}

void displayBackward(Node* head){
    Node* current = head;
    //traverse until last node
    while (current->next != NULL){
        current = current->next;
    }
    //traverse backward
    while (current->prev != NULL){
        cout << current->name << endl;
        current = current->prev;
    }
    cout << current->prev << endl;
}

int main(){
    Node* node1 = new Node(); 
    Node* node2 = new Node(); 
    Node* node3 = new Node(); 
    Node* node4 = new Node(); 
    
    node1->name = "Ali";
    node2->name = "Batrisyia";
    node3->name = "Claire";
    node4->name = "Dmitri";

    node1-> next = node2;
    node2-> next = node3;
    node3-> next = node4;

    node1-> prev = NULL;
    node2-> prev = node1;
    node3-> prev = node2;
    node4 -> prev = node3;

    Node* head = node1;

    //insert
    insertFront(head, "Zara");
    cout << "\nAfter inserting Zara at the front:\n";
    displayForward(head);

    insertEnd(head, "Kelly");
    cout << "\nAfter inserting Kelly at the end:\n";
    displayForward(head);

    insertAfter(head, "Dmitri", "Eleanor");
    cout << "\nAfter inserting Eleanor after Dmitri:\n";
    displayForward(head);
    
    //delete
    deleteNode(head, "Claire");
    cout << "\nAfter deleting Claire:\n";
    displayForward(head);

    cout << "Forward traversal:" <<  endl;
    displayForward(head);

    cout << "Backward traversal:" << endl;
    displayBackward(head);
    
    return 0;
}