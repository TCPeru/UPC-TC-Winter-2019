#include <iostream>
#include <unordered_map>
#define izq(i) (i<<1)
#define der(i) (i<<1|1)
#define pad(i) (i>>1)
using namespace std;

const int MAXN = 1<<29;

unordered_map<int, int> ST;

void set(int i, int v){
	i += MAXN;
	ST[i] = v;
	for(i = pad(i); i; i = pad(i))
		ST[i] = ST[izq(i)] + ST[der(i)];
}

int query(int A, int B, int n = 1, int a = 0, int b = MAXN){
    ++C;
	if( b <= A or  B <= a ) return 0;
	if( A <= a and b <= B ) return ST[n];
	int m = (a + b) / 2;
	return query(A, B, izq(n), a, m) + query(A, B, der(n), m, b);
}


int main(){

    set(4, -5);
    set(1000, 750);
    set(35000, 100);


    cout << query(1, 4) << endl;
    cout << query(4, 1001) << endl;
    cout << query(1, 40000000) << endl;

    return 0;
}
