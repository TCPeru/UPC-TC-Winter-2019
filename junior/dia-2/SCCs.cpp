#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i, N) for(int i = 0; i < int(N); ++i)
using namespace std;

const int MAXN = 1024;

int N, M, I;
vector<int> G[MAXN], GT[MAXN];
bool visitado[MAXN];
int SCC[MAXN];
vector<int> toposort;

int dfs(int v){
    visitado[v] = true;
    for(auto &w : G[v])
        if( not visitado[w])
            dfs(w);
    toposort.push_back(v);
}

void pintar(int v, int color){
    SCC[v] = color;
    cout << v << ", ";
    for(auto &w: GT[v])
        if( not SCC[w] )
            pintar(w, color);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("grafo_scc.txt", "r", stdin);

    cin>>N>>M;
    forn(i, M){
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }

    forn(v, N)
        if( not visitado[v])
            dfs(v);

    reverse(toposort.begin(), toposort.end());

    for(auto v : toposort)
        if( not SCC[v] ){
            ++I;
            cout << "componente " << I << ": ";
            pintar(v, I);
            cout << endl;
        }

    return 0;
}
