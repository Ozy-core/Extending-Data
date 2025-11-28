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
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

    public:

    Quack() : head(nullptr), tail(nullptr) {}
    ~Quack() {
        while (!isEmpty()) {
            popFront();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void pushFront(const T& val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(const T& val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T popFront() {
        if (isEmpty()) {
            throw runtime_error("Quack is empty");
        }
        Node* temp = head;
        T val = head->data;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return val;
    }

    T popBack() {
        if (isEmpty()) {
            throw runtime_error("Quack is empty");
        }
        Node* temp = tail;
        T val = tail->data;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        return val;
    }

    T front() const {
        if (isEmpty()) {
            throw runtime_error("Quack is empty");
        }
        return head->data;
    }

    T back() const {
        if (isEmpty()) {
            throw runtime_error("Quack is empty");
        }
        return tail->data;
    }
};


int main()
{

}