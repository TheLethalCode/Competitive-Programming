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
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n;
        vector< pa > v;
        r=n;
        for(int i=2;i<=sqrt(n);i++)
        {
            int cnt=0;
            while(r%i==0)
                cnt++,r/=i;
            if(cnt)
                v.push_back({i,cnt});
        }
        if(r!=1)
            v.push_back({r,1});
        int tt=1;
        for(auto r:v)
        {
            for(int i=0;i<r.se-1;i++)
                tt*=r.fi;
            tt*=r.fi-1;
        }
        cout<<tt<<endl;
    }
}