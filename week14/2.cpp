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



int main(){
    
    cin >> n;
    

    map<int, set<edge> > m;

    for(int i = 0; i < n; ++i){
        used[i] = false;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
            if(g[i][j] != 0){
                edge e(i, j, g[i][j]);
                m[i].insert(e);
            }
        }
    }

    int v = 0;
    for(int i = 0; i < n; ++i){
        set<edge> edges = m[v];
        for(set<edge>:: iterator j = edges.begin(); j != edges.end(); ++j){
            edge e = *j;
        }
    }

    /*

    for(map<int, set<edge> > :: iterator i = m.begin(); i != m.end(); ++i){
        int v = (*i).first;
        set<edge> edges = (*i).second;
        cout << v + 1 << ": " << endl;
        for(set<edge>:: iterator j = edges.begin(); j != edges.end(); ++j){
            j->print();
        }
        cout << endl;
    }*/

    return 0;
}