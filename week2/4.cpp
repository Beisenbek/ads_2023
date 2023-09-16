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


int main(){

    node * n1 = new node(15); 
    cout << n1->val << endl;
    
    return 0;
}