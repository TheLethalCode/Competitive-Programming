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

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

struct segment
{
    vi tree;
    int n;
    segment(int a)
    {
        n=a;
        tree.resize(4*n, 0);
    }
    void build(int l, int r, int node, vi &v)
    {
        if(l>r)
            return;
        if(l==r)
        {
            tree[node]=v[l];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        tree[node] = tree[node<<1] + tree[(node<<1)+1];
    }
    void update(int i, int x, int l, int r, int node)
    {
        if(l>r || i<l || i>r)
            return;
        if(l==r)
        {
            tree[node]+=x;
            return;
        }
        int mid = l + r >> 1;
        update(i, x, l, mid, node<<1), update(i, x, mid+1, r, (node<<1)+1);
        tree[node] = tree[node<<1] + tree[(node<<1)+1];
    }
    int query(int k, int l, int r, int node)
    {
        if(l>r || tree[node] < k)
            return -1;
        if(l==r)
            return l;
        int mid = l+r>>1;
        if(tree[node<<1]>=k)
            return query(k, l, mid, node<<1);
        return query(k-tree[node<<1], mid+1, r, (node<<1)+1);
    }
};

int main(int argc, char **argv)
{
    crap;
    int n,q;
    cin>>n>>q;
    segment tr(n);
    vi v(n,0);
    FOR(i, n) {
        int a;
        cin>>a;
        v[a-1]++;
    }
    tr.build(0, n-1, 1, v);
    while(q--)
    {
        int k;
        cin>>k;
        if(k > 0)
            tr.update(k-1, 1, 0, n-1, 1), v[k-1]++;
        else
        {
            k = abs(k);
            int w = tr.query(k, 0, n-1, 1);
            v[w]--, tr.update(w, -1, 0, n-1, 1);
            // cout<<w+1<<endl;
        }
    }
    int fl=0;
    for(int i=0;i<n & !fl;i++)
        if(v[i])
            fl=i+1;
    cout<<fl<<endl;
}