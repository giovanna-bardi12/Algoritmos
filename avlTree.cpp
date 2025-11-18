#include <iostream>
#include <string>
using namespace std;

//montando struct


struct Node{
    int key;
    int element; //elemento
    Node* left;
    Node* right;
    int height;

   //construtor
   Node(int k, int e): 
    key(k),
    element(e),
    left(nullptr),
    right(nullptr),
    height(0) {}

};

string rotationInfo;

class avlTree
{
public:

Node* root;

avlTree(){
    root = nullptr;
}

~avlTree(){
    deleteNode(root);
    root = nullptr;
}

int h(Node* rt){
    if(rt == nullptr){
        return -1;
    }
    return rt->height;
}

int getBalance(Node* rt){
    if(rt == nullptr){
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

Node* rightRotate(Node* rt){
    Node* l = rt->left;
    Node* lr = l->right;

    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    return l;
}

Node* leftRotate(Node* rt){
    Node* r = rt->right;
    Node* rl = r->left;

    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    return r;
    
}

Node* NodeInsertHelp(Node* rt, int k, int e){
    if(rt == nullptr){
        return new Node(k,e);
    }

    if(rt->key > k){
        rt->left = NodeInsertHelp(rt->left, k, e);
    }else{
        rt->right = NodeInsertHelp(rt->right, k, e);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    //implementar rotações

    if(balance < -1 && k >= rt->right->key){
        rotationInfo = to_string(rt->key) + " is unbalanced, L-rotation!";

        return leftRotate(rt);
    }

    if(balance > 1 && k < rt->left->key){
        rotationInfo = to_string(rt->key) + " is unbalanced, R-rotation!";

        return rightRotate(rt);
    }

    if(balance > 1 && k >= rt->left->key){
        rotationInfo = to_string(rt->key) + + " is unbalanced, LR-rotation!";

        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }

    if(balance < -1 && k < rt->right->key){
        rotationInfo = to_string(rt->key) + + " is unbalanced, RL-rotation!";

        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
    
}

void printInOrder(Node* rt){
    if(rt == nullptr){
        return;
    }
    printInOrder(rt->left);
    cout << rt->key << " ";
    printInOrder(rt->right);
}

void printPreOrder(Node*rt){
    if(rt == nullptr){
        return;    
    }
    cout << rt->key << " ";
    printPreOrder(rt->left);
    printPreOrder(rt->right);
}

void printPostOrder(Node* rt){
    if(rt == nullptr){
        return;
    }
    printPostOrder(rt->left);
    printPostOrder(rt->right);
    cout << rt->key << " ";
}

void deleteNode(Node* rt){
    if(rt == nullptr){
        return;
    }
    deleteNode(rt->left);
    deleteNode(rt->right);
    delete rt;
}

};

int main(){
    avlTree arvore;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, key;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> key;
        rotationInfo = "no rotation!";
        arvore.root = arvore.NodeInsertHelp(arvore.root, key, 0);
        cout << "insert " << key << ": " << rotationInfo << "\n";
    }

    cout << "preorder: ";
    arvore.printPreOrder(arvore.root);
    cout << "\n";

    cout << "inorder: ";
    arvore.printInOrder(arvore.root);
    cout << "\n";

    cout << "postorder: ";
    arvore.printPostOrder(arvore.root);
    cout << "\n";

    return 0;
}

