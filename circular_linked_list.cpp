// by Ahmed Hussein 2025
// Linked List :
// 1. push front ....
// 2. push back  ....
// 3. pop back   ....
// 4. pop front  ....
// 5. display    ....
// 6. overLoad on [] ...
// 7. isEmpty  ...
// 8. size  ...
// 9. max  ...
//10. min  ...
//11. find  ...
//12. insert ...
//13. search ...


#include <iostream>

using namespace std;
template<class t>
struct Node {
    t value;
    Node *Next;
};

template<class t>
class circular_linked_list {
private:
    Node<t> *head;
    Node<t> *tail;
    int Size;

public:
    circular_linked_list() : Size(0) {
        head = nullptr;
        tail = head;
    }

    void push_back(t element) {
        auto *node = new Node<t>;
        node->value = element;
        if (Size == 0) {
            head = node;
            tail = head;
            tail->Next = head;
            head->Next = nullptr;
        } else {
            tail->Next = node;
            tail = node;
            tail->Next = head;
        }
        Size++;
    }

    void push_front(t element) {
        auto *node = new Node<t>;
        node->value = element;
        if (Size == 0) {
            head = node;
            tail = node;
            tail->Next = head;
            head->Next = nullptr;
        } else {
            node->Next = head;
            head = node;
            tail->Next = head;
        }
        Size++;
    }

    void insert(t element, int index) {
        if (index == 0) {
            push_front(element);
        } else if (Size == index) {
            push_back(element);
        } else if (index > 0 && index < Size) {

            Node<t> *node = new Node<t>;
            Node<t> *curr = head;
            node->value = element;
            int count = 0;
            do {
                if (count == index - 1) {
                    node->Next = curr->Next;
                    curr->Next = node;
                    Size++;
                    return;
                }
                count++;
                curr = curr->Next;
            } while (curr != head);
        } else {
            throw runtime_error("invalid index");
        }
    }

    void pop_back() {
        if (Size) {
            Node<t> *curr = head;
            while (curr->Next != tail) {
                curr = curr->Next;
            }
            curr->Next = head;
            delete tail;
            tail = curr;
            Size--;
        } else {
            throw runtime_error("empty list");
        }
    }

    void pop_front() {
        if (Size) {
            auto *temp = head;
            head = head->Next;
            tail->Next = head;
            delete temp;
            Size--;
        } else {
            throw runtime_error("empty list");

        }
    }


    void display() {
        if (Size) {
            auto node = head;
            cout << '[';
            do {
                (node->Next != head) ? cout << node->value << "," : cout << node->value << "]" << endl;;

                node = node->Next;

            } while (node != head);

        } else {
            throw runtime_error("empty linked");


        }
    }

    t operator[](int index) {
        if (index >= 0 && index < Size) {
            auto *node = head;
            int count = 0;
            while (node->Next != head) {
                if (count == index) {
                    return node->value;
                }
                node = node->Next;
                count++;
            }
        }
        throw runtime_error("invalid index");
    }

    bool isEmpty() {
        return Size==0;
    }

    int size() {
        return Size;
    }

    t max() {
        if (Size != 0) {
            auto curr = head;
            t element = head->value;
            do {
                curr = curr->Next;
                if (curr->value > element) {
                    element = curr->value;
                }
            } while (curr != head);
            return element;
        }
        throw runtime_error("empty");
    }

    t min() {
        if (Size != 0) {
            auto curr = head;
            t element = head->value;
            do {
                curr = curr->Next;
                if (curr->value < element) {
                    element = curr->value;
                }
            } while (curr != head);
            return element;
        }
        throw runtime_error("empty");
    }

    int find(t element) {
        if (Size) {
            Node<t> *curr = head;
            int index = 0;
            do {
                if (element == curr->value) {
                    return index;
                }
                index++;
                curr = curr->Next;
            } while (curr != head);
            return -1 ;
        }
        throw runtime_error("empty");
    }

    bool search(t element) {
        if (Size) {
            Node<t> *curr = head;
            int index = 0;
            do {
                if (element == curr->value) {
                    return true;
                }
                index++;
                curr = curr->Next;
            } while (curr != head);
            return false ;
        }
        throw runtime_error("empty");
    }

    ~circular_linked_list() {
        if (head == nullptr) return;
        tail->Next = nullptr;
        auto temp = head;

        while (temp != nullptr) {
            head = head->Next;
            delete temp;
            temp = head;
        }
    }

};

int main() {
    circular_linked_list<int> a;
    a.insert(1, 0);
    a.insert(2, 0);
    a.insert(13, 0);
    a.insert(4, 0);
    a.insert(5, 0);
    a.insert(6, 0);
    a.display();
    cout << a.search(6) << endl;


}
