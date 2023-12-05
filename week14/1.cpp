#include <iostream>
#include <vector>
#include <algorithm>

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
    void print(){
        cout << start + 1 << " " << end + 1 << " " << weight << endl;
    } 
    bool operator < (edge other){
        return this->weight < other.weight;
    }
};

int g[100][100];
bool used[100];
int n;

vector<edge> edges;

edge get_not_used_min_edge(){
    sort(edges.begin(), edges.end());
    edge result(-1,-1,-1);
    for(int i = 0; i < edges.size(); ++i){
        if(!used[edges[i].start]){
            result = edges[i];
            break;
        }
    }
    return result;
}

int main(){
    
    cin >> n;


    for(int i = 0; i < n; ++i){
        used[i] = false;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
            if(g[i][j] != 0){
                edge e(i, j, g[i][j]);
                edges.push_back(e);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        edge cur = get_not_used_min_edge();
        if(cur.start != -1){
            used[cur.start] = true;
            used[cur.end] = true;
            cur.print();
        }
    }

    /*
    

    for(int i = 0; i < edges.size(); ++i){
        edges[i].print();
    }
    */
    return 0;
}