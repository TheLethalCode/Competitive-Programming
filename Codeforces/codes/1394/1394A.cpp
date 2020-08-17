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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector< int > V[2];
    vector< lli > pref[2];
    FOR(i, n){
        int x;
        cin >> x;
        V[x > m].pb(x);
    }
    FOR(i, 2){
        sort(V[i].rbegin(), V[i].rend());
        pref[i].resize(V[i].size());
        FOR(j, V[i].size()){
            pref[i][j] = V[i][j];
            if(j > 0){
                pref[i][j] += pref[i][j-1];
            }
        }
    }
    lli ans = 0;
    for(int i=1;i<=V[1].size();i++){
       if((i-1)*(d+1) >= n){
           break;
       }
       int j = n-1-(i-1)*(d+1);
       lli temp = pref[1][i-1];
       if(V[0].size() && j){
           temp += pref[0][min(j-1, (int)V[0].size()-1)];
       }
       ans = max(ans, temp);
    }
    if(V[1].empty()){
        ans = max(ans, pref[0].back());
    }
    cout << ans << '\n';
}