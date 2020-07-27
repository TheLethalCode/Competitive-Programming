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
    lli m;
    cin>>n>>m;
    vli v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    lli ans=0,temp=0;
    int st=0,en=0;
    for(;en<n;en++)
    {
        temp+=v[en];
        if(temp>m)
        {
            ans=max(ans,temp-v[en]);
            while(temp > m)
                temp-=v[st],st++;
        }
    }
    ans=max(ans,temp);
    cout<<ans<<endl;
}