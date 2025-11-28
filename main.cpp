#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class Queue{
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
public:

    Queue() : head(nullptr), tail(nullptr) {}
    
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void push(T val) {
        Node* newNode = new Node(val);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = head;
        T val = head->data;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        return val;
    }

    T front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

};

template <typename T>

class Quack{
    private:

    public:
    
};


int main()
{

}