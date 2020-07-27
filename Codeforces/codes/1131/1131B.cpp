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
    vector<pa> v,r(n);
    lli ans=0;
    for(int i=0;i<n;i++)
        cin>>r[i].fi>>r[i].se;
    v.push_back({0,0});
    for(int i=0;i<n;i++)
    {
        if(v.back()!=r[i])
            v.push_back(r[i]);
    }
    n=v.size();
    ans+=(n==1);
    vector< pa > temp;
    for(int i=1;i<n;i++)
    {
        if(min(v[i].fi,v[i].se)-max(v[i-1].se,v[i-1].fi) >= 0)
            temp.push_back({min(v[i].fi,v[i].se),max(v[i-1].se,v[i-1].fi)});
    }
    n=temp.size();
    for(int i=0;i<n;i++)
    {
        ans+=temp[i].fi - temp[i].se;
        if(!i || temp[i].se != temp[i-1].fi)
            ans++;
    }
    cout<<ans<<endl;
}