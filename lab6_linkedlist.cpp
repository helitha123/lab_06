#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { // Constructor to initialize top as NULL
        top = NULL;
    }

    bool push(int x) {
        Node* temp = new Node();
        if (temp == NULL) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        else {
            temp->data = x;
            temp->next = top;
            top = temp;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return 0;
        }
        else {
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return x;
        }
    }

    bool isEmpty() {
        return (top == NULL);
    }

    bool isFull() {
        return false;
    }

    int stacktop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else {
            int x = top->data;
            return x;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
        }
        else {
            std::cout << "Stack Elements: ";
            Node* temp = top;
            while (temp != NULL) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    std::cout << s.pop() << " popped from stack\n";
    std::cout << "Top element is " << s.stacktop() << std::endl;
    s.display();
    std::cout << s.isFull() << std::endl;
    return 0;
}
