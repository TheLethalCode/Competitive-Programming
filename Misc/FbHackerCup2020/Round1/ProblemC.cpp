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
#define MAXC 1000005
// %
vector< int > to[MAXC];
int par[MAXC], siz[MAXC], cnt1[MAXC], cnt2[MAXC], S[MAXC];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) {
        return false;
    }
    if (x > y) {
        swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return true;
}

void dfs(int u, int p, const int& C1, const int& C2, int tC1, int tC2, lli& B) {
    cnt1[u] += (siz[u] == C1);
    cnt2[u] += (siz[u] == C2);
    FORR (v, to[u]) {
        if (v != p) {
            dfs(v, u, C1, C2, tC1, tC2, B);
            cnt1[u] += cnt1[v];
            cnt2[u] += cnt2[v];
        }
    }
    B += 1LL * cnt1[u] * (tC2 - cnt2[u]);
    if (C1 != C2) {
        B += 1LL * cnt2[u] * (tC1 - cnt1[u]);
    }
}

void dfs2(int u, int p, int cn1, int cn2, lli &B, int tr) {
    S[u] = 1;
    cnt1[u] += (siz[u] == 1);
    FORR (v, to[u]) {
        if (v != p) {
            dfs2(v, u, cn1, cn2, B, siz[u] & siz[v]);
            cnt1[u] += cnt1[v];
            S[u] += S[v];
        }
    }
    if (!tr) {
        B += 1LL * (cn1 + cn2 - S[u]) * S[u];
    } else {
        B += 1LL * (cn1 - cnt1[u]) * cnt1[u];
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        FOR (i, n) {
            to[i+1].clear();
            par[i+1] = i+1;
            siz[i+1] = (s[i] == '*');
            cnt1[i+1] = cnt2[i+1] = S[i+1] = 0;
        }
        vector< int > E(n+1);
        for (int i = 2; i <= k + 1; i++) {
            cin >> E[i];
            if (s[E[i]-1] == '*' && s[i-1] == '*') {
                merge(i, E[i]);
            }
        }
        lli a, b, c;
        cin >> a >> b >> c;
        for (int i = k+2; i <= n; i++) {
            E[i] = (a*E[i-2] + b*E[i-1] + c) % (i-1) + 1;
            if (s[E[i]-1] == '*' && s[i-1] == '*') {
                merge(i, E[i]);
            }
        }
        map < int, int, greater< int > > F;
        for (int i = 1; i <= n; i++) {
            int x = get(i);
            if (x == i) {
                F[siz[i]]++;
            }
        }
        int C1 = -1, C2 = -1;
        lli A = 0, B = 0;
        FORR (c, F) {
            if (C2 == -1) {
                if (C1 != -1) {
                    C2 = c.fi;
                } else if (c.se >= 2) {
                    C1 = C2 = c.fi;
                } else {
                    C1 = c.fi;
                }   
            }
            A += 1LL * c.fi * (c.fi - 1) / 2 * c.se;
        } 
        if (C2 != -1 && C2) {
            A += 1LL * C1 * C2;
            for (int i = 2; i <= n; i++) {
                int x = get(i), y = get(E[i]);
                if (x != y) {
                    to[x].pb(y);
                    to[y].pb(x);
                }
            }
            dfs(1, -1, C1, C2, F[C1], F[C2], B);
            B *= 1LL * C1 * C2;
        } else {
            F.clear();
            for (int  i = 1; i <= n; i++) {
                if (i > 1) {
                    to[i].pb(E[i]);
                    to[E[i]].pb(i);
                }
                siz[i] = C1? s[i-1]=='*': 1;
                F[siz[i]]++;
            }
            if (!C1){
                C1 = C2 = 1;
                dfs(1, -1, C1, C2, F[C1], F[C2], B);
            } else {
                dfs2(1, -1, F[1], F[0], B, 0);
            }
        }
        cout << "Case #" << z << ": " << A << ' ' << B << '\n';
    }
}