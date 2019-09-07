#include <iostream>
using namespace std;

const int MAXN = 128;

struct ST{

    int valor;
    ST *izq, *der;

    int query(int A, int B, int a = 0, int b = MAXN){
        if( b <= A or  B <= a ) return 0;
        if( A <= a and b <= B ) return valor;
        int m = (a + b) / 2;
        return izq->query(A, B, a, m) + der->query(A, B, m, b);
    }

    ST* set(int I, int X, int a = 0, int b = MAXN){
        if( I < a or  b <= I ) return this;
        if( a + 1 == b ) return new ST{X, izq, der};
        int m = (a + b) / 2;
        auto i = izq->set(I, X, a, m);
        auto d = der->set(I, X, m, b);
        return new ST{ i->valor + d->valor, i, d};
    }
};

int main()
{
    ST T1;
    T1.valor = 0;
    T1.izq = &T1;
    T1.der = &T1;

    cout << T1.query(2, 5) << endl;
    cout << "-------------" << endl;

    auto T2 = T1.set(3, 100);

    cout << T1 .query(2, 5) << endl;
    cout << T2->query(2, 5) << endl;
    cout << "-------------" << endl;

    auto T3 = T2->set(3, 20);

    cout << T1 .query(2, 5) << endl;
    cout << T2->query(2, 5) << endl;
    cout << T3->query(2, 5) << endl;
    cout << "-------------" << endl;

    auto T4 = T2->set(4, 50);

    cout << T1 .query(2, 5) << endl;
    cout << T2->query(2, 5) << endl;
    cout << T3->query(2, 5) << endl;
    cout << T4->query(2, 5) << endl;


    return 0;
}
