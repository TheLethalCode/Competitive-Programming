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
    int n,m;
    cin>>n>>m;
    vector< pair< int, double> > v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].fi>>v[i].se;
    vi l(n);
    vector<  int > a(n+1,1e9+5);
    a[0]=-1;
    for(int i=0;i<n;i++)
    {
        int it = upper_bound(a.begin(),a.end(),v[i].fi) - a.begin();
        l[i]=it;
        a[it]=v[i].fi;
    }
    int ans=n-*max_element(l.begin(),l.end());
    cout<<ans<<endl;
}