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
    vi v(3,0);
    while(n--)
    {
        string s;
        cin>>s;
        if(s=="1/4")
            v[0]++;
        else if(s=="1/2")
            v[1]++;
        else
            v[2]++;
    }
    int a=min(v[0],v[2]),ans=0;
    
    v[0]-=a,v[2]-=a;
    ans+=a;

    ans+=v[1]/2,v[1]%=2;

    ans+=v[2],v[2]=0;

    ans+=v[0]/4,v[0]%=4;

    if(v[1])
        ans++,v[1]=0,v[0]=max(v[0]-2,0);
    if(v[0])
        ans++,v[0]=0;
    cout<<ans+1<<endl;
}