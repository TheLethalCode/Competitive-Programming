#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int n;
vi v;
vpa seg;

void build(int id=1, int l=0, int r=n-1)
{
    if(l == r)
    {
        seg[id].fi = v[l],seg[id].se=-1;
        return;
    }
    int mid = l + r >> 1;
    build(id<<1,l,mid);
    build((id<<1)+1,mid+1,r);
    seg[id].fi = max(seg[id<<1].fi,seg[(id<<1)+1].fi);
    seg[id].se = seg[id<<1].fi < seg[(id<<1)+1].fi ? max(seg[id<<1].fi,seg[(id<<1)+1].se) : max(seg[id<<1].se,seg[(id<<1)+1].fi); 
}

void update(int x, int i, int l=0,int r=n-1, int id=1)
{
    if(i < l || i > r )
        return;
    if(l==r)
    {
        v[i]+=x;
        seg[id].fi=v[i];
        return;
    }
    int mid = l + r >> 1;
    update(x,i,l,mid,id<<1);
    update(x,i,mid+1,r,(id<<1)+1);
    seg[id].fi = max(seg[id<<1].fi,seg[(id<<1)+1].fi);
    seg[id].se = seg[id<<1].fi < seg[(id<<1)+1].fi ? max(seg[id<<1].fi,seg[(id<<1)+1].se) : max(seg[id<<1].se,seg[(id<<1)+1].fi); 
}

pa query(int st,int en,int l=0,int r=n-1,int id =1)
{
    if(st > r || en < l)
        return {-1,-1};
    if(st <= l && r<= en)
        return seg[id];
    int mid = l + r >> 1;
    pa L = query(st,en,l,mid,id<<1), R = query(st,en,mid+1,r,(id<<1)+1);
    return {max(L.fi,R.fi), L.fi < R.fi ? max(L.fi,R.se) : max(L.se,R.fi)  };
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    v.resize(n);
    seg.resize(4*n);
    FOR(i,n) cin>>v[i];
    build();
    int q;
    cin>>q;
    while(q--)
    {
        char a;
        cin>>a;
        if(a=='Q')
        {
            int b,c;
            cin>>b>>c;
            pa ans=query(b-1,c-1);
            cout<<ans.fi+ans.se;nl;
        }
        else
        {
            int b,c;
            cin>>b>>c;
            update(c-v[b-1],b-1);
        }
    }
}