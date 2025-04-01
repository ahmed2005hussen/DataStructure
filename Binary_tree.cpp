#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class t>
struct Node{
    Node *lchild , *rchild;
    t data;
};

template<class t>
class Binary_Tree{
private:
    Node<t> *root ;
    int size ;
public:
    Binary_Tree(){
        size=0 ;
        root = nullptr;

    }
    void create(){
        Node<t> *p , *n;
        t x; queue<Node<t>*>q;
        cout<< "Enter the root "<<endl;
        cin>>x;
        root= new Node<t>;
        root->data= x ;
        q.push(root);
        size++;
        root->lchild = nullptr;
        root->rchild = nullptr;
        char ch;
        while(!q.empty()){
            p = q.front();
            q.pop();

            cout<<"if "<<p->data<<" have a left child ?(y/n)";
            cin>>ch;
            if(ch=='y'){
                n = new Node<t>;
                q.push(n);
                cout<< "Enter the left node "<<endl;
                cin>>x;
                n->data = x;
                n->rchild = nullptr;
                n->lchild = nullptr;

                p->lchild = n;
                size++;
            }


            cout<<"if "<<p->data<<" have a right child ?(y/n)";
            cin>>ch;
            if(ch=='y'){
                n = new Node<t>;
                q.push(n);
                cout<< "Enter the right node "<<endl;
                cin>>x;
                n->data = x;
                n->rchild = nullptr;
                n->lchild = nullptr;

                p->rchild = n;
                size++;
            }

        }
    }

    void by_level() {
        if (!root) return;

        queue<Node<t>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<t>* p = q.front();
            q.pop();

            cout << p->data << " ";

            if (p->lchild) q.push(p->lchild);
            if (p->rchild) q.push(p->rchild);
        }
        cout << endl;
    }
    Node<t>* getRoot() {
        return root;
    }

    void preorder(Node<t> *p){
        if (p == nullptr) return;
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }

    int height(Node<t>*p){
        if(p){
            int x = height(p->lchild);
            int y = height(p->rchild);
            if(x>y){
                return x+1;
            }
            else
                return y+1;
        }
        else
            return -1;
    }

    int count(Node<t>*p){

        if(p){
            return count(p->lchild)+ count(p->rchild)+1;
        }
        return 0;
    }

    void postorder(Node<t> *p){
        if (p == nullptr) return;

        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }

    void inorder(Node<t> *p){
        if (p == nullptr) return;

        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }

    ~Binary_Tree() {
        deleteTree(root);
    }

    void deleteTree(Node<t>* p) {
        if (p == nullptr) return;
        deleteTree(p->lchild);
        deleteTree(p->rchild);
        delete p;
    }
};

int main(){

    Binary_Tree<char> a;
    a.create();
    cout<<"By level : ";
    a.by_level();


    cout<<"By preorder : ";
    a.preorder(a.getRoot());
    cout<<endl;
    cout<<"By inorder : ";
    a.inorder(a.getRoot());
    cout<< endl;

    cout<<"By inorder : ";
    a.postorder(a.getRoot());


    cout<<endl<<"the height "<<a.height(a.getRoot());
    cout<<endl<<"count "<<a.count(a.getRoot());
    return 0;
}
