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
    vector< vli > v(n,vli(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    
    vli s(n),ans;
    for(int i=0;i<n;i++)
    {
        lli a;
        cin>>a;
        s[i]=a-1;
    }
    reverse(s.begin(),s.end());

    ans.pb(0);
    for(int k=0;k<n;k++)
    {
        lli su=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[s[i]][s[j]]=min(v[s[i]][s[j]],v[s[i]][s[k]]+v[s[k]][s[j]]);
                su+= (i<=k && j<=k)? v[s[i]][s[j]]:0;
            }
        }
        ans.pb(su);
    }
    reverse(ans.begin(),ans.end());

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}