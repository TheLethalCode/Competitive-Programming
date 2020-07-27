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
#define RANGE 1000000
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

struct data{
    int x;
    bool exist;
    data(): exist(false) {} 
    data(int v) : x(v), exist(true) {}
    data operator+(data r){
        if(!r.exist) return *this;
        if(!this->exist) return r;
        data ans(min(x, r.x));
        return ans;
    }
    void upd(int lazy){
        x += lazy;
    }
};
struct seg_tree{
    int n;
    vector< pair< bool, int > > lazy;
    vector< data > tr;
    seg_tree(int size){
        n = size;
        tr.resize(4*n, data(0));
        lazy.resize(4*n, {false, 0});
    }
    seg_tree(vector< lli > &v){
        n = v.size();
        tr.resize(4*n);
        lazy.resize(4*n, {false, 0});
        build(v, 0, n-1, 1);
    }
    void build( vector< lli > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].x = v[l];
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1);
        build(v, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    void update(int x, int i, int j, int l, int r, int ind){
        if(lazy[ind].fi){
            if(l!=r){
                lazy[ind<<1].se += lazy[ind].se;
                lazy[(ind<<1)+1].se += lazy[ind].se;
                lazy[ind<<1].fi = 1;
                lazy[(ind<<1)+1].fi = 1;
            }
            tr[ind].upd(lazy[ind].se);
            lazy[ind] = {false, 0};
        }
        if(i>r || j<l || l>r || i>j) return;
        if(l>=i && r<=j){
            tr[ind].upd(x);
            if(l!=r) {
                lazy[ind<<1].se += x;
                lazy[(ind<<1)+1].se += x;
                lazy[ind<<1].fi = 1;
                lazy[(ind<<1)+1].fi = 1;
            }
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1);
        update(x, i, j, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    data query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            return data();
        }
        if(lazy[ind].fi){
            if(l!=r){
                lazy[ind<<1].se += lazy[ind].se;;
                lazy[(ind<<1)+1].se += lazy[ind].se;;
                lazy[ind<<1].fi = 1;
                lazy[(ind<<1)+1].fi = 1;
            }
            tr[ind].upd(lazy[ind].se);
            lazy[ind] = {false, 0};
        }
        if(l>=i && r<=j) return tr[ind];
        int mid=l+r>>1;
        return query1(i, j, l, mid, ind<<1) + query1(i, j, mid+1, r, (ind<<1)+1);
    }
    int query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(int x, int i, int j){ update(x, i , j, 0, n-1, 1); }
};
int n, m, q, j, cur, A[MAXC], B[MAXC];
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    seg_tree sg(RANGE + 1);
    cin >> n >> m;
    FOR(i, n){
        cin >> A[i+1];
        sg.upd(-1, 1, A[i+1]);
    }
    FOR(i, m){
        cin >> B[i+1];
        sg.upd(1, 1, B[i+1]);
    }
    cin >> q;
    while(q--){
        int ty, a, b;
        cin >> ty >> a >> b;
        if(ty==1){
            sg.upd(1, 1, A[a]);
            A[a] = b;
            sg.upd(-1, 1, A[a]);
        }
        else{
            sg.upd(-1, 1, B[a]);
            B[a] = b;
            sg.upd(1, 1, B[a]);
        }
        for(j=19, cur=0;j>=0;j--){
            if(cur+(1<<j)<=RANGE && sg.query(cur+(1<<j), RANGE)<0){
                cur += 1<<j;
            }
        }
        cout << (cur?cur:-1) << '\n';
    }
}