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

struct data
{
    lli sum, pre,suf, masum;
    bool ch;
};

int n;
vli v;
vector< data > st;

void upgarde(int id)
{
    st[id].sum = st[id<<1].sum + st[(id<<1)+1].sum;
    st[id].pre = max(st[id<<1].pre,st[id<<1].sum + st[(id<<1)+1].pre);
    st[id].suf = max(st[(id<<1)+1].suf,st[(id<<1)+1].sum + st[(id<<1)].suf);
    st[id].masum = max(st[id<<1].masum,max(st[(id<<1)+1].masum,st[id<<1].suf + st[(id<<1)+1].pre));
    st[id].ch = false;
}

void build(int id=1,int i=0,int j=n-1)
{
    if(i==j)
        st[id] = {v[i],v[i],v[i],v[i],false};
    else
    {
        int mid = (i+j)/2;
        build(id<<1,i,mid);
        build((id<<1)+1,mid+1,j);
        upgarde(id);
    }
}

void update(lli pos,int l=0,int r=n-1,int id=1)
{
    if(l==r)
        st[id] = {v[l],v[l],v[l],v[l],false};
    else
    {
        int mid = l + r >> 1;
        if(pos<=mid)
            update(pos,l,mid,id<<1);
        else
            update(pos,mid+1,r,(id<<1)+1);
        upgarde(id);
    }
}

data query(int in,int en,int l=0,int r=n-1,int id=1)
{
    if(in > r || en < l)
        return {INT_MIN,INT_MIN,INT_MIN,INT_MIN,true};
    if(in <= l && r <= en)
        return st[id];
    int mid= l + r >> 1;
    data le = query(in,en,l,mid,id<<1),ri = query(in,en,mid+1,r,(id<<1)+1);
    if(le.ch)
        return ri;
    if(ri.ch)
        return le;
    return {le.sum + ri.sum,
            max(le.pre,le.sum + ri.pre),
            max(ri.suf,ri.sum + le.suf),
            max(le.masum,max(ri.masum,le.suf + ri.pre)),
            false};
}

int main()
{
    crap;
    cin>>n;
    st.resize(4*n);
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    build();
    int m;
    cin>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(!a)
            v[b-1]=c,update(b-1);
        else
            cout<<query(b-1,c-1).masum<<endl;
    }
}