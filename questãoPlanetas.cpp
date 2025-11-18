#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key; //orbita
    int element; //qts planetas
    Node* right;
    Node* left;
    int height;

    //construtor
    Node(int k, int e){
        key = k;
        element = e;
        right = nullptr;
        left = nullptr;
        height = 0;
    }
};

class avlTree{
private:  

    void deleteNode(Node* rt){
        if(rt == nullptr){
            return;
        }
        deleteNode(rt->left);
        deleteNode(rt->right);
        delete rt;

    }  

    int h(Node* rt){
        if (rt == nullptr){
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

    Node* rightRotate(Node*rt){
        Node* l = rt->left;
        Node* lr = l->right;

        l->right = rt;
        rt->left = lr;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        return l;
    }

    Node* leftRotate(Node*rt){
        Node* r = rt->right;
        Node* rl = r->left;

        r->left = rt;
        rt->right = rl;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;
        return r;
    }

    int machine1(int n){
        return n * 1;
    }

public:
    Node* root; 

    avlTree(){
        root = nullptr;
    }

    ~avlTree(){
        deleteNode(root);
        root = nullptr;
    }

    Node* insertHelp(Node* rt, int k, int e){
        if(rt == nullptr){
            return new Node(k,e);
        }

        if(rt->key > k){
            rt->left = insertHelp(rt->left, k, e);

        }else if(rt->key < k){
            rt->right =insertHelp(rt->right, k, e);

        }else{ //k == key
            rt->element++;
            return rt;
        }

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        int balance = getBalance(rt);

        if(balance < -1 && k>= rt->right->key){
            return leftRotate(rt);
        }

        if(balance > 1 && k < rt->left->key){
            return rightRotate(rt);
        }

        if(balance > 1 && k >= rt->left->key){
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }

        if(balance < -1 && k < rt->right->key){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }

        return rt;
    }

    void throughTree(int & custo, Node* rt, int c){
        if(rt == nullptr){
        return;
        }

        throughTree(custo, rt->left, c);
        int result = min(machine1(rt->element), c);
        custo = custo + result;
        throughTree(custo,rt->right,c);
        
        
    }

};

//global
int custo = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,c,k;
    cin >> t; //casos

    for(int i = 0; i < t; i++){
        avlTree arvoreCaso;

        custo = 0;
        cin >> n; //planetas
        cin >> c; //custo de usar segunda máquina

        for(int i2 = 0; i2 < n; i2++){
            cin >> k;
            arvoreCaso.root = arvoreCaso.insertHelp(arvoreCaso.root, k, 1);
        }

        arvoreCaso.throughTree(custo,arvoreCaso.root,c);
        cout << custo << "\n";

    }

    return 0;
}