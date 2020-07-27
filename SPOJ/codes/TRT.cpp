#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int dp[n+1][n+1];
    for(int j=1;j<=n;j++)
        for(int i=0;i<n-j+1;i++)
        {
            if(j == 1)
                dp[i][i+j-1] = n*v[i];
            else
            {
                int en=i+j-1;
                dp[i][en] = max( dp[i][en-1] + ( n - j + 1)*v[en], dp[i+1][en] + ( n - j + 1)*v[i] );
            }
        }
    cout<<dp[0][n-1]<<endl;
}