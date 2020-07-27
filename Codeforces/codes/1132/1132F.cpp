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
#define mp make_pair

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
    int n;
    cin>>n;
    string s;
    cin>>s;
    n = unique(all(s))-s.begin();
    int dp[n+1][n+1];
    FOR(i, n) dp[i+1][i+1]=1;
    for(int l=2;l<=n;l++){
        for(int i=1, j=i+l-1; j<=n; i++, j++){
            dp[i][j] = dp[i][j-1]+1;
            for(int k=i;k<j;k++) if(s[k-1]==s[j-1]) dp[i][j]=min(dp[i][j], dp[k+1][j-1]+dp[i][k]); 
        }
    }
    cout<<dp[1][n]<<endl;
}