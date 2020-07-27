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
        int n;
        cin>>n;
        vector< pair< pa,int> > v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].fi.fi>>v[i].fi.se;
            v[i].se=i;
        }
        sort(v.begin(),v.end());
        int fl=-1,ma=v[0].fi.se;
        for(int i=1;i<n;i++)
        {
            if(v[i].fi.fi > ma)
            {
                fl=i;
                break;
            }
            ma=max(ma,v[i].fi.se);
        }
        if(fl==-1)
            cout<<-1;
        else
        {
            vi ans(n,2);
            for(int i=0;i<fl;i++)
                ans[v[i].se]=1;
            for(int i=0;i<n;i++)
                cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}