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
#define sz(a) (int)(a.size())
#define MAXC 300005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
        data ans(x + r.x);
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
    int n, q;
    cin >> n >> q;
    vector< lli > v(1<<n);
    FOR (i, 1<<n) {
        cin >> v[i];
    }
    seg_tree sg(v);
    int cur = 0;

    auto func = [&](int r)->lli{
        int p = 0;
        lli ans = 0;
        for (int i = n; i >= 0; i--) {
            if (r & (1<<i)) {
                int tech = cur & ~((1<<i) - 1);
                ans += sg.query(p xor tech, (p + (1<<i) - 1) xor tech);
                p += 1 << i;
            }
        }
        return ans;
    };

    while (q--) {
        int t, x, k;
        cin >> t;
        switch (t) {
            case 1 : 
                cin >> x >> k;
                x--;
                sg.upd(k-v[x xor cur], x xor cur, x xor cur);
                v[x xor cur] = k;
                break;
            
            case 2 :
                cin >> k;
                cur = cur xor ((1<<k) - 1);
                break;

            case 3:
                cin >> k;
                cur = cur xor (1<<k);
                break;

            case 4:
                int l, r;
                cin >> l >> r;
                lli sum = l > 1? func(r) - func(l-1) : func(r);
                cout << sum << '\n';
                break;
        }
    }
}