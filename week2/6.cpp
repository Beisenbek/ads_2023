#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct dll{
    public:
        dll(){
            head = NULL;
            tail = NULL;
        }
        void add_node(int x){
            node * temp = new node(x);
            if(head == NULL){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;  
                temp->prev = tail;
                tail = temp;  
            }
        }
        void print(){
            print(head);
        }
        void r_print(){
            r_print(tail);
        }

    private:
        node * head;
        node * tail;
        void print(node * cur){
            if(cur != NULL){
                cout << cur->val << " ";
                print(cur->next);
            }
        }
        void r_print(node * cur){
            if(cur != NULL){
                cout << cur->val << " ";
                r_print(cur->prev);
            }
        }
};


int main(){

    dll dl;
    for(int i = 0; i < 10; ++i){
        dl.add_node(i + 1);
    }
    dl.print();
    cout << endl;
    dl.r_print();
   return 0;
}