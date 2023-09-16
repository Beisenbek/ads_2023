#include <iostream>

using namespace std;

void double_it(int * x, int n){
    for(int i = 0; i < n ; ++i){
        x[i] = x[i] * 2;
    }
}

void read(int * x, int n){
    for(int i = 0; i < n ; ++i){
        cin >> x[i];
    }
}

void print(int * x, int n){
    for(int i = 0; i < n ; ++i){
        cout << x[i] << " ";
    }
}


int main(){

    int a[10];

    read(a, 2);

    double_it(a, 2);

    print(a, 2);

    return 0;
}