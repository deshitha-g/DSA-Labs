#include <iostream>
#include <chrono>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int val) {
            data = val;
            next = NULL;
        }
};

class LinkedStack {
    private:
        Node* top;
    
    public:
        LinkedStack() {
            top = NULL;
        }
        
        bool isEmpty() {
            return top == NULL;
        }
        
        void push(int element) {
            Node* newNode = new Node(element);
            if (isEmpty()) {
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }
        
        void pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        
        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return top->data;
        }
        
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            Node* curr = top;
            while (curr != NULL) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
};

int main()
{
    auto start_time = chrono::high_resolution_clock::now();

    LinkedStack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    for(int i=0; i<5; i++) {
        s.pop();
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
