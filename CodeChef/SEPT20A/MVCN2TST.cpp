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
#define ordered_set tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

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
    merge_sort_tree () {}
    void init(vector< int > &v){
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

    // Find kth smallest number not in range i, j
    int Qkth(int k, int posr, int posl, int l, int r, int ind) {
        if (l == r) {
            return tr[ind][0].q;
        }
        int mid = l + r >> 1, ls = tr[ind<<1].size() - tr[ind][posr].l + tr[ind][posl].l - 1;
        if (ls >= k) {
            return Qkth(k, tr[ind][posr].l, tr[ind][posl].l, l, mid, ind << 1);
        }
        return Qkth(k - ls, tr[ind][posr].r, tr[ind][posl].r, mid + 1, r, ind << 1 | 1);
    }
    int kth(int k, int i, int j) {
        int posr = upper_bound(tr[1].begin(), tr[1].end(), j, [](data l, data r){
            return l.q < r.q;
        }) - tr[1].begin();
        int posl = lower_bound(tr[1].begin(), tr[1].end(), i, [](data l, data r){
            return l.q < r.q;
        }) - tr[1].begin();
        return Qkth(k, posr, posl, 0, n-1, 1);
    }
};

int n, S[MAXC], H[MAXC], PH[MAXC];
lli F[MAXC];
pair < int, int > pos[MAXC];
vector < int > to[MAXC], heiNode[MAXC], heiNodeI[MAXC], treeArray;

void dfs(int u, int p, int h = 0) {
    pos[u].fi = treeArray.size();
    treeArray.pb(u);
    S[u] = 1;
    H[u] = h;
    for (int v : to[u]) {
        if (v != p) {
            dfs(v, u, h+1);
            S[u] += S[v];
        }
    }
    F[u] = n - S[u];
    pos[u].se = treeArray.size() - 1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int hmax = 0;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            to[i].clear();
            heiNode[i].clear();
            heiNodeI[i].clear();
        }
        treeArray.clear();
        for (int i = 0, a, b; i < n-1; i++) {
            cin >> a >> b;
            to[a].pb(b);
            to[b].pb(a);
        }
        dfs(1, 0);

        // Data for u
        for (int i = 1; i <= n; i++) {
            F[i] += F[i-1];
        }

        // Data for h
        vector< int > ord(n), treeArrayH(n);
        for (int i = 0; i < n; i++) {
            treeArrayH[i] = H[treeArray[i]];
        }
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
           return treeArrayH[i] < treeArrayH[j];
        });
        merge_sort_tree mgH, mgHC;
        mgH.init(ord);
        mgHC.init(treeArrayH);

        // Data for v
        for (int x : treeArray) {
            heiNode[H[x]].pb(x);
            hmax = max(hmax, H[x]);
        }
        merge_sort_tree mgHh[hmax+1];
        for (int i = 0; i <= hmax; i++) {
            sort(heiNode[i].begin(), heiNode[i].end());
            for (int x : heiNode[i]) {
                heiNodeI[i].pb(pos[x].fi);
            }
            mgHh[i].init(heiNodeI[i]);
            PH[i+1] = PH[i] + heiNode[i].size();
        }

        int q, u, h, v, t = 0;
        lli e, d = 0, p2 = 2, p3 = 3;
        ordered_set S;
        cin >> q;
        while (t++ < q) {
            cin >> e;
            e ^= d;

            // Finding the index
            lli lo = 1, hi = e + t, mid, ans;
            while (lo <= hi) {
                mid = lo + hi >> 1;
                if (mid - S.order_of_key(mid) <= e) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            e = ans; 
            S.insert(e);

            // Finding u
            u = lower_bound(F, F + n + 1, e) - F;
            e -= F[u-1];

            // Finding h;
            h = H[treeArray[mgH.kth(e, pos[u].fi, pos[u].se)]];
            e -= PH[h] - mgHC.query(h, pos[u].fi, pos[u].se);

            // Finding v
            v = treeArray[mgHh[h].kth(e, pos[u].fi, pos[u].se)];
            d = (d + p2*u + p3*v) % mod;
            p2 = p2 * 2 % mod, p3 = p3 * 3 % mod;
        }
        cout << d << '\n';
    }
}