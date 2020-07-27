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
    for(int i=0;i < n; i++)
        cin>>v[i];
    
    int ans=0,la=v[0],laf=1,las=0,sh=0;
    for(int i=1;i<n;i++)
    {
        if(v[i] == la)
        {
            laf++;
        }
        else
        {
            ans=max(ans,2*min(laf,las));
            las=laf;
            laf=1;
            la=v[i];
        }
    }
    ans=max(ans,2*min(laf,las));
    cout<<ans<<endl;
    
}