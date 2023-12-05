#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct edge{
    int start;
    int end;
    int weight;
    edge(){

    }
    edge(int s, int e, int w){
        start = s;
        end = e;
        weight = w;
    }
    bool operator < (edge other) const{
        return this->weight < other.weight;
    }
    void print() const{
        cout << start + 1 << " " << end + 1 << " " << weight << endl;
    } 
  
};

struct cmp{
    bool operator() (edge r, edge l){
        if(r.weight > l.weight) return false;
        return true;
    }
};

int g[100][100];
bool used[100];
int n;
vector<int> min_e;
vector<int> sel_e;


int main(){
    
    cin >> n;
    
    set<edge, cmp> edges;

    for(int i = 0; i < n; ++i){
        used[i] = false;
        min_e[i] = 10000000;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
            if(g[i][j] != 0){
                edge e(i, j, g[i][j]);
            }
        }
    }

    int v = 0;
    for(int i = 0; i < n; ++i){
        if(edges.size()  == 0){
            break;
        }
        edge cur = *edges.begin();
        int v = cur.end;
        edges.erase(edges.begin());
        for(int j = 0; j < n; ++j){
            edge//???
        }
    }


    return 0;
}