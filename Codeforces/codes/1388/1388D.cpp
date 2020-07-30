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
lli n, t, fin, A[MAXC], B[MAXC], V[MAXC], T[MAXC];
vector< int > to[MAXC], ans[MAXC];

void dfs(int u){
    V[u] = 1;
    FORR(v, to[u]){
        if(!V[v]){
            dfs(v);
        }
        if(A[v] > 0){
            A[u] += A[v];
            ans[v].pb(u);
        }
        else{
            ans[u].pb(v);
        }
    }
    fin += A[u];
}

void dfs1(int u){
    T[u] = 1;
    t++;
    FORR(v, ans[u]){
        if(!T[v]){
            dfs1(v);
        }
    }
    T[u] = t++;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> A[i+1];
    }
    FOR(i, n){
        cin >> B[i+1];
        if(B[i+1] != -1){
            to[B[i+1]].pb(i+1);
        }
    }
    FOR(i, n){
        if(!V[i+1]){
            dfs(i+1);
        }
    }
    FOR(i, n){
        if(!T[i+1]){
            dfs1(i+1);
        }
    }
    vector< int > ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return T[i] > T[j];
    });
    cout << fin << '\n';
    FORR(i, ord){
        cout << i << ' ';
    }
    cout << '\n';
}