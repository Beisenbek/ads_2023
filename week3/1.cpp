#include <iostream>

using namespace std;

int bin_search(int * a, int n, int x){
    int result = -1;
    int l = 0;
    int r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            result = m;
            break;
        }
        if(a[m] > x){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return result;
}


int main(){

    int a[] = {10, 11, 200, 300};
    int x;
    int n = sizeof(a) / sizeof(int);
    cin >> x;
    cout << bin_search(a, n, x);

    return 0;
}