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
    cin>>n>>k>>m;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    double ans=0;
    double sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=v[i];
        if(m>=i) ans=max(ans,(sum+min((lli)(n-i)*k,(lli)(m-i)))*1.0/(n-i));
    }
    cout<<fixed<<setprecision(7)<<ans<<endl;    
}