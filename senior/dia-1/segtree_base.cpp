#include <iostream>
#include <cstdio>
#define izq(i) (i<<1)
#define der(i) (i<<1|1)
#define pad(i) (i>>1)
using namespace std;

const int MAXN = 1<<20;

int ST[MAXN<<1];

void build(){
    for(int i = MAXN-1; i; --i)
        ST[i] = ST[izq(i)] + ST[der(i)];
}

void set(int i, int v){
	i += MAXN;
	ST[i] = v;
	for(i = pad(i); i; i = pad(i))
		ST[i] = ST[izq(i)] + ST[der(i)];
}

int query(int A, int B, int n = 1, int a = 0, int b = MAXN){
	if( b <= A or  B <= a ) return 0;
	if( A <= a and b <= B ) return ST[n];
	int m = (a + b) / 2;
	return query(A, B, izq(n), a, m) + query(A, B, der(n), m, b);
}



int main(){

    ST[MAXN+0] = 14;
    ST[MAXN+1] = 6;
    ST[MAXN+2] = 0;
    ST[MAXN+3] = 100;
    ST[MAXN+4] = -5;

    build();

    cout << query(1, 4) << endl;

    set(2, 4);

    cout << query(1, 4) << endl;

    return 0;
}
