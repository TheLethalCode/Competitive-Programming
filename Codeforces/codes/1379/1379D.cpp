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
#define MAXC 200005
// %

struct data{
    
    lli x, lazyVal;
    bool exist, lazy;

    data(): exist(false) {} 
    data(lli v) : x(v), exist(true), lazy(false), lazyVal(0) {}

    // Node combination
    data operator+(data r){
        if(!r.exist) return *this;
        if(!this->exist) return r;
        data ans(min(x, r.x));
        return ans;
    }
    
    // Lazy updation
    void upd(){
        x += lazyVal;
        lazy = false;
        lazyVal = 0;
    }
};

struct seg_tree{
    int n;
    vector< data > tr;
    seg_tree(int size){
        n = size;
        tr.resize(4*n, data(0));
    }
    seg_tree(vector< lli > &v){
        n = v.size();
        tr.resize(4*n, data(0));
        build(v, 0, n-1, 1);
    }
    // Lazy propagaton
    void pushdown(int ind, int l, int r){
        if(tr[ind].lazy){
            if(l!=r){
                tr[ind<<1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1|1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1].lazy = tr[ind<<1|1].lazy = true;
            }
            tr[ind].upd();
        }
    }
    void build( vector< lli > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].x = v[l];
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
    lli query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(lli x, int i, int j){ 
        update(x, i , j, 0, n-1, 1); 
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    vector < pair< int, int > > V(n);
    set < int > S;
    vector < int > X;
    FOR (i, n) {
        cin >> V[i].fi >> V[i].se;
        S.insert(V[i].se);
        S.insert((V[i].se + k) % m);
    }
    if (k == 1) {
        cout << "0 0\n";
        return 0;
    }
    FORR (x, S) {
        X.pb(x);
    }
    int T = X.size();
    seg_tree sg(T);
    auto upd = [&](int l, int r) {
        int pl = lower_bound(X.begin(), X.end(), l) - X.begin();
        int pr = upper_bound(X.begin(), X.end(), r) - X.begin() - 1;
        if (pl <= pr) {
            sg.upd(1, pl, pr);
        }
    };
    auto chg = [&](int l, int r) {
        if (l >= m) {
            l -= m;
            r -= m;
        }
        if (r >= m) {
            upd(0, r - m);
            r = m - 1;
        }
        upd(l, r);
    };
    auto chk = [](int l, int r, int i)->bool {
        if (r > l && i > l && i < r) {
            return true;
        }
        if (r < l && (i > l || i < r)) {
            return true;
        }
        return false;
    };
    FORR (t, V) {
        int cur = t.se;
        chg(t.se + 1, t.se + k - 1);
        chg(t.se + m/2 + 1, t.se + m/2 + k - 1);
    }
    pair< int, int > ans = {mod, -1};
    FOR (i, T) {
        ans = min(ans, make_pair((int)sg.query(i, i), X[i]));
    }
    if (ans.se >= m/2) {
        ans.se -= m/2;
    }
    cout << ans.fi << " " << ans.se << '\n';
    FOR (i, n) {
        int l1 = (ans.se - k + m) % m, r1 = ans.se;
        int l2 = (ans.se - k + m/2 + m) % m, r2 = (ans.se + m/2) % m;
        if (chk(l1, r1, V[i].se) || chk(l2, r2, V[i].se)) {
            cout << i + 1 << ' ';
        }
        
    }
    cout << '\n';
}
