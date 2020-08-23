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

struct seg_tree{
    int n;
    struct data{
        lli x, lazyVal;
        bool exist, lazy;

        data(): exist(false) {} 
        data(lli v) : x(v), exist(true), lazy(false), lazyVal(0) {}

        // Node combination
        data operator+(data r){
            if(!r.exist) return *this;
            if(!this->exist) return r;
            data ans(max(x, r.x));
            return ans;
        }
        
        // Lazy updation
        void upd(){
            x += lazyVal;
            lazy = false;
            lazyVal = 0;
        }
    };
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
    int findFirst(int l, int r, int ind) {
        pushdown(ind, l, r);
        if (tr[ind].x <= 0) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = l + r >> 1, ret = findFirst(l, mid, ind << 1);
        if (ret == -1) {
            ret = findFirst(mid+1, r, ind << 1 | 1);
        }
        return ret;
    }
    lli query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(lli x, int i, int j){ 
        update(x, i , j, 0, n-1, 1); 
    }
};

struct FenwickTree {
    vector<lli> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    lli sum(int r) {
        lli ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    void add(int idx, lli delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;
        vector < lli > E(n), R(n);
        FOR (i, n) {
            cin >> E[i] >> R[i];
        }
        seg_tree sg(R);
        FenwickTree pref(n);
        for (int i = 0; i < n; i++) {
            sg.upd(-E[i], 0, i-1);
            sg.upd(-E[i], i+1, n-1);
            pref.add(i, E[i]);
        }
        pair< lli, int > ans = {0, 0};
        int cnt = 0;
        while (cnt < n - 1) {
            int whi = sg.findFirst(0, n-1, 1);
            if (whi == -1) {
                ans = {-1, cnt};
                break;
            }
            lli bef = pref.sum(n-1) + pref.sum(whi) - E[whi];
            if (ans.fi < bef) {
                ans = {bef, cnt};
            }
            sg.upd(E[whi], 0, whi-1);
            sg.upd(E[whi], whi+1, n-1);
            sg.upd(-1e18, whi, whi);
            pref.add(whi, -E[whi]);
            cnt++;
        }
        if (cnt == n-1 && ans.fi < pref.sum(n-1)) {
            ans = {pref.sum(n-1), n-1};
        }
        cout << "Case #" << z << ": " << ans.se << " ";
        if (ans.fi == -1) {
            cout << "INDEFINITELY";
        } else {
            cout << ans.fi;
        }
        cout << '\n';
    }    
}