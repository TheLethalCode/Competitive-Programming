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
lli a1 = 1, a2 = 6, a3 = 32*27*5*7, ar[101];
vector< int > ed[101];

void dfs(int u, int p = -1, int c = 0){
    ar[u] = c?c==1?a2:a3:a1;
    FORR(v, ed[u]){
        if(v != p){
            dfs(v, u, (c+1)%3);
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector< int > prime(100, 1);
    prime[1] = prime[0] = 0;
    for(int i=2;i<100;i++){
        if(prime[i]){
            for(int j=2*i;j<100;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i=2;i < 50;i++){
        if(prime[i]){
            a1 *= i;
        }
    }
    for(int i=50; i<90;i++){
        if(prime[i]){
            a2 *= i;
        }
    }
    for(int i=90; i<100;i++){
        if(prime[i]){
            a3 *= i;
        }
    }
    while(t--){
        int n;
        cin >> n;
        FOR(i, n){
            ed[i+1].clear();
        }
        FOR(i, n-1){
            int a, b;
            cin >> a >> b;
            ed[a].pb(b);
            ed[b].pb(a);
        }
        dfs(1);
        FOR(i, n){
            cout << ar[i+1] << " ";
        }
        cout << '\n';
    }
}