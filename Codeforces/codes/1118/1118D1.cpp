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

int n,m;
vli sum;
vli v;

bool can(int ans)
{
    if(ans > n)
        return true;
    lli val=0;
    for(int i=0;i<n;i++)
        val+=max(v[i]-i/ans,0LL);
    if(val < m)
        return false;
    return true;
}

int main()
{
    crap;
    cin>>n>>m;
    v.resize(n);
    sum.resize(n+1,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.rbegin(),v.rend());
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+v[i];
    if(sum[n] < m)
        cout<<-1;
    else
    {
        int ans=1<<19;
        for(int i=18;i>=0;i--)
            if(can(ans - (1<<i)))
                ans-= (1<<i);
        cout<<ans<<endl;
    }
}