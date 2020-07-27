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

class comp
{
    public:
    bool operator() (pa const &l,pa const &r)
    {
        if(l.fi == r.fi)
            return l.se<r.se;
        return l.fi < r.fi;
    }
};

int main()
{
    crap;
    int n,m;
    cin>>n>>m;
    vector< pa > d(n);
    vli a(n),c(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>d[i].fi;
        d[i].se=i;
        c[i]=d[i].fi;
    }
    sort(d.begin(),d.end(),comp());
    lli ans=0;
    int cnt=0;
    while(m--)
    {
        lli t,r;
        cin>>t>>r;
        if(a[t-1] >= r)
        {
            ans+=c[(t-1)]*r;
            a[t-1]-=r;
            r=0;
        }
        if(a[t-1] && r)
        {
            ans+=c[t-1]*a[t-1];
            r-=a[t-1];
            a[t-1]=0;
        }
        if(r && cnt<n)
        {
            while(r && cnt<n)
            {
                int val=min(r,a[d[cnt].se]);
                r-=val;
                ans+=c[d[cnt].se]*val;
                a[d[cnt].se]-=val;
                if(!a[d[cnt].se])
                    cnt++;
            }
        }
        if(r)
            ans=0;
        cout<<ans<<endl;
        ans=0;
    }    
}