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

// Range Update Point Query
struct segment_range_update
{
    vli tree, lazy;
    int n;
    segment_range_update(int a)
    {
        n=a;
        tree.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }
    void build(int l, int r, int node, vli &v)
    {
        if(l>r)
            return;
        if(l==r){
            tree[node]=v[l];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        tree[node] = tree[node<<1] + tree[(node<<1)+1];
    }
    // i - j update range
    // l - r node range
    void update(int i, int j, int x, int l, int r, int node)
    {
        if(l>r || j<l || i>r)
            return;
        if(i<=l && r<=j){
            lazy[node]+=x;
            return;
        }
        int mid = l + r >> 1;
        update(i, j, x, l, mid, node<<1);
        update(i, j, x, mid+1, r, (node<<1)+1);
    }
    // point query at i
    lli query(int i, int l, int r, int node)
    {
        if(l>r || i<l || i>r)
            return 0;
        if(l==r)
            return tree[node]+lazy[node];
        int mid = l+r>>1;
        if(i<=mid)
            return lazy[node] + query(i, l, mid, node<<1);
        return lazy[node] + query(i, mid+1, r, (node<<1)+1);
    }
};


int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli v(n);
    FOR(i, n) cin>>v[i];
    
    vli ans(n), cnt(n+1, 0);
    vli pre(n+1, 0);
    FOR(i, n) pre[i+1]=pre[i]+i+1;

    segment_range_update tr(n+1);
    tr.build(0, n, 1, cnt);

    for(int i=n-1;i>=0;i--){
        int j = 1<<20;
        for(int r=19;r>=0;r--){
            int ch = j - (1<<r);
            if(ch > n) {
                j=ch;
                continue;
            }
            lli sum = tr.query(ch, 0, n, 1);
            if(pre[ch-1]-sum > v[i]) j=ch;

        }
        int z;
        for(z=j-1;cnt[z];z--);
        ans[i]=z, cnt[z]=1;
        tr.update(z+1, n, z, 0, n, 1);
    }
    debugA(ans);
}