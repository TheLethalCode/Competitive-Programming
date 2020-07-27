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
    vi v(1e5+1,0),arr(n),dp(1e5+1,1),ch(1e5+1,0);
    vector< vi > ans(1e5+1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        v[arr[i]]=1;
    }
    for(int i=2;i<=1e5;i++)
    {
        if(!ch[i])
        {
            int prev;
            prev = v[i]?i:-1;
            for(int j=2*i;j<=1e5;j+=i)
            {
                ch[j]=1;
                if(!v[j])
                    continue;
                if(prev!=-1)
                    ans[j].pb(prev);
                prev=j;
            }
        }
    }
    // for(int i=2;i<=10;i++)
    //     cout<<i<<"="<<ans[i]<<endl;
    // cout<<endl;
    for(int a:arr)
    {
        for(int x:ans[a])
            dp[a]=max(dp[a],dp[x]+1);
    }
    // for(int i=1;i<=10;i++)
    //     cout<<dp[i]<<" ";
    cout<<*max_element(dp.begin(),dp.end());
}