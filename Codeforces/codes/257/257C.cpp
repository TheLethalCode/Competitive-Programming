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
    vector< pair< double, pa > > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].se.fi>>v[i].se.se;
        v[i].fi = atan2(v[i].se.se,v[i].se.fi);
    }
    sort(v.begin(),v.end());
    double ans=0,temp;
    for(int i=0;i<n-1;i++)
        ans=max(ans,v[i+1].fi-v[i].fi);

    ans=max(ans,2*acos(-1)-(v[n-1].fi-v[0].fi));
    
    cout<<fixed<<setprecision(7)<<360-ans*180/acos(-1);
}