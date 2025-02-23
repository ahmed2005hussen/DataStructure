// by Ahmed Hussein 2025
// Linked List :
// 1. push front
// 2. push back
// 3. pop back
// 4. pop front
// 5. display
// 6. at
// 7. isEmpty
// 8. size
// 9. max
//10. min
//11. find
//12. push_sorted
//13. insert
//14. delete
//15. isSorted
//16. reverse
//17. isLooping
//18. add
//19. addSorted

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
    Node<t> *Tail;
    int Size;

public:
    linked_list() : Size(0) {
        Head = nullptr;
        Tail = Head;
    }

    void push_back(t element) {
        auto *node = new Node<t>;
        node->value = element;
        node->Next = nullptr;
        if (Size == 0) {
            Head = Tail = node;
        } else {
            Tail->Next = node;
            Tail = node;
        }
        Size++;
    }

    void push_front(t element) {
        auto *newNode = new Node<t>; // auto == Node<t>
        newNode->value = element;
        newNode->Next = Head;
        Head = newNode;
        if (Size == 0) {
            Tail = Head;
        }
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
            auto *node = Head;
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

    void pop_front() {
        if (Size == 0) {
            throw runtime_error("List is already empty!");
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

    void pop_back() {
        auto temp = Head;
        if (Size == 0) {
            throw runtime_error("List is already empty!");
        } else if (Size == 1) {
            delete Head;
            Head = Tail = nullptr;
        } else {
            while (temp->Next != Tail) {
                temp = temp->Next;
            }
            delete Tail;
            Tail = temp;
            Tail->Next = nullptr;

        }
        Size--;
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
                    Size++;
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

    void push_sorted(t element) {
        auto *node = new Node<t>;
        node->value = element;
        if (Size != 0 && Head->value > element) {
            push_front(element);
        } else if (Size != 0 && Tail->value < element) {
            push_back(element);
        } else if (Size == 0) {
            push_back(element);
        } else {
            auto *cur = Head;
            Node<t> *pre = nullptr;

            while (cur != nullptr) {
                if (cur->value > element) {
                    node->Next = cur;
                    pre->Next = node;
                    Size++;
                    break;
                }
                pre = cur;
                cur = cur->Next;
            }

        }
    }

    bool isSorted() {
        auto temp = Head;
        if (Size == 0) {
            throw runtime_error("empty list");
        } else if (Size == 1) {
            return true;
        } else {
            while (temp->Next != nullptr) {
                if (temp->value > temp->Next->value) {
                    return false;
                }
                temp = temp->Next;

            }
            return true;
        }
    }

    void reverse() {
        Node<t> *precede = Head;
        Node<t> *cur = nullptr;
        Node<t> *previous = nullptr;
        if (Size == 0) {
            throw runtime_error("empty list");
        } else {
            while (precede != nullptr) {
                previous = cur;
                cur = precede;
                precede = precede->Next;
                cur->Next = previous;
            }
            Tail = Head;
            Head = cur;
        }
    }

    void Delete(int index) {
        if (index == 0) {
            pop_front();
        } else if (index == Size - 1) {
            pop_back();
        } else if (index > 0 && index < Size) {
            auto temp = Head;
            Node<t> *pre = nullptr;
            for (int i = 0; i < index; i++) {
                pre = temp;
                temp = temp->Next;
            }
            pre->Next = temp->Next;
            delete temp;
            Size--;
        } else {
            throw runtime_error("Invalid index: Out of bounds.");
        }

    }

    void add(linked_list<t> &other) {
        if (other.Size == 0) {
            return;
        }
        if (Size == 0) {
            Head = other.Head;
            Tail = other.Tail;
        } else {
            Tail->Next = other.Head;
            Tail = other.Tail;

        }
        Size += other.Size;
    }

    void addSorted(linked_list<t> &other) {
        if (other.Size == 0) {
            return;
        }
        if (Size == 0) {
            Head = other.Head;
            Tail = other.Tail;
            Size = other.Size;
            return;
        }

        Node<t> *p1 = Head;
        Node<t> *p2 = other.Head;
        Node<t> *newHead = nullptr;
        Node<t> *newTail = nullptr;

        if (p1->value < p2->value) {
            newHead = newTail = p1;
            p1 = p1->Next;
        } else {
            newHead = newTail = p2;
            p2 = p2->Next;
        }

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->value < p2->value) {
                newTail->Next = p1;
                p1 = p1->Next;
            } else {
                newTail->Next = p2;
                p2 = p2->Next;
            }
            newTail = newTail->Next;
        }

        if (p1 != nullptr) {
            newTail->Next = p1;
        } else {
            newTail->Next = p2;
        }

        Head = newHead;
        Tail = newTail;

        Size += other.Size;
    }

    bool isLooping() {
        auto *fast = Head;
        auto *slow = Head;
        while (fast != nullptr && fast->Next != nullptr) {
            fast = fast->Next->Next;
            slow->Next;
            if (fast == slow) {
                return true;
            }
        }
        return false;

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
