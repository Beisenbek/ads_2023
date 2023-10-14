#include <iostream>

using namespace std;

struct hp{
    int val[100];
    int size;
    hp(){
        size = 0;
    } 
    int get_min(){
        if(size == 0) return -1;
        return val[0];
    }
    void add(int x){
        int i = size++;
        val[i] = x;
        int p = (i - 1) / 2;
        while(i > 0 && val[p] > val[i]){
            swap(val[p], val[i]);
            i = p;
            p = (i - 1) / 2;
        }
    }
    void print(){
        for(int i = 0; i < size; ++i){
            cout << val[i] << " ";
        }
        cout << endl;
    }

    int cut_min(){
        int p = 0;
        int res = val[0];
        val[p] = val[--size];
        
        while(2 * p + 1 < size){
            int c1 = 2 * p + 1;
            int c2 = 2 * p + 2;
            int minp = c1;
            if(c2 < size && val[c2] < val[c1]){
                minp = c2;
            }
            if(val[p] > val[minp]){
                swap(val[p], val[minp]);
                p = minp;
            }else break;
        }
        return res;
    }
};

int main(){

    hp h;
    int a[] = {10, 2, 3, 11, 5, 6};
    int n = sizeof(a)/sizeof(int);

    for(int i = 0; i < n; ++i){
        h.add(a[i]);
    }

    cout << h.get_min() << endl;

    for(int i = 0; i < n; ++i){
        cout << h.cut_min() << " ";
    }


    return 0;
}