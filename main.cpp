// infix to postfix using stack based on linked list

#include <iostream>
#include <string>

using namespace std;

template<class t>
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
        return Size == 0;
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
        if (isEmpty()) {
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


bool isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return false;
    }

    return true;
}

int precedence(char x) {

    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

string convert_Infix_Postfix(string &state) {
    stack<char> st;
    string postfix;
    int count = 0;
    while (count != state.length()) {
        if (isOperand(state[count])) {
            postfix += state[count++];
        } else {
            if (st.isEmpty()) {
                st.push(state[count++]);
            } else {
                if (precedence(st.top()) < precedence(state[count])) {
                    st.push(state[count++]);
                } else {
                    postfix += st.top();
                    st.pop();
                }
            }
        }
    }
    while (!st.isEmpty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {

    string state = "a+b*c-d/e";
    string postfix = convert_Infix_Postfix(state);
    cout << postfix;

}