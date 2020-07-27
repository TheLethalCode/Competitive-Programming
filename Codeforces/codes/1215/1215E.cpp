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
#define MAXC 400005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
const int c=20, C = 1<<c;
int ar[MAXC], pref[MAXC][c+1];
lli W[c+1][c+1], dp[C+1];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    FOR(i, n){
        cin>>ar[i];
        ar[i]--;
        FOR(j, 20){
            pref[i+1][j] = pref[i][j];
        }
        pref[i+1][ar[i]]++;
    }
    for(int i=n-1; i; i--){
        FOR(j, 20){
            W[j][ar[i]] += pref[i][j];
        }
    }
    FOR(i, C){
        dp[i] = 1LL*mod*mod;
    }
    dp[0] = 0;
    for(int i=0; i < C; i++){
        for(int j=0; j<c ; j++){
            if(!(i&1<<j)){
                lli temp = dp[i];
                for(int k=0; k<c; k++){
                    if(i&1<<k){
                        temp += W[k][j];
                    }
                }
                dp[i|(1<<j)] = min(dp[i|(1<<j)], temp);
            }
        }
    }
    cout << dp[C-1] << "\n";
}