// stack using linked list
#include <iostream>

using namespace std;

template<class t >
struct Node {
    t value;
    Node *Next;
};

template<class t>
class stack {
private:
    Node<t> *Head;
    Node<t> *Tail;
    int Size;

public:
    stack() {
        Size = 0;
        Head = nullptr;
        Tail = Head;
    }


    void push(t element) {
        auto *newNode = new Node<t>;
        newNode->value = element;
        newNode->Next = Head;
        Head = newNode;
        if (Size == 0) {
            Tail = Head;
        }
        Size++;
    }

    bool isEmpty() {
        return Size==0;
    }

    void pop() {
        if (Size == 0) {
            throw runtime_error("stack empty");
        } else if (Size == 1) {
            delete Head;
            Head = Tail = nullptr;

        } else {
            auto temp = Head;
            Head = Head->Next;
            delete temp;

        }
        Size--;
    }

    t top() {
      if(isEmpty()){
          throw runtime_error("empty");
      }

        return Head->value;
    }

    ~stack() {
        Node<t> *temp;

        while (Head != nullptr) {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
    }
};


int main() {

    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);


    while (!a.isEmpty()) {
        cout << a.top() << ' ';
        a.pop();
    }

}
