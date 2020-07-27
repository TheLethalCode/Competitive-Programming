#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
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
    map<int, int> la;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v[i]=a;
        la[a]=i;
    }
    lli ans=1;
    for(int i=0;i<n;i++)
    {
        if(i)
            ans*=2,ans%=mod;
        int las=la[v[i]], j=i+1;
        while(j<=las)
        {
            las=max(las,la[v[j]]);
            j++;
        }
        i=las;
    }
    cout<<ans;
}