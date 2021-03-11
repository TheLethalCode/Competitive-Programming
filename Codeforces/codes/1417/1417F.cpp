#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 300005
// %

int par[MAXC], val[MAXC], n, m, q;
bool invalidE[MAXC], splitQ[2*MAXC];
pair< int, int > E[MAXC], Qu[2*MAXC];
vector< int > lis[MAXC];

struct seg_tree{
    struct data{
        int lazyVal;
        pair< int, int > x;
        bool exist, lazy;

        data(): exist(false) {} 
        data(pair< int, int > v) : x(v), exist(true), lazy(false), lazyVal(0) {}
        // Node combination
        data operator+(data r){
            if(!r.exist) return *this;
            if(!this->exist) return r;
            data ans(max(x, r.x));
            return ans;
        }
        // Lazy updation
        void upd(int l, int r){
            x.fi += lazyVal;
            lazy = false;
            lazyVal = 0;
        }
    };
    int n;
    vector< data > tr;
    seg_tree(int size){
        n = size;
        tr.resize(4*n, data({-1, 0}));
    }
    seg_tree(vector< int > &v){
        n = v.size();
        tr.resize(4*n, data({-1, 0}));
        build(v, 0, n-1, 1);
    }
    void pushdown(int ind, int l, int r){ // Lazy propagaton
        if(tr[ind].lazy){
            if(l!=r){
                tr[ind<<1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1|1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1].lazy = tr[ind<<1|1].lazy = true;
            }
            tr[ind].upd(l, r);
        }
    }

    void build( vector< int > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].x = {v[l], l};
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1);
        build(v, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    void update(lli x, int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i>r || j<l || l>r || i>j){
            return;
        }
        if(l>=i && r<=j){
            tr[ind].lazy = true;
            tr[ind].lazyVal += x;
            pushdown(ind, l, r);
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1);
        update(x, i, j, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    data query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            return data();
        }
        pushdown(ind, l, r);
        if(l>=i && r<=j){
            return tr[ind];
        }
        int mid=l+r>>1;
        return query1(i, j, l, mid, ind<<1) + query1(i, j, mid+1, r, ind<<1|1);
    }
    pair< int, int > query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(lli x, int i, int j){ 
        update(x, i , j, 0, n-1, 1); 
    }
};

struct node {
    int Lc, Rc, lSize, l;
    void ass(int i, int j, int s) {
        Lc = i, Rc = j;
        lSize = s;
    } 
};

int fp(int x) {
    return x == par[x] ? x : par[x] = fp(par[x]);
}

vector<int> buildInitial() {
    for (int i = 0; i < m; i++) {
        if (invalidE[i]) {
            continue;
        }
        int x = fp(E[i].fi), y = fp(E[i].se);
        if (x == y) {
            continue;
        }
        if (lis[x].size() > lis[y].size()) {
            swap(x, y);
        }
        par[x] = y;
        for (int wee : lis[x]) {
            lis[y].pb(wee);
        }
    }

    vector< int > cur;
    for (int i = 1; i <= n; i++) {
        if (fp(i) == i) {
            cur.pb(i);
        }
    }
    return cur;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + MAXC, 0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        lis[i].pb(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> E[i].fi >> E[i].se;
    }
    for (int i = 0; i < q; i++) {
        cin >> Qu[i].fi >> Qu[i].se;
        if (Qu[i].fi == 2) {
            invalidE[--Qu[i].se] = 1;
        }
    }

    // Organize the initial sets
    vector< int > iniSets = buildInitial(), whiQu(n + 1);
    int iniSize = iniSets.size();
    vector< node > nodes(q + iniSize);
    for (int i = 0; i < iniSize; i++) {
        nodes[q + i].ass(-1, -1, 0);
        whiQu[iniSets[i]] = q + i;
    } 
    

    // Build the tree
    for (int i = q - 1; i >= 0; i--) {
        if (Qu[i].fi == 1) {
            continue;
        }
        int j = Qu[i].se, u = E[j].fi, v = E[j].se;
        int x = fp(u), y = fp(v);        
        if (x == y) {
            continue;
        }
        
        // Merge nodes
        if (lis[x].size() > lis[y].size()) {
            swap(x, y);
        }
        for (int wee : lis[x]) {
            lis[y].pb(wee);
        }
        par[x] = y;

        // Manage the tree
        splitQ[i] = 1;
        nodes[i].ass(whiQu[y], whiQu[x], lis[y].size() - lis[x].size());
        whiQu[y] = i;
    }

    // Build the initial array and set range
    set < int > range;
    range.insert(-1);
    vector< int > where(n + 1), V(n);
    for (int i = 1, mark = 0; i <= n; i++) {
        if (fp(i) == i) {
            for (int x : lis[i]) {
                where[x] = mark;
                V[mark++] = val[x-1];
            }
            nodes[whiQu[i]].l = *range.rbegin();
            range.insert(range.end(), mark-1);
        }
    }
    range.insert(range.end(), n-1);
    seg_tree S(V);

    // Process the queries
    for (int i = 0; i < q; i++) {
        if (Qu[i].fi == 1) {
            auto it = range.lower_bound(where[Qu[i].se]);
            int r = *it, l = *prev(it) + 1;
            auto res = S.query(l, r);
            cout << res.fi << '\n';
            if (res.fi) {
                S.upd(-V[res.se], res.se, res.se);
                V[res.se] = 0;
            }
        } else if (splitQ[i]) {
            range.insert(nodes[i].l + nodes[i].lSize);
            nodes[nodes[i].Lc].l = nodes[i].l;
            nodes[nodes[i].Rc].l = nodes[i].l + nodes[i].lSize;
        }
    }
    
}