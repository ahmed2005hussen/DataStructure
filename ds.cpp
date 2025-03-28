
#include <iostream>
#include <cassert>

using namespace std;
template<class T>
struct Node {
    T value;
    Node *next;
};

template<class T>
class Queue_linked {
private:
    Node<T> *first;
    Node<T> *rear;

public:
    Queue_linked() {
        rear = nullptr;
        first = rear;
    }

    bool is_empty() {
        return (rear == nullptr );
    }

    void push(T element) {
        Node<T> *node = new Node<T>;
        node->value = element;

        if (first == rear && rear == nullptr) {
            first = node;
            rear = node;
        }
        else{
            rear->next =node;
            rear = node;
        }
    }

    void pop() {
        if (is_empty()) {
            throw runtime_error("Empty queue");
        }

        if(first==rear){
            delete first;
            first = nullptr;
            rear = nullptr;
        }
        else {
            auto *node = first;
            first= first->next;
            delete node;
        }

    }

    T front() {
        if (is_empty()) {
            throw runtime_error("empty");
        }
        return first->value;
    }

    T back() {
        if (!is_empty()) return rear->value;
        throw runtime_error("empty");
    }

    ~Queue_linked() {
        auto *node = first;
        while(node!= nullptr){
            first = first->next;
            delete node;
            node = first;
        }
    }
};

int main() {
    Queue_linked<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    a.push(10);
    a.push(11);


    while (!a.is_empty()) {
        cout << a.back() << endl;
        a.pop();
    }
    
}