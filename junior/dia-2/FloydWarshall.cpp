#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i, N) for(int i = 0; i < int(N); ++i)
using namespace std;

const int MAXN = 1024;
const int INF = 999;

int N, M, I;
int A[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("grafo_dijkstra.txt", "r", stdin);

    forn(i, MAXN)
        forn(j, MAXN)
            A[i][j] = INF;

    forn(i, MAXN) A[i][i] = 0;

    cin>>N>>M;
    forn(i, M){
        int u, v, d;
        cin>>u>>v>>d;
        A[u][v] = d;
    }

    forn(k, N)
        forn(i, N)
            forn(j, N)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

    forn(i, N){
        forn(j, N)
            cout << A[i][j] << '\t';
        cout << endl;
    }


    return 0;
}
