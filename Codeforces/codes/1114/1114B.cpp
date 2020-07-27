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
    int n,m,k;
    cin>>n>>m>>k;
    vector< pa > v(n);
    vi has(n),val(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].fi;
        v[i].se=i;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<n;i++)
    {
        has[v[i].se]=i;
        val[v[i].se]=v[i].fi;
    }
    vi ans;
    int cnt=0;
    lli sum=0;
    for(int i=0;i<n;i++)
    {
        if(has[i]<m*k)
            cnt++,sum+=val[i];
        if(cnt == m)
            ans.push_back(i),cnt=0;
    }
    cout<<sum<<endl;
    for(int i=0;i<k-1;i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}