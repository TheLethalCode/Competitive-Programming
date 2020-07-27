#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    lli n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v[26];
    FOR(i, n) v[s[i]-'a'].pb(i);
    vector< vli > dp(n+1, vli(n+1, 0));
    FOR(i, n+1) dp[i][1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++){
            int pos = lower_bound(all(v[j]), i) - v[j].begin();
            if(s[i]-'a' == j) pos++;
            if(pos == v[j].size()) continue;
            for(int k=1;k<=n;k++)
                dp[i][k] += dp[v[j][pos]][k-1];
        }
    }
    lli ans = 0;
    for(int j=n;j>=1;j--){
        FOR(i, 26){
            if(v[i].empty()) continue;
            lli temp = min(k, dp[v[i][0]][j]);
            k -= temp, ans += 1LL*(n-j)*temp;
            if(k==0){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    if(k>1) cout<<-1;
    else if(k) cout<<ans+n;
    else cout<<ans;
    cout<<endl;
}