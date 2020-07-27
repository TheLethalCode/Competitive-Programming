#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<lli,lli>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n;
vector< pa > s_t;

void update(lli x, int st,int en,int l=0,int r=n-1,int id=1)
{

    if(s_t[id].se)
    {
        s_t[id].fi += (r - l + 1) * s_t[id].se;
        if( l != r )
            s_t[id<<1].se += s_t[id].se , s_t[ (id << 1) + 1].se += s_t[id].se;
        s_t[id].se=0;
    }

    if(en < l || st > r)
        return;

    if(st <= l && en >= r)
    {
        s_t[id].fi += x * (r - l + 1);
        if( l != r)
            s_t[id<<1].se += x , s_t[ (id << 1) + 1].se += x;
        return;
    }

    int mid = (l+r)/2;
    update(x,st,en,l,mid,2*id);
    update(x,st,en,mid+1,r,(id<<1) + 1);
    s_t[id].fi = s_t[id << 1].fi + s_t[ (id << 1) + 1].fi;
}

lli query(int st, int en, int l=0,int r=n-1,int id=1)
{
    if(en < l || st > r)
        return 0;
    
    if(s_t[id].se)
    {
        s_t[id].fi += (r-l+1) * s_t[id].se;
        if( l != r)
            s_t[id<<1].se += s_t[id].se, s_t[( id<<1 ) + 1].se += s_t[id].se;
        s_t[id].se=0;
    }

    if(st <= l && en >= r)
        return s_t[id].fi;
        
    int mid = (l+r)/2;

    return query(st,en,l,mid,id << 1) + query(st,en,mid+1,r,(id << 1) + 1);
}

int main()
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>n>>c;
        s_t.clear();
        s_t.resize(4*n,{0,0});
        while(c--)
        {
            int a;
            cin>>a;
            if(a)
            {
                int p,q;
                cin>>p>>q;
                cout<<query(p-1,q-1)<<endl;
            }
            else
            {
                int p,q;
                lli v;
                cin>>p>>q>>v;
                update(v,p-1,q-1);
            }
        }
    }
}