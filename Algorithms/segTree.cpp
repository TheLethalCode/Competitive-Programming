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
        void upd(int l, int r){
            x += lazyVal;
            lazy = false;
            lazyVal = 0;
        }
    };
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