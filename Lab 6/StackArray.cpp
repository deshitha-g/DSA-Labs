#include <iostream>
#include <chrono>

using namespace std;

const int maximumSize = 50;

class Stack {
    private:
        int arr[maximumSize];
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            if (top == -1) {
                return true;
            } else {
                return false;
            }
        }

        bool isFull() {
            if (top == maximumSize-1) {
                return true;
            } else {
                return false;
            }
        }

        void push(int element) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            arr[top] = element;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return;
            }
            top--;
        }

        int stackTop() {
            return arr[top];
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            for(int i=0; i<top+1; i++) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
};


int main()
{
    auto start_time = chrono::high_resolution_clock::now();

    Stack s;
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
