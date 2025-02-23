// by Ahmed Hussein 2025
// Linked List :
// . push front
// . push back
// . pop back
// . pop front
// . display
// . at
// . isEmpty
// . size
// . max
// . min
// . search


#include <iostream>

using namespace std;

template<class t>
struct Node {
    t value;
    Node *Next;
};

template<class t>

class linked_list {
private:
    Node<t> *Head;
    int Size;

public:
    linked_list() : Size(0) {
        Head = nullptr;
    }

    void push_back(t element) {
        auto *newnode = new Node<t>;
        newnode->value = element;
        newnode->Next = nullptr;
        if (Size == 0) {
            Head = newnode;
        } else {
            Node<t> *p = Head;
            while (p->Next != nullptr) {
                p = p->Next;
            }
            p->Next = newnode;
        }
        Size++;
    }

    void push_front(t element) {
        auto *newNode = new Node<t>; // auto == Node<t>
        newNode->value = element;
        newNode->Next = Head;
        Head = newNode;
        Size++;
    }

    void display() {
        if (Size) {
            Node<t> *temp = Head;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->Next;
            }
        } else {
            throw runtime_error("Empty List");
        }
    }

    t at(int index) {
        if (index >= Size || index < 0) {
            throw (runtime_error("invalid index"));
        } else {
            auto *p = Head;
            for (int i = 0; i < index; i++) {
                p = p->Next;
            }
            return p->value;
        }
    }

    bool isEmpty() {
        return Size;
    }

    int size() {
        return Size;
    }

    t max() {
        if (Size) {
            auto node = Head;
            t element = node->value;
            node = node->Next;
            while (node != nullptr) {
                if (node->value > element) {
                    element = node->value;
                }
                node = node->Next;
            }
            return element;
        }

        throw runtime_error("Empty list");

    }

    t min() {
        if (Size) {
            auto node = Head;
            t element = node->value;
            node = node->Next;
            while (node != nullptr) {
                if (node->value < element) {
                    element = node->value;
                }
                node = node->Next;
            }
            return element;
        }
        throw runtime_error("Empty list");
    }

    int find(t element) {
        auto *node = Head;
        int count = 0;
        while (node != nullptr) {
            if (node->value == element) {
                return count;
            }
            node = node->Next;
            count++;
        }
        return -1;
    }

    void insert(t element, int index) {
        if (index == 0) {
            push_front(element);
        } else if (index == Size) {
            push_back(element);
        } else if (index < Size && index > 0) {
            Node<t> *pre = nullptr;
            Node<t> *cur = Head;
            auto *node = new Node<t>;
            node->value = element;
            int count = 0;
            while (cur != nullptr) {
                if (index == count) {
                    node->Next = cur;
                    pre->Next = node;
                    Size++ ;
                    return;
                }
                count++;
                pre = cur;
                cur = cur->Next;
            }

        } else {
            throw runtime_error("Invalid index: Out of bounds.");
        }
    }

    ~linked_list() {
        Node<t> *temp;

        while (Head != nullptr) {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
    }

};


int main() {

    linked_list<int> a;
    a.push_back(20);
    a.push_back(10);
    a.push_back(2);
    a.push_back(30);
    a.push_back(1);
    a.insert(12, 2);
    a.display();


    return 0;
}