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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

void merge(vi &d, vi &a, vi &b){
    int x = a.size(), y = b.size();
    int i=0, j=0;
    while(i<x && j<y)
        if(a[i] < b[j]) d.pb(a[i]), i++;
        else d.pb(b[j]), j++;
    while(i<x) d.pb(a[i]), i++;
    while(j<y) d.pb(b[j]), j++;
}

struct merge_sort_tree{

    vector< vi > tree;
    int n;
    merge_sort_tree(vi &v){
        n=v.size(), tree.resize(4*n);
        build(0, n-1, 1, v);
    }
    void build(int l, int r, int node, vi &v){
        if(l>r) return;
        if(l==r){
            tree[node].pb(v[l]);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, node<<1, v), build(mid+1, r, (node<<1)+1, v);
        merge(tree[node], tree[node<<1], tree[(node<<1)+1]);
    }
    // 1 -  greater than k
    // -1 - less than k
    int query1(int k, int i, int j, int l, int r, int node, int ty){
        if(l>r || r<i || l>j || i>j) return 0;
        if(l==r) return ty==1?(tree[node][0] > k):(tree[node][0] < k);
        if(i<=l && r<=j){
            if(ty == 1){
                auto pos = upper_bound(all(tree[node]), k);
                return tree[node].end() - pos;
            }
            else{
                auto pos = lower_bound(all(tree[node]), k);
                return (pos - tree[node].begin()) + 1 - (*pos == k);
            }
        }
        int mid = l+r>>1;
        return query1(k, i, j, l, mid, node<<1, ty) + query1(k, i, j, mid+1, r, (node<<1)+1, ty);
    }
    int query(int x, int i, int j, int ty){
        return query1(x, i, j, 0, n-1, 1, ty);
    }
};

int main(int argc, char **argv)
{
    crap;
    int n, cnt=0;
    cin>>n;
    map< int, int > mp;
    map< int, vi > po;
    FOR(i, n) {
        int a, b;
        cin>>a>>b;
        if(mp.count(a)) mp[a]=max(mp[a], b);
        else mp[a] = b;
        po[b].pb(a);
    }
    vi last; 
    for(auto &el : mp) last.pb(el.se), el.se=cnt++;
    for(auto &el : po) el.se.pb(mod), sort(all(el.se));
    mp[mod]=cnt++;

    merge_sort_tree mg(last);
    lli ans = 0;
    for(auto y : po){
        int prev = -1;
        lli tot = y.se.size()-1, sub = 0;
        for(int x : y.se){
            lli z = mg.query(y.fi, prev+1, mp[x]-1, 1);
            sub += z*(z+1)/2, tot+=z, prev=mp[x];
        }
        ans += (tot*(tot+1))/2 - sub;
    }
    cout<<ans<<endl;
}