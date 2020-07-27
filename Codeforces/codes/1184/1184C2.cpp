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
#define MAXC 200005
#define RAN 2000000
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
map< int, vector< int > > V;
vector< int > P;
int ans = 0;

struct seg_tree{
    int n;
    vector< int > lazy, tr;
    seg_tree(){
        n = 2*RAN+2, tr.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }
    void update(int x, int i, int j, int l, int r, int ind){
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind] += lazy[ind], lazy[ind]=0;
        }
        if(i>r || j<l || l>r || i>j) return;
        if(l>=i && r<=j){
            tr[ind] += x;
            if(l!=r) lazy[ind<<1] += x, lazy[(ind<<1)+1] += x;
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1), update(x, i, j, mid+1, r, (ind<<1)+1);
        tr[ind] = max(tr[ind<<1], tr[(ind<<1)+1]);
    }
    int query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            return 0;
        }
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind] += lazy[ind], lazy[ind]=0;
        }
        if(l>=i && r<=j) return tr[ind];
        int mid=l+r>>1;
        return max(query1(i, j, l, mid, ind<<1), query1(i, j, mid+1, r, (ind<<1)+1));
    }
    int query(){ return query1(0, n-1, 0, n-1, 1);}
    void upd(int x, int i, int j){ update(x, max(0, i) , min(n-1, j), 0, n-1, 1); }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    FOR(i, n){
        int x, y;
        cin >> x >> y;
        V[x+y].pb((y - x) + RAN);
    }
    FORR(el, V){
        P.pb(el.fi);
    }
    n = P.size();
    seg_tree sg;
    int st = 0, en = 0;
    while(en < n && P[en] <= P[st]+2*r){
        FORR(y, V[P[en]]){
            sg.upd(1, y-r, y+r);
        }
        en++;
    }
    ans = max(ans, sg.query());
    while(en < n){
        FORR(y, V[P[en]]){
            sg.upd(1, y-r, y+r);
        }
        while(P[en] > P[st]+2*r){
            FORR(y, V[P[st]]){
                sg.upd(-1, y-r, y+r);
            }
            st++;
        }
        ans = max(ans, sg.query());
        en++;
    }   
    cout << ans << '\n';
}