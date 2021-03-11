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
#define MAXC 300005
// %

int par[MAXC], rep[MAXC], up[MAXC], sal[MAXC];

int fp(int x){
    return x==par[x]? x : par[x]=fp(par[x]);
}

void unite(int x, int y, int ass){
    x = fp(x), y = fp(y);
    par[y] = x;
    rep[x] = ass;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set< pair< int, int > > v[n];

    memset(up, 0xff, sizeof(up));
    iota(par, par + MAXC, 0);
    iota(rep, rep + MAXC, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < n; j++) {
            cin >> x;
            if (i == j) {
                sal[i] = x;
            } else {
                v[i].insert({x, j});
            }
        }
    }
    int cnt = 0, num = n;
    while (cnt < n*(n-1)) {
        int sm = MAXC, l, r;
        for (int i = 0; i < n; i++) {
            if (v[i].empty()) {
                continue;
            }
            if (v[i].begin()->fi < sm) {
                sm = v[i].begin()->fi;
                l = i, r = v[i].begin()->se;
            }
        }
        v[l].erase(v[l].begin()), v[r].erase(v[r].begin());
        cnt += 2;

        int x = rep[fp(l)], y = rep[fp(r)];
        if (x == y) {
            continue;
        } else if (sal[x] == sm) {
            up[y] = x;
            unite(l, r, x);
        } else if (sal[y] == sm) {
            up[x] = y;
            unite(l, r, y);
        } else {
            up[x] = up[y] = num;
            sal[num] = sm;
            unite(l, r, num);
            num++;
        }
    }
    cout << num << '\n';
    for (int i = 0; i < num; i++) {
        cout << sal[i] << ' ';
    }
    cout << '\n';
    cout << rep[fp(0)] + 1 << '\n';
    for (int i = 0; i < num; i++) {
        if (up[i] != -1) {
            cout << i + 1 << " " << up[i] + 1 << '\n';
        }
    }
}