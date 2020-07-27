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

int n;

bool comp(pair< pa,int> lhs, pair< pa,int> rhs)
{
    if((int)(lhs.fi.fi / sqrt(n)) == (int)(rhs.fi.fi / sqrt(n)))
        return lhs.fi.se < rhs.fi.se;
    
    return (int)(lhs.fi.fi / sqrt(n)) < (int)(rhs.fi.fi / sqrt(n));
}

int main()
{
    crap;
    cin>>n;
    vi v(n),a(1e6+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int q;
    cin>>q;
    vector< pair< pa,int> > Q(q);
    for(int i=0;i<q;i++)
    {
        cin>>Q[i].fi.fi>>Q[i].fi.se;
        Q[i].fi.fi--;Q[i].fi.se--;
        Q[i].se=i;
    }
    sort(Q.begin(),Q.end(),comp);
    int ans=0,l=-1,r=-1;
    vi we(q);
    for(auto te:Q)
    {
        while(l < te.fi.fi)
        {
            a[v[l]]--;
            if(a[v[l]]==0)
                ans--;
            l++;
        }
        while(l > te.fi.fi)
        {
            a[v[--l]]++;
            if(a[v[l]]==1)
                ans++;
        }
        while(r < te.fi.se)
        {
            a[v[++r]]++;
            if(a[v[r]]==1)
                ans++;
        }
        while(r > te.fi.se)
        {
            a[v[r]]--;
            if(a[v[r]]==0)
                ans--;
            r--;
        }
        we[te.se]=ans;
    }
    for(auto r:we)
        cout<<r<<"\n";
}