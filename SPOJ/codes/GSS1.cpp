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
vi v;

struct data
{
    int sum, pre,suf,tot;
    bool ch;
};

vector< data > st;

void build(int l=0,int r=n-1,int id=1)
{
    if(l==r)
    {
        st[id].sum=st[id].pre=st[id].suf=st[id].tot=v[l];
        st[id].ch = false;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    st[id].pre=max(st[2*id].pre,st[2*id].sum+st[2*id+1].pre);
    st[id].suf=max(st[2*id+1].suf,st[2*id+1].sum+st[2*id].suf);
    st[id].tot=max(max(st[2*id].tot,st[2*id+1].tot),st[2*id].suf+st[2*id+1].pre);
    st[id].sum=st[2*id].sum + st[2*id+1].sum;
    st[id].ch = false;
}

data val(int x,int y,int l=0, int r=n-1,int id=1)
{
    if(x > r || y < l) return {INT_MIN,INT_MIN,INT_MIN,INT_MIN,true};
    if(x <= l && y >= r)
        return st[id];
    int mid=(l+r)/2;
    data le=val(x,y,l,mid,2*id), ri=val(x,y,mid+1,r,2*id+1);
    if(le.ch)
        return ri;
    if(ri.ch)
        return le;
    data te= { le.sum+ri.sum, max(le.pre,le.sum+ri.pre),max(ri.suf,ri.sum+le.suf),max(max(le.tot,ri.tot),le.suf+ri.pre)};
    return te;
}

int main()
{
    crap;
    cin>>n;
    v.resize(n);
    st.resize(4*n+1);
    for(int i=0;i<n;i++)
        cin>>v[i];
    build();
    int m;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<val(a-1,b-1).tot<<endl;
    }
}