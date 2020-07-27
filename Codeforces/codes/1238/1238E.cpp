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

int W[21][21];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    n = unique(s.begin(), s.end()) - s.begin();
    if(n == 1){
        cout << 0 << "\n";
        return 0; 
    }
    FOR(i, m+1){
        FOR(j, m+1){
            W[i][j] = 0;
        }
    }
    FOR(i, n-1){
        W[s[i]-'a'][s[i+1]-'a']++;
        W[s[i+1]-'a'][s[i]-'a']++;
    }
    int M = 1<<m, dp[M+1], cnt[M+1]={};
    FOR(i, M){
        dp[i] = 1e9;
        cnt[i+1] = 1 + cnt[i&(i+1)];
    }
    dp[0] = 0;
    FOR(i, M){
        FOR(j, m){
            if(!(i&(1<<j))){
                int temp = dp[i];
                FOR(k, m){
                    temp += ((i&(1<<k))?W[j][k]:-W[j][k]) * cnt[i];
                }
                dp[i|(1<<j)] = min(dp[i|(1<<j)], temp);
            }
        }
    }
    cout << dp[M-1] << "\n";
}