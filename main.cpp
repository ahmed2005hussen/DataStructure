#include<iostream>

using namespace std;

template<class t>
struct Node {
    t value;
    Node *next;
    Node *pre;
};

template<class t>
class doubly_linked_list {
private:
    int Size;
    Node<t> *head;
    Node<t> *tail;
public:
    doubly_linked_list() {
        Size = 0;
        head = nullptr;
        tail = head;
    }

    void push_back(t element) {
        auto *node = new Node<t>;
        node->value = element;
        if (Size == 0) {
            head = node;
            tail = head;
            node->next = nullptr;
            node->pre = nullptr;
        } else {
            tail->next = node;
            node->pre = tail;
            node->next = nullptr;
            tail = node;
        }
        Size++;
    }

    void push_front(t element) {
        auto *node = new Node<t>;
        node->value = element;
        node->pre = nullptr;
        if (Size == 0) {
            head = node;
            tail = head;
            node->next = nullptr;

        } else {
            node->next = head;
            head->pre = node;
            head = node;
        }
        Size++;
    }

    void insert(t element, int index) {

        if (Size == 0) {
            auto *node = new Node<t>;
            node->value = element;
            head = node;
            tail = head;
            node->next = nullptr;
            node->pre = nullptr;
        } else if (index == Size) {
            push_back(element);
        } else if (index == 0) {
            push_front(element);
        } else if (index > 0 && index < Size) {
            auto *node = new Node<t>;
            node->value = element;
            auto *curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next->pre = node;
            curr->next = node;
            node->pre = curr;
        } else {
            throw runtime_error("incorrect index");
        }
        Size++;

    }

    void pop_front() {
        if (Size != 0) {
            auto *curr = head;
            head = head->next;
            delete curr;
            if (head) head->pre = nullptr;
            Size--;
        } else {
            throw runtime_error("empty");
        }
    }

    void pop_back() {
        if (Size) {
            auto *curr = tail;
            tail = tail->pre;
            delete curr;
            if (tail)tail->next = nullptr;
            Size--;
        } else {
            throw runtime_error("empty");
        }
    }

    void pop(int index) {
        if (Size!=0) {
            if (index == 0) {
                pop_front();
            } else if (index == Size - 1) {
                pop_back();
            }
            else if (index > 0 && index < Size) {
                auto *curr = head;
                for (int i = 0; i < index; i++) {
                    curr = curr->next;
                }
                curr->next->pre = curr->pre;
                curr->pre->next = curr->next;
                delete curr;
                Size--;
            }
            else {
                throw runtime_error("invalid index");
            }
        }
        else {
            throw runtime_error("empty");
        }
    }

    void reverse(){
        if(Size){
            auto *curr = head;
            auto *temp = head;
            auto *a= tail ;
            tail=head;
            head=a; 
            while(curr!= nullptr){
                temp=curr->next;
                curr->next=curr->pre;
                curr->pre =temp;
                curr= curr->pre;

            }
        }
        else{
            throw runtime_error("empty");
        }
    }
    int size(){
        return Size;
    }
    void display_front() {
        auto *curr = head;
        cout << '[';
        while (curr != nullptr) {
            cout << curr->value;
            (curr->next != nullptr) ? cout << ',' : cout << ']' << endl;
            curr = curr->next;
        }
    }

    void display_back() {
        auto *curr = tail;
        cout << '[';
        while (curr != nullptr) {
            cout << curr->value;
            (curr->pre != nullptr) ? cout << ',' : cout << ']' << endl;
            curr = curr->pre;
        }
    }

    ~doubly_linked_list() {
        auto *curr = head;
        while (curr != nullptr) {
            head = head->next;
            delete curr;
            curr = head;
        }
    }

};

int main() {
    doubly_linked_list<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_front(0);
    a.insert(99, 5);

    a.display_front();
    a.reverse();
    a.display_front();
}