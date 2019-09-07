#include <iostream>
#include <cstdio>
#define izq(i) (i<<1)
#define der(i) (i<<1|1)
#define pad(i) (i>>1)
using namespace std;

const int MAXN = 1<<20;

struct lazy{
    int lazyA = 0;
    int lazyB = 0;
};

int ST[MAXN<<1];
lazy L[MAXN<<1];


void propagate(int n, int r){
	ST[n] += L[n].lazyA * r + L[n].lazyB * r * (r-1) / 2;
	if( n < MAXN ){
		L[izq(n)].lazyA += L[n].lazyA;
		L[izq(n)].lazyB += L[n].lazyB;
        L[der(n)].lazyA += L[n].lazyA + L[n].lazyB * r / 2;
		L[der(n)].lazyB += L[n].lazyB;
    }
	L[n] = {};
}


void update(int A, int B, int P, int Q, int n = 1, int a = 0, int b = MAXN){
    if( L[n].lazyA or L[n].lazyB ) propagate(n, b-a);
	if( b <= A or  B <= a ) return;
	if( A <= a and b <= B ){
        L[n] = {P + Q * (a-A), Q};
        propagate(n, b-a);
        return;
	}
	int m = (a + b) / 2;
	update(A, B, P, Q, izq(n), a, m);
	update(A, B, P, Q, der(n), m, b);
	ST[n] = ST[izq(n)] + ST[der(n)];
}

int query(int A, int B, int n = 1, int a = 0, int b = MAXN){
    if( L[n].lazyA or L[n].lazyB ) propagate(n, b-a);
	if( b <= A or  B <= a ) return 0;
	if( A <= a and b <= B ) return ST[n];
	int m = (a + b) / 2;
	return query(A, B, izq(n), a, m) + query(A, B, der(n), m, b);
}



int main(){

    update(3, 13, 2, 5);
    // 0   0   0   2   7  12  17  22  27  32  37  42  47   0   0
    // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14

    update(6, 10, 10, -50);
    // 0   0   0   2   7  12  27 -18 -63 -108 37  42  47   0   0
    // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14

    for(int i = 0; i < 15; ++i)
        cout << query(i, i+1) << ' ';

    cout << endl << query(7, 10) << endl;


    return 0;
}
