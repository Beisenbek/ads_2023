#include <iostream>
using namespace std;

int main(){

    string s;

    cin >> s;

    int p[s.size()];

    for(int i = 1; i <= s.size(); ++i){
        p[i-1] = 0;
        for(int j = 1; j < i; ++j){
            string prefix = s.substr(0, j);
            string suffix = s.substr(i - j, j);
            if(prefix == suffix){
                p[i-1] = max(p[i-1], (int)prefix.size());
            }
        }
    }

    for(int i = 0; i < s.size(); ++i){
        cout << p[i] << " ";
    }    

    return 0;
}