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
    int t;
    cin>>t;
    while(t--)
    {
        int h,w;
        cin>>h>>w;
        int val[h][w];
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                cin>>val[i][j];
        
        int dp[h][w];
        for(int i=0;i<w;i++)
            dp[0][i] = val[0][i];
        
        for(int i=1;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(!j)
                    dp[i][j]=max(dp[i-1][j],(w>1)?dp[i-1][j+1]:0) + val[i][j];
                else if(j==w-1)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]) + val[i][j];
                else
                    dp[i][j]=max(max(dp[i-1][j],dp[i-1][j+1]),dp[i-1][j-1]) + val[i][j];
            }
        }
        cout<<*max_element(dp[h-1],dp[h-1]+w)<<endl;
    }
}