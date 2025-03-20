// stack using  array
#include <iostream>

using namespace std;

template<class t>
class stack {
private:
    t Top;
    int Size;
    int length;
    t *arr;

    void resize() {
        Size *= 2;
        t *temp = new t[Size];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    stack(int sz = 10) {
        Size = sz;
        length = 0;
        arr = new t[Size];
    }


    void push(t element) {
        if (length == Size) {
            resize();
        }
        arr[length++] = element;
        Top = element;
    }

    bool isEmpty() {
        return (length == 0);
    }

    void pop() {
        if (isEmpty()) {
            throw runtime_error("this is an empty stack ");
        }
        length--;
        Top = arr[length - 1];
    }

    t top() {
        if (isEmpty()) {
            throw runtime_error("empty stack");
        }
        return Top;
    }

    ~stack() {
        delete[]arr;
    }
};


int main() {

    stack<int> a(5);
    a.push(1);
    a.push(2);
    a.push(3);


    while (!a.isEmpty()) {
        cout << a.top() << ' ';
        a.pop();
    }
    a.top();

}
