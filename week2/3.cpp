#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void f(node n){
    n.val = 18;
}

void f2(node * n){
    n->val = 17;
}



int main(){

    node n1(15);
    cout << n1.val << endl;
    f(n1);
    cout << n1.val << endl;
    f2(&n1);
    cout << n1.val << endl;
    return 0;
}