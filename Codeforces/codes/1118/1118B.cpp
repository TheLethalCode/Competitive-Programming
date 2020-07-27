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
    vector< pa > he(n+1,{0,0});
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        he[i].fi=he[i-1].fi;
        he[i].se=he[i-1].se;
        if(i%2)
            he[i].fi+=v[i-1];
        else
            he[i].se+=v[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(he[i-1].fi+he[n].se - he[i].se == he[i-1].se+he[n].fi - he[i].fi)
            ans++;
    }
    cout<<ans<<endl;
}