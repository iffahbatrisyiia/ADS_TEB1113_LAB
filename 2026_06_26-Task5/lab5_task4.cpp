//Queue using Array
#include <iostream>
#include <string>

using namespace std;

class Queue{
    private:
        string arr[100];
        int front = -1;
        int rear = -1;

    public:
        void enqueue(string name){
            if (rear >= 99){
                cout << "Queue is full" << endl;
                return;
            }

            if (front == -1){
                front = 0;
            }

            arr[++rear] = name;
        }

        void dequeue(){
            if (front == -1){
                cout << "Queue is empty" << endl;
                return;
            }

            front++;

            if (front > rear){
                front = -1;
                rear = -1;
            }
        }

        void display(){
            if (front == -1){
                cout << "Queue is empty" << endl;
                return;
            }
            for (int i = front; i <= rear; i++){
                cout << arr[i] << endl;
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