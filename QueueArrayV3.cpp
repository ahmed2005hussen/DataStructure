// using circular
// pop()-> O(1)
// push()-> O(1);

#include <iostream>
using namespace std;
template<class T>
class Queue_array {
private:
    T *Data;
    int Size;
    int rear;
    int first;
    bool isFull() {
        return (rear + 1) % Size == first+1;
    }
public:
    Queue_array(int sz = 10) {
        Size = sz;
        Data = new T[Size];
        rear = -1;
        first = -1;
    }
    bool is_empty() {
        return (rear == first);
    }
    void push(T element) {
        if (isFull()) {
            T *temp = new T[Size * 2];
            for (int i = 0; i < Size; i++) {
                temp[i] = Data[i];
            }
            Size *= 2;
            delete[]Data;
            Data = temp;
        }
        rear = (rear + 1) % Size;
        Data[rear] = element;
    }
    void pop() {
        if (is_empty()) {
            throw runtime_error("Empty queue");
        }

        first = (first + 1) % Size;
    }
    T front() {
        if (is_empty()) {
            throw runtime_error("empty");
        }
        return Data[1 + first];
    }
    T back() {
        if (!is_empty()) return Data[rear];
        throw runtime_error("empty");
    }
    ~Queue_array() {
        delete[]Data;
    }
};

int main() {
    Queue_array<int> a;
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
        cout << a.front() << endl;
        a.pop();

    }

}
