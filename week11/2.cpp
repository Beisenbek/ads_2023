#include <iostream>
using namespace std;

int main(){

    string s, t;

    cin >> t >> s;

    string newt = s + "#" + t;

    int p[newt.size()];

    for(int i = 1; i <= newt.size(); ++i){
        p[i-1] = 0;
        for(int j = 1; j < i; ++j){
            string prefix = newt.substr(0, j);
            string suffix = newt.substr(i - j, j);
            if(prefix == suffix){
                p[i-1] = max(p[i-1], (int)prefix.size());
            }
        }
    }

    for(int i = 0; i < newt.size(); ++i){
        cout << p[i] << " ";
    }    

    cout << endl;

    for(int i = 0; i < newt.size(); ++i){
        if(p[i] == s.size()){
            cout << newt.substr(i- s.size() + 1, s.size()) << endl;
        }
    }  

    return 0;
}