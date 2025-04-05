#include<iostream>

using namespace std;

template<class t>
struct Node {
    t data;
    Node *lchild;
    Node *rchild;
};

template<class t>
class BST {
private:
    Node<t> *root;

public:
    BST() {
        root = nullptr;
    }

    void insert(t element) {
        if (!root) {
            root = new Node<t>;
            root->data = element;
            root->rchild = nullptr;
            root->lchild = nullptr;
            return;
        }
        Node<t> *tail, *node;
        auto *p = new Node<t>;
        node = root;

        while (node != nullptr) {
            tail = node;
            if(node->data == element)return;

            if (node->data < element) {
                node = node->rchild;
            } else {
                node = node->lchild;
            }
        }
        if (tail->data < element) {
            tail->rchild = p;

        } else {
            tail->lchild = p;
        }
        p->data = element;
        p->rchild = nullptr;
        p->lchild = nullptr;
    }

    bool search(t element){
        Node<t>* temp = root;
        while(temp!=nullptr){
            if(temp->data == element) { return true; }

            if (temp->data < element) {
                temp = temp->rchild;
            } else {
                temp = temp->lchild;
            }
        }
        return false;
    }

    void inorder(Node<t>*p){
        if(!p)return;
        inorder(p->lchild);
        cout<< p->data<<" " ;
        inorder(p->rchild);
    }

    Node<t>* getroot(){
        return root ;
    }

    ~BST(){
        deletetree(root);
    }
    void deletetree(Node<t>*temp){
        if(temp == nullptr)return;
        deletetree(temp->lchild);
        deletetree(temp->rchild);
        delete temp;
    }
};


int main(){
    BST<int>a;
    a.insert(30);
    a.insert(15);
    a.insert(10);
    a.insert(20);
    a.insert(50);
    a.insert(40);
    a.insert(60);

    cout<< "the order is ";
   a.inorder(a.getroot());

    cout<<"find  " << 30 << " : "<<  a.search(30)<<endl;
    cout<<"find  " << 10 << " : "<<  a.search(10)<<endl;
    cout<<"find  " << 20 << " : "<<  a.search(20)<<endl;
    cout<<"find  " << 40 << " : "<<  a.search(40)<<endl;
    cout<<"find  " << 12 << " : "<<  a.search(12)<<endl;
    cout<<"find  " << 0 << " : "<<  a.search(0)<<endl;
    cout<<"find  " << 123 << " : "<<  a.search(123)<<endl;
}




