#include <iostream>
#define forn(i, n) for(int i = 0; i < n; ++i)
using namespace std;

typedef struct node* treap;

struct node{
	int value;
	int p, size;
	bool rev;
	treap l, r;
};


int size(treap t) {
    return t ? t->size : 0;
}

void upd_size(treap t) {
    if(t)   t->size = size(t->l) + size(t->r) + 1;
}

void propagate (treap t) {
    if (t && t->rev) {
        t->rev = false;
        swap (t->l, t->r);
        if (t->l)  t->l->rev ^= true;
        if (t->r)  t->r->rev ^= true;
    }
}

void merge (treap &t, treap l, treap r) {
    propagate(l); propagate(r);
    if (not l or not r)           t = l ? l : r;
    else if (l->p > r->p)         merge (l->r, l->r, r),  t = l;
    else                          merge (r->l, l, r->l),  t = r;
    upd_size(t);
}

void split (treap t, treap &l, treap &r, int key) {
    propagate (t);
    if (!t) 				return void( l = r = 0 );
    if (key <= size(t->l))	split (t->l, l, t->l, key),              r = t;
    else					split (t->r, t->r, r, key-1-size(t->l)), l = t;
    upd_size(t);
}

void reverse (treap t1, int l, int r) {
    treap t2, t3;
    split (t1, t1, t2, l);
    split (t2, t2, t3, r-l);
    t2->rev ^= true;
    merge (t1, t1, t2);
    merge (t1, t1, t3);
}

void output (treap t) {
    if (!t)  return;
    propagate (t);
    output (t->l);
    printf ("%d ", t->value);
    output (t->r);
}

int main(){
   // freopen("entrada.txt", "r", stdin);

    int N, M;

    scanf("%d%d", &N, &M);

    srand(215115);
    treap t = nullptr;
    forn(i, N){
        int p = rand();
        merge(t, t, new node{i+1, p, 1, false, nullptr, nullptr});
    }

    forn(i, M){
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(t, l-1, r);
    }

    output(t);
    cout << endl;

    return 0;
}
