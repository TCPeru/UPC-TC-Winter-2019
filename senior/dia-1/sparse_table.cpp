#include <iostream>
#define forr(i, a, n) for(int i = int(a); i < int(n); ++i)
#define forn(i, n) forr(i, 0, n)
using namespace std;

const int MAXN = 128;
const int LOGN = 8;

int st[MAXN][LOGN];
int lt[MAXN];

int main(){
    int N = 8;
    int A[] = {10, 5, 7, 8, -7, 45, 0, 3};
            //  0  1  2  3   4   5  6  7

    for(int i = 0; i < LOGN; ++i)
        lt[1<<i] = i;
    forr(i, 1, N)
        lt[i] = max(lt[i], lt[i-1]);

    forn(i, N)
        st[i][0] = A[i];

    forr (k, 1, LOGN)
        for (int i = 0; i + (1 << k) <= N; i++)
            st[i][k] = min(st[i][k-1], st[i + (1 << (k - 1))][k - 1]);
    {
        // query [A, B)
        int A = 3;
        int B = 6;
        cin>> A >> B;
        int l = lt[B - A];
        int minimum = min(st[A][l], st[B - (1 << l)][l]);
        cout << minimum << endl;
    }

    return 0;
}
