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

struct ll{
    public:
        ll(){
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
                tail = temp;  
            }
        }
        void print(){
            print(head);
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
};


int main(){

   ll l;
   for(int i = 0; i < 10; ++i){
        l.add_node(i + 1);
   }
   l.print();
    
   return 0;
}