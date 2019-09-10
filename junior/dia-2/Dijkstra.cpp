#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define forn(i, N) for(int i = 0; i < int(N); ++i)
using namespace std;

const int MAXN = 1024;

struct edge{
    int v, d;
    bool operator<(const edge &o) const {
        return d > o.d;
    }
};

int N, M;
vector<edge> G[MAXN];
int D[MAXN], P[MAXN];

void dijkstra(int raiz){
    priority_queue<edge> Q;
    fill(D, D+N, -1);
    fill(P, P+N, -1);
    D[raiz] = 0;
    Q.push({raiz, 0});
    while( not Q.empty() ){
        auto c = Q.top(); Q.pop();
        if( c.d > D[c.v] ) continue;
        for(auto &e : G[c.v])
            if( D[e.v] == -1 or D[e.v] > c.d + e.d ){
                D[e.v] = c.d + e.d;
                P[e.v] = c.v;
                Q.push({e.v, D[e.v]});
            }
    }
}


int main(){
    //ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("grafo_dijkstra.txt", "r", stdin);

    cin>>N>>M;
    forn(i, M){
        int u, v, d;
        cin>>u>>v>>d;
        G[u].push_back({v, d});
    }

    dijkstra(0);

    forn(i, N)
        cout << D[i] << ' ';
    cout << endl;

    vector<int> camino;
    for(int v = 6; v != -1; v = P[v])
        camino.push_back(v);

    reverse(camino.begin(), camino.end());

    for(auto &v: camino)
        cout << v << "->";

    return 0;
}
