#include <iostream>
using namespace std;

struct Node{
    string name;
    Node* prev = NULL;
    Node* next = NULL;
    
};
int main(){
    
    Node* node1 = new Node(); 
    Node* node2 = new Node(); 
    Node* node3 = new Node(); 
    Node* node4 = new Node(); 
    
    node1->name = "Ahmad";
    node2->name = "Batrisyia";
    node3->name = "Claire";
    node4->name = "Dmitri";

    node1-> next = node2;
    node2-> next = node3;
    node3-> next = node4;

    node2-> prev = node1;
    node3-> prev = node2;
    node4 -> prev = node3;

    cout << "Forward traversal:" <<  endl;
    Node* display_node = node1;
    for(int i=0;i<4;i++){
        cout << display_node -> name << endl;
        display_node = display_node ->next;
    }

    cout << endl;

    cout << "Backward traversal:" << endl;
    display_node = node4;
    for(int i=0; i<4; i++){
        cout << display_node -> name << endl;
        display_node = display_node -> prev;
    }

    return 0;
}