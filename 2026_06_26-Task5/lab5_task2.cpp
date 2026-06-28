//stack using linked list
#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        struct Node {
            string name;
            Node* next = NULL;
        };
        
        Node* top = NULL;

    public:
        void push(string name) {
            Node* newNode = new Node();
            newNode->name = name;
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            top = top->next;
        }

        void peek() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Top: " << top->name << endl;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* current = top;
            while (current != NULL) {
                cout << current->name << endl;
                current = current->next;
            }
        }
};

int main() {
    Stack stack;

    stack.push("Nur");
    stack.push("Iffah");
    stack.push("Batrisyia");
    stack.push("Sani");

    cout << "--- Display ---" << endl;
    stack.display();

    cout << "--- Peek ---" << endl;
    stack.peek();

    cout << "--- Pop ---" << endl;
    stack.pop();
    stack.display();

    return 0;
}