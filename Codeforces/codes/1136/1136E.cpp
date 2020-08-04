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
#define MAXC 100005
// %

char t;
int a, b, n, q;
lli A[MAXC], K[MAXC], pref[MAXC];

struct data{
    
    lli x, big, lazyVal;
    bool exist, lazy;

    data(): exist(false) {} 
    data(lli v) : x(v), lazyVal(0), exist(true), lazy(false) {}

    // Node combination
    data operator+(data r){
        if(!r.exist) return *this;
        if(!this->exist) return r;
        data ans(r.x + x);
        ans.big = max(r.big, big);
        return ans;
    }
    
    // Lazy updation
    void upd(int l, int r){
        x = lazyVal * (r - l +1);
        big = lazyVal;
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
                tr[ind<<1].lazyVal = tr[ind].lazyVal;
                tr[ind<<1|1].lazyVal = tr[ind].lazyVal;
                tr[ind<<1].lazy = tr[ind<<1|1].lazy = true;
            }
            tr[ind].upd(l, r);
        }
    }
    void build( vector< lli > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].x = tr[ind].big = v[l];
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1);
        build(v, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    void update(lli x, int i, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i > r || i < l){
            return;
        }
        if(l==r){
            tr[ind].big = tr[ind].x += x;
            return;
        }
        int mid=l+r>>1;
        update(x, i, l, mid, ind<<1);
        update(x, i, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    void assign(lli x, int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i > r || j < l){
            return;
        }
        if(l >= i && j >= r){
            tr[ind].lazy = true;
            tr[ind].lazyVal = x;
            pushdown(ind, l, r);
            return;
        }
        int mid = l + r >> 1;
        assign(x, i, j, l, mid, ind<<1);
        assign(x, i, j, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    data query1(int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i>r || j<l || l>r){
            return data();
        }
        if(l>=i && r<=j){
            return tr[ind];
        }
        int mid=l+r>>1;
        return query1(i, j, l, mid, ind<<1) + query1(i, j, mid+1, r, ind<<1|1);
    }
    int findFirst(lli val, int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i>r || j<l || tr[ind].big <= val){
            return -1;
        }
        if(l == r){
            return l;
        }
        int mid = l + r >> 1;
        int q = findFirst(val, i, j, l, mid, ind<<1);
        if(q == -1){
            q = findFirst(val, i, j, mid+1, r, ind<<1|1);
        }
        return q;
    }
    lli query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(lli x, int i){ 
        update(x, i, 0, n-1, 1);
        lli val = query(i, i);
        int till = findFirst(val, i, n-1, 0, n-1, 1);
        if(till == -1){
            till = n;
        }
        assign(val, i, till-1, 0, n-1, 1);
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> A[i];
    }
    FOR(i, n-1){
        cin >> K[i+1];
        K[i+1] += K[i];
        pref[i+1] = pref[i] + K[i+1];
    }
    vector< lli > B(n);
    FOR(i, n){
        B[i] = A[i] - K[i];
    }
    seg_tree sg(B);
    cin >> q;
    while(q--){
        cin >> t >> a >> b;
        if(t == '+'){
            sg.upd(b, a-1);
        }
        else{
            cout << sg.query(a-1, b-1) + pref[b-1] - pref[max(a-2, 0)] << '\n';
        }
    }
}