#include <iostream>

using namespace std;

void f(string t, string s){
    long long p[t.size()];
    long long h[t.size()];

    p[0] = 1;

    for(int i = 1; i < t.size(); ++i){
        p[i] = p[i - 1] * 31;
    }

    for(int i = 0; i < t.size(); ++i){
        if(i == 0) h[i] = t[i] - 'a' + 1;
        else h[i] = h[i-1] + (t[i] - 'a' + 1) * p[i];
    } 
    
    long long h_s = 0;
    for(int i = 0; i < s.size(); ++i){
        h_s += (s[i] - 'a' + 1) * p[i];
    } 

    for(int i = 0; i <= t.size() - s.size(); ++i){
        long long temp = h[i + s.size()-1];
        if(i > 0) temp -= h[i-1];
        if(temp == h_s * p[i]){
            cout << "found!";
        }
    }


}

int main(){
    string t = "xowoxowo", s = "owo";
    f(t, s);
    return 0;
}