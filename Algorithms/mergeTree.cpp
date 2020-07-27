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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// MERGE SORT TREE WITH FRACTIONAL CASCADING
// NUMBER OF ELEMENTS STRICTLY LESS THAN K IN O(logN)

struct data{
    int q, l, r;
    data(int v, int i=-1, int j=-1) : q(v), l(i), r(j) {}
};

void merge(vector< data > &d, vector< data > &a, vector< data > &b){
    int x = a.size() - 1, y = b.size() - 1;
    int i=0, j=0;
    while(i<x && j<y){
        if(a[i].q < b[j].q){
            d.pb(a[i].q, i, j);
            i++;
        }
        else{
            d.pb(b[j].q, i, j);
            j++;
        }
    }
    while(i<x){
        d.pb(a[i].q, i, j);
        i++;
    }
    while(j<y){
        d.pb(b[j].q, i, j);
        j++;
    }
    d.pb(1<<30, i, j);
}

struct merge_sort_tree{
    int n;
    vector< vector< data > > tr;
    merge_sort_tree(vector< int > &v){
        n=v.size(), tr.resize(4*n);
        build(0, n-1, 1, v);
    }
    void build(int l, int r, int node, vector< int > &v){
        if(l>r) return;
        if(l==r){
            tr[node].pb(v[l]);
            tr[node].pb(1<<30);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        merge(tr[node], tr[node<<1], tr[(node<<1)+1]);
    }
    int query1(int i, int j, int l, int r, int in, int node){
        if(l>r || r<i || l>j) return 0;
        if(l >=i && j >= r){
            return in;
        }
        int mid = l+r>>1;
        int L = query1(i, j, l, mid, tr[node][in].l, node<<1);
        int R = query1(i, j, mid+1, r, tr[node][in].r, (node<<1)+1);
        return L + R;
    }
    int query(int x, int i, int j){
        int pos = lower_bound(tr[1].begin(), tr[1].end(), x, [](data l, data r){
            return l.q < r.q;
        }) - tr[1].begin();
        return query1(i, j, 0, n-1, pos, 1);
    }
};

int main(int argc, char **argv){
    return 0;
}