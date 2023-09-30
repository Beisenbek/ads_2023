#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    public:
        bst(){
            root = NULL;
        }
        void add(int val){
            root = add(root, val);
        }
        void print(){
            print(root);
        }
        bool find(int val){
            return find(root, val) != NULL;
        }

    private:
        node * root;
    
        node * add(node * current, int val){
            if(current == NULL){
                current = new node(val);
            }
            else if(val < current->val){
                current->left = add(current->left, val);
            }
            else if(val > current->val){
                current->right = add(current->right, val);
            }
            return current;
        }

        void print(node * current){
            if(current != NULL){
                print(current->left);
                cout << current->val << " ";
                print(current->right);
            }
        }

        node * find(node * current, int val){
            if(current == NULL) return NULL;
            if(current->val == val) return current;
            if(current->val < val) return find(current->right, val);
            return find(current->left, val);
        }

};

int main(){

    int a[] = {10, 6, 7, 1, 2, 3, 5};
    int n = sizeof(a)/sizeof(int);
    bst * b = new bst();
    
    for(int i = 0; i < n; ++i){
        b->add(a[i]);
    }

    b->print();
    cout << endl;

    for(int i = 0; i <= 10; ++i){
        cout << i << " " << b->find(i) << endl;
    }

    return 0;
}