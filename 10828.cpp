//성공
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Stack{
private:
    int top;
    int capacity;
    T* stack;
    void level_up() {
        T* new_stack = new T[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
        capacity *= 2;
    }
public:
    Stack() : top(-1), capacity(8) {
        stack = new T[capacity];
    }
    ~Stack() {
        delete[] stack;
    }
    void push_back(T data) {
        if (full()) {
            level_up();
        }
        top++;
        stack[top] = data;
    }
    void pop_back() {
        if (empty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        top--;
    }
    T back() {
        return stack[top];
    }
    T front() {
        return stack[0];
    }
    bool full() {
        if (top == capacity - 1) return true;
        else return false;
    }
    bool empty() {
        if (top == -1) return true;
        else return false;
    }
    int size() {
        return top + 1;
    }


};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;


    Stack<int> stack;
    for (int i = 0; i < N; i++) {
        string cmd;
        int X;
        cin >> cmd;
        if (cmd == "push") {
            cin >> X;
            stack.push_back(X);
        }
        else if (cmd == "pop") {
            if (stack.empty()) {
                cout << "-1\n";
            }
            else {
                cout << stack.back() << '\n';
                stack.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << stack.size() << '\n';
        }
        else if (cmd == "empty") {
            if (stack.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (cmd == "top") {
            if (stack.empty()) {
                cout << "-1\n";
            }
            else {
                cout << stack.back() << '\n';
            }
        }
    }

    return 0;
}