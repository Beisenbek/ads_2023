#include <iostream>

using namespace std;

int a[100][100];
bool used[100];
int n;

void dfs(int v){
    cout << v + 1<< endl;
    used[v] = true;
    for(int i = 0; i < n; ++i){
        if(!used[i] && a[v][i] != 0){
            dfs(i);
        }
    }
}

int main(){
 
    cin >> n;

    for(int i = 0; i < n; ++i){
        used[i] = false;
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; ++i){
        if(!used[i]){
            dfs(i);
            cnt++;
            cout << endl;
        }
    }

    cout << cnt;

    return 0;
}