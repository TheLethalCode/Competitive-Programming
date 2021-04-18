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
// %

typedef vector < pair < int, int > > prime_pairs; 

struct merge_tree{
    struct data{
        int p, q, l, r;
        data(int v, int _p, int i=-1, int j=-1) : q(v), p(_p), l(i), r(j) {}
    };
    int n;
    vector< vector< data > > tr;
    vector< vector< lli > > pref;
    merge_tree(prime_pairs &v){
        n=v.size(), tr.resize(4*n);
        pref.resize(4*n);
        build(0, n-1, 1, v);
    }
    void build(int l, int r, int node, prime_pairs &v){
        if(l>r) return;
        if(l==r){
            tr[node].pb(v[l].fi, v[l].se);
            tr[node].pb(1<<30, 1);
            pref[node].pb(1);
            pref[node].pb(v[l].se);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        merge(pref[node], tr[node], tr[node<<1], tr[(node<<1)+1]);
    }
    void merge(vector< lli > &pr, vector< data > &d, vector< data > &a, vector< data > &b){
        int x = a.size() - 1, y = b.size() - 1;
        int i=0, j=0;
        pr.pb(1);
        while(i<x && j<y){
            if(a[i].q < b[j].q){
                d.pb(a[i].q, a[i].p, i, j);
                pr.pb(pr.back() * a[i].p % mod);
                i++;
            }
            else{
                d.pb(b[j].q, b[j].p, i, j);
                pr.pb(pr.back() * b[j].p % mod);
                j++;
            }
        }
        while(i<x){
            d.pb(a[i].q, a[i].p, i, j);
            pr.pb(pr.back() * a[i].p % mod);
            i++;
        }
        while(j<y){
            d.pb(b[j].q, b[j].p, i, j);
            pr.pb(pr.back() * b[j].p % mod);
            j++;
        }
        d.pb(1<<30, 1, i, j);
    }
    lli query1(int i, int j, int l, int r, int in, int node){
        if (l>r || r<i || l>j) {
            return 1;
        }
        if (l >=i && j >= r){
            return pref[node][in];
        }
        int mid = l+r>>1;
        lli L = query1(i, j, l, mid, tr[node][in].l, node<<1);
        lli R = query1(i, j, mid+1, r, tr[node][in].r, (node<<1)+1);
        return L * R % mod;
    }
    lli query(int i, int j){
        int pos = lower_bound(tr[1].begin(), tr[1].end(), i, [](data l, int v){
            return l.q < v;
        }) - tr[1].begin();
        return query1(i, j, 0, n-1, pos, 1);
    }
};

struct merge_sort_tree {
    int n;
    vector< prime_pairs > tr;;
    merge_sort_tree(vector< prime_pairs > &v) {
        n = v.size();
        tr.resize(4 * n);
        build(v, 0, n - 1, 1);
    }
    
    void build(vector< prime_pairs > &v, int l, int r, int ind) {
        if (l == r) {
            tr[ind] = v[l];
            return;
        }
        int mid = l + r >> 1;
        build(v, l, mid, ind << 1);
        build(v, mid + 1, r, ind << 1 | 1);
        merge(tr[ind], tr[ind << 1], tr[ind << 1 | 1]);
    }
    void merge(prime_pairs &V, prime_pairs &A, prime_pairs &B) {
        int n = A.size(), m = B.size(), a = 0, b = 0;
        while (a < n && b < m) {
            if (A[a].fi < B[b].fi) {
                V.pb(A[a++]);
            } else if (A[a].fi > B[b].fi) {
                V.pb(B[b++]);
            } else {
                V.pb(A[a].fi, max(A[a].se, B[b].se));
                a++, b++;
            }
        }
        while (a < n) {
            V.pb(A[a++]);
        }
        while (b < m) {
            V.pb(B[b++]);
        }
    }
    prime_pairs query(int i, int j, int l, int r, int ind) {
        if (l > r || i > r || j < l) {
            return prime_pairs();
        }
        if (l >= i && r <= j) {
            return tr[ind];
        }
        int mid = l + r >> 1;
        prime_pairs left = query(i, j, l, mid, ind << 1);
        prime_pairs right = query(i, j, mid + 1, r, ind << 1 | 1);
        if (!left.empty() && !right.empty()) {
            prime_pairs ans;
            merge(ans, left, right);
            return ans;
        } else if (!right.empty()) {
            return right;
        } else {
            return left;
        }
    }
};

lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    }
    lli t = modp(n, p >> 1);
    return t * t % mod;
}

const int LIM = sqrt(MAXC) + 1;
vector< int > pos[MAXC], powers[LIM];
vector < int > prime, lp;

void linearSieve(int n){
    lp.resize(n+1);
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            prime.pb(i);
            lp[i] = i;
        }
        for (auto p : prime) {
            if (p * i > n) {
                break;
            }
            lp[p * i] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    linearSieve(MAXC);
    for (int i = 2; i < LIM; i++) {
        if (lp[i] == i) {
            powers[i].pb(1);
            int next = i;
            while (next < MAXC) {
                powers[i].pb(next);
                next *= i;
            }
        }
    }

    int n;
    cin >> n;
    vector< prime_pairs > v(n);
    prime_pairs upM(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        while (x != 1 && lp[x] < LIM) {
            int p = lp[x], cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            v[i].pb(p, cnt);
        }
        upM[i].fi = pos[x].empty()? -1: pos[x].back();
        upM[i].se = x;
        pos[x].pb(i);
    }
    
    merge_sort_tree mgL(v);
    merge_tree mgH(upM);
    int q, last = 0;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x = (x + last) % n;
        y = (y + last) % n;
        if (x > y) {
            swap(x, y);
        }
        lli ans = mgH.query(x, y);
        for (auto x : mgL.query(x, y, 0, n-1, 1)) {
            ans = ans * powers[x.fi][x.se] % mod;
        }
        cout << (last = ans) << "\n";
    }
}