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
#define MAXC 500005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int ar[MAXC], L[MAXC], R[MAXC], S[MAXC], par[MAXC], root, l, n;
vector< int > ed[MAXC], up[MAXC];

int retrieve(int u, int k){
    for(int i=l; i>=0; i--){
        if(S[up[u][i]] < k){
            u = up[u][i];
        }
    }
    return u;
}

void dfs(int u, int p=0){
    up[u][0] = p;
    S[u] = 1;
    for(int i=1;i<=l;i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    FORR(v, ed[u]){
        dfs(v, u);
        S[u] += S[v];
    }
}

void calc(){
    vector< pair< int, int > > v;
    v.pb(mod, 0);
    l = ceil(log2(n))+1;
    R[0] = n; 
    up[0].assign(l+1, 0);
    for(int i=1;i<=n;i++){
        ed[i].clear();
        up[i].assign(l+1, 0);
        while(v.back().fi < ar[i]){
            R[v.back().se] = i;
            v.pop_back();
        }
        v.pb(ar[i], i);
    }
    v.clear();
    L[n] = 0;
    v.pb(mod, n);
    for(int i=n-1;i>=0;i--){
        while(v.back().fi < ar[i]){
            L[v.back().se] = i;
            v.pop_back();
        }
        v.pb(ar[i], i);
    }
    for(int i=1;i<n;i++){
        if(ar[L[i]] != ar[R[i]]){
            par[i] = ar[L[i]] < ar[R[i]] ? L[i] : R[i];
            ed[par[i]].pb(i);
        }
        else{
            root = i;
        }
    }
    dfs(root);
    S[0] = mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ar[0] = mod;
    for(int z=1; z<=t; z++){
        cout << "Case #" << z << ": ";
        int q;
        cin >> n >> q;
        FOR(i, n-1){
            cin >> ar[i+1];
        }
        ar[n] = mod; 
        calc();
        while(q--){
            int s, t, k, tree;
            cin >> s >> k;
            if(k == 1){
                cout << s << " ";
                continue;
            }
            t = s - (ar[s-1] < ar[s]); 
            k--;
            if(S[t] >= k){
                if(t < s){
                    cout << s - k << " "; 
                }
                else{
                    cout << s + k << " ";
                }
            }
            else{
                tree = retrieve(t, k);
                if(up[tree][0] > t){
                    cout << up[tree][0] + (k - S[tree]) << " ";
                }
                else{
                    cout << up[tree][0] - (k - S[tree]) + 1 << " ";
                }
            }
        }
        cout << '\n';
    }
}