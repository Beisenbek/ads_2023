#include <iostream>

using namespace std;

struct node{
    int value;
    int priority;
    node(int v, int p){
        this->value = v;
        this->priority = p;
    }
};

struct pq{
    private:
        node * items[100];
        int size;
    public:
        pq(){
            size = 0;
        } 
        node * get_min(){
            if(size == 0) return NULL;
            return items[0];
        }
        void add(node * x){
            int i = size++;
            items[i] = x;
            int p = (i - 1) / 2;
            while(i > 0 && items[p]->priority > items[i]->priority){
                swap(items[p], items[i]);
                i = p;
                p = (i - 1) / 2;
            }
        }
        node * cut_min(){
            int p = 0;
            node * res = items[0];
            items[p] = items[--size];
            while(2 * p + 1 < size){
                int c1 = 2 * p + 1;
                int c2 = 2 * p + 2;
                int minp = c1;
                if(c2 < size && items[c2]->priority < items[c1]->priority){
                    minp = c2;
                }
                if(items[p]->priority > items[minp]->priority){
                    swap(items[p], items[minp]);
                    p = minp;
                }else break;
            }
            return res;
        }
};

int f(int x){
    int res = 0;
    for(int i = 1; i <= x; ++i){
        if(x % i == 0) res++;
    }
    return res;
}

int main(){

    pq h;
    int a[] = {10, 2,3,11,5, 6};
    int n = sizeof(a)/sizeof(int);

    for(int i = 0; i < n; ++i){
        h.add(new node(a[i], f(a[i])));
    }
    for(int i = 0; i < n; ++i){
        cout << h.cut_min()->value << " ";
    }
    return 0;
}