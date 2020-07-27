#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

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

// No. of elements greater than k
// No Modifications
struct merge_sort_tree{

    vector< vi > tree;
    int n;
    merge_sort_tree(int a){
        n=a, tree.resize(4*n);
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
    // i - j  query range
    // l - r  node range
    // 1 -  greater than k
    // -1 - less than k
    int query(int k, int i, int j, int l, int r, int node, int ty){
        if(l>r || r<i || l>j) return 0;
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
        return query(k, i, j, l, mid, node<<1, ty) + query(k, i, j, mid+1, r, (node<<1)+1, ty);
    }
};

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    vi v(m), first(n+1, 1e9), ans(n+1, 0);
    vector< vi > occ(n+1);
    FOR(i, m) {
        cin>>v[i], occ[v[i]].pb(i);
        if(first[v[i]]==1e9) first[v[i]]=i;
    }
    FOR(i, n) occ[i+1].pb(m), ans[i+1]=i+1;
    
    ordered_set te;
    vi st(n);
    iota(st.begin(), st.end(), 1);
    sort(all(st), [&](int i, int j){
                        return first[i]<first[j];
                    });
    for(int i=0, cnt=0;i<n;i++){
        while(cnt<m && first[st[i]]==1e9)
            te.insert(-v[cnt]), cnt++;
        while(cnt<=first[st[i]] && cnt<m && first[st[i]]!=1e9)
            te.insert(-v[cnt]), cnt++;
        int val = te.order_of_key(-st[i]);
        ans[st[i]]=max(ans[st[i]], st[i]+val);
    }

    vi next(m);
    FOR(i, m){
        int pos = upper_bound(all(occ[v[i]]), i) - occ[v[i]].begin();
        next[i]=occ[v[i]][pos];
    }
    
    merge_sort_tree mt(m);
    mt.build(0, m-1, 1, next);
    FOR(i, n){
        if(occ[i+1].size()<2) continue;
        FOR(j, occ[i+1].size()-1){
            if(occ[i+1][j]+1==occ[i+1][j+1]) continue;
            int uq = mt.query(occ[i+1][j+1]-1, occ[i+1][j]+1, occ[i+1][j+1]-1, 0, m-1, 1, 1);
            ans[i+1]=max(ans[i+1], uq+1);
        }
    }

    FOR(i, n){
        if(occ[i+1].size()==1) cout<<i+1<<" ";
        else cout<<1<<" ";
        cout<<ans[i+1]<<endl;
    }
}