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

void merge(vi &d, vi &a, vi &b)
{
    int x = a.size(), y = b.size();
    int i=0, j=0;
    while(i<x && j<y)
        if(a[i] < b[j])
            d.pb(a[i]), i++;
        else
            d.pb(b[j]), j++;
    while(i<x)
        d.pb(a[i]), i++;
    while(j<y)
        d.pb(b[j]), j++;
}

// No Modifications
struct merge_sort_tree
{
    vector< vi > tree;
    int n;
    merge_sort_tree(int a)
    {
        n=a;
        tree.resize(4*n);
    }
    void build(int l, int r, int node, vpal &v)
    {
        if(l>r)
            return;
        if(l==r)
        {
            tree[node].pb(v[l].se);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        merge(tree[node], tree[node<<1], tree[(node<<1)+1]);
    }
    // i - j  query range
    // l - r  node range
    int query(int k, int i, int j, int l, int r, int node, int ty)
    {
        // cout<<l<<" "<<r<<endl;
        if(l>r || r<i || l>j)
            return 0;
        if(l==r)
            return ty==1?(tree[node][0] <= k):(tree[node][0] >= k);
        if(i<=l && r<=j)
        {
            if(ty == 1)
            {
                auto pos = upper_bound(all(tree[node]), k);
                return pos-tree[node].begin();
            }
            else
            {
                auto pos = lower_bound(all(tree[node]), k);
                return (tree[node].end()-pos);
            }
        }
        int mid = l+r>>1;
        return query(k, i, j, l, mid, node<<1, ty) + query(k, i, j, mid+1, r, (node<<1)+1, ty);
    }
};

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vpal v(n);
    FOR(i, n) cin>>v[i].fi;
    FOR(i, n) cin>>v[i].se;
    sort(all(v));
    
    merge_sort_tree tr(n);
    tr.build(0, n-1, 1, v);
    
    lli ans = 0;
    for(int j=1;j<n;j++)
    {
        lli temp = tr.query(v[j].se , 0, j-1, 0, n-1, 1, 1);
        ans += temp*v[j].fi;
        // cout<<temp<<endl;
    }
    for(int i=0;i<n-1;i++)
    {
        lli temp = tr.query(v[i].se , i+1, n-1, 0, n-1, 1, -1);
        ans -= temp*v[i].fi;
    }
    cout<<ans<<endl;
}