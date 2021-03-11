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
#define MAXC 200005
// %

int F[27];
void dfs(int u, int p, vector< int > &S, vector< vector< int > > &E) {
    for (int v : E[u]) {
        if (v != p) {
            dfs(v, u, S, E);
            S[u] += S[v];
        }
    }
}

void dfs1(int u, int p, int l, vector< vector< int > > &E, vector< int > &A) {
    A[u] = 1;
    for (int v : E[u]) {
        if (v != p && v != l) {
            dfs1(v, u, l, E, A);
        }
    }
}

bool fib(vector< vector< int > > &E, int w) {
    int n = E.size();
    if (n <= 3) {
        return true;
    }
    
    vector< int > S(n, 1);
    int temp = -1;
    dfs(0, -1, S, E);
    for (int i = 0; i < n; i++) {
        if (S[i] == F[w-2] || S[i] == F[w-1]) {
            temp = i;
            break;
        }
    }

    if (temp == -1) {
        return false;
    } else {
        vector< int > A(n);
        dfs1(0, -1, temp, E, A);
        
        vector< int > to(n);
        for (int i = 0, z=0, o=0; i < n; i++) {
            if (A[i]) {
                to[i] = o++;
            } else {
                to[i] = z++;
            }
        }

        vector< vector< int > > E1(F[w-1]), E2(F[w-2]);
        for (int i = 0; i < n; i++) {
            for (int u : E[i]) {
                if (A[u] == A[i]) {
                    ((A[i] == 1) ^ (S[temp] == F[w-1]) ? E1 : E2)[to[i]].pb(to[u]);
                }
            }
        }
        return fib(E1, w-1) && fib(E2, w-2);
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    F[0] = F[1] = 1;
    for (int i = 2; i < 27; i++) {
        F[i] = F[i-1] + F[i-2];
    }

    int n, whi = 0;
    cin >> n;
    vector< vector< int > > E(n);

    while (whi < 27 && F[whi] < n) {
        whi++;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u-1].pb(v-1);
        E[v-1].pb(u-1);
    }

    if (whi >= 27 || F[whi] != n) {
        cout << "No\n";
        return 0;
    }

    cout << (fib(E, whi) ? "Yes\n" : "No\n");
}