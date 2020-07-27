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

struct compa
{
    bool operator ()(pa const& a, pa const& b) const
    {
        if(a.fi == b.fi)
            return a.se < b.se;
        return a.fi < b.fi;
    }
};

bool isvalid(int i,int j)
{
    if(i<=0 || j<=0)
        return false;
    if(i>1e9 || j>1e9)
        return false;
    return true;
}

int main()
{
    crap;
    pa st,en;
    cin>>st.fi>>st.se>>en.fi>>en.se;
    int n;
    set < pa , compa > v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        for(int j=y;j<=z;j++)
            v.insert(mp(x,j));
    }
    queue< pair < pa, int > > pq;
    v.erase(st);
    pq.push(mp(st,0));
    int fl=1;
    while(!pq.empty() && fl)
    {
        pair< pa , int > te = pq.front();
        pq.pop();
        for(int i=te.fi.fi-1;i<=te.fi.fi+1 && fl;i++)
        {
            for(int j=te.fi.se-1;j<=te.fi.se+1 && fl;j++)
            {
                if( !v.erase(mp(i,j)) || !isvalid(i,j))
                    continue;
                pq.push(mp(mp(i,j),te.se+1));
                if(i==en.fi && j==en.se)
                {
                    cout<<te.se+1<<endl;
                    fl=0;
                }
            }
        }
    }
    if(fl)
        cout<<-1<<endl;
}