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

int sum(vi v)
{
    int su=0,n=v.size();
    for(int i=0;i<n;i++)
        su+=v[i];
    return abs(su);
}

int main()
{
    crap;
    int n,k;
    cin>>n>>k;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=0;
    for(int i=0;i<k;i++)
    {
        vi r;
        for(int j=0;j<n;j++)
        {
            if((abs(j-i))%k==0)
                continue;
            // cout<<i<<" "<<j<<endl;
            r.pb(v[j]);
        }
        ans=max(ans,sum(r));
    }
    cout<<ans<<endl;
}