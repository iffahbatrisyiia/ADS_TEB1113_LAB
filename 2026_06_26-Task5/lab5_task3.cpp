//Queue using linked list
#include <iostream>
#include <string>

using namespace std;

class Queue{
    private:
        struct Node{
            string name;
            Node* next = NULL;
        };
        
        Node* front = NULL;
        Node* rear = NULL;
    
    public:
        void enqueue(string name){
            Node* newNode = new Node();
            newNode->name = name;

            if (rear == NULL){
                front = newNode;
                rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        void dequeue(){
            if (front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            front = front->next;

            if (front == NULL){
                rear = NULL;
            }
        }

        void display(){
            if (front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            Node* current = front;
            while (current != NULL){
                cout << current->name << endl;
                current = current->next;
            }
        }
};

int main(){
    Queue q;

    q.enqueue("Nur");
    cout << "Enqueue Nur:" << endl;
    q.display(); cout << endl;

    q.enqueue("Iffah");
    cout << "Enqueue Iffah:" << endl;
    q.display(); cout << endl;

    q.enqueue("Batrisyia");
    cout << "Enqueue Batrisyia:" << endl;
    q.display(); cout << endl;

    q.enqueue("Sani");
    cout << "Enqueue Sani:" << endl;
    q.display(); cout << endl;

    cout << "- Display full queue -" << endl;
    q.display();
    cout << endl;

    cout << "- Dequeue -" << endl;
    q.dequeue();
    q.display();

    return 0;
}