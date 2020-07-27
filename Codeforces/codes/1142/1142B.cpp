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
// #define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int n, m, q;
vi p, v, nex, bef, sh;
int fina(int x){
    if(x < 0 || v[x]==p[n-1]) return x;
    return nex[x]=fina(nex[x]);
}
int begi(int x){
    if(x<0 || v[x]==p[0]) return x;
    return bef[x]=begi(bef[x]);
}

void pre(){
    p.resize(n), v.resize(m);
    nex.resize(m, -1);
    bef.resize(m, -1), sh.resize(m, -1);
}


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
                return (pos - tree[node].begin()) ;
            }
        }
        int mid = l+r>>1;
        return query1(k, i, j, l, mid, node<<1, ty) + query1(k, i, j, mid+1, r, (node<<1)+1, ty);
    }
    int query(int x, int i, int j, int ty){	return query1(x, i, j, 0, n-1, 1, ty);}
};

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>q;
    pre();
    vi pos[n+1], ans(m, 1e9);
    FOR(i, n) cin>>p[i];
    FOR(i, m) cin>>v[i], pos[v[i]].pb(i);
    FOR(i, n-1) {
        for(int po : pos[p[i]]) {
            auto ch = lower_bound(all(pos[p[i+1]]), po);
            if(ch != pos[p[i+1]].end()) nex[po]=*ch;
        }
        for(int po : pos[p[i+1]]){
            int ch = lower_bound(all(pos[p[i]]), po) - pos[p[i]].begin();
            if(ch) bef[po]=pos[p[i]][ch-1];
        }
    }
    FOR(i, m) nex[i]=fina(i), bef[i]=begi(i);
    vpa mp[n+1];
    for(int i=m-1;i>=0;i--) if(bef[i]!=-1) mp[v[i]].pb({bef[i], i});
    FOR(i, n) sort(all(mp[i+1]));
    FOR(i, n){
        for(int el : pos[p[i]]) {
            if(nex[el]==-1) break;
            if(!i) ans[el]=nex[el];
            else {
                auto ch = lower_bound(all(mp[p[i-1]]), make_pair(nex[el], 0));
                if(ch != mp[p[i-1]].end()) ans[el]=ch->se;
            }
        }
    }
    merge_sort_tree mg(ans);
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<(mg.query(b, a-1, b-1, -1)?1:0);
    }
    cout<<endl;
}