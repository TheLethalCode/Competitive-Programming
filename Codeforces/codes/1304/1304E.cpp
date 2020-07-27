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

// %
vi height;

struct node{
    lli val, num;
    bool dummy;
    node() : val(0), num(0), dummy(true) {}
    void init(lli v, lli n){
        val=v, num=n, dummy = false;
    }
    void update(lli x){
        val+=x; //Range min or max
        // val+=x*num // Range sum
    }
    node operator +(node r);
};

struct seg_tree{

    int n;
    vi lazy;
    vector< node > tr;

    seg_tree () {}
    void init(vi &v){
        n = v.size(), tr.resize(4*n);
        lazy.resize(4*n, 0);
        build(v, 0, n-1, 1);
    }
    void build( vi &v, int l, int r, int ind){
        if(l==r){
            tr[ind].init(v[l], r-l+1);
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1), build(v, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    void update(int x, int i, int j, int l, int r, int ind){
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind].update(lazy[ind]), lazy[ind]=0;
        }
        if(i>r || j<l || l>r) return;
        if(l>=i && r<=j){
            tr[ind].update(x);
            if(l!=r) lazy[ind<<1] += x, lazy[(ind<<1)+1] += x;
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1), update(x, i, j, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    node query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            node dum;
            return dum;
        }
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind].update(lazy[ind]), lazy[ind]=0;
        }
        if(l>=i && r<=j) return tr[ind];
        int mid=l+r>>1;
        node Lt = query1(i, j, l, mid, ind<<1), Rt = query1(i, j, mid+1, r, (ind<<1)+1);
        return Lt + Rt;
    }
    lli query(int i, int j){ return query1(i, j, 0, n-1, 1).val;}
    void upd(lli x, int i, int j){ update(x, i , j, 0, n-1, 1); }
};

node node::operator +(node r){
    if(r.dummy) return *(this);
    if(this->dummy) return r;
    node ans;
    ans.init(height[val]<height[r.val]?val:r.val, num+r.num);
    return ans;
}

struct LCA{
    int n;
    vi vis, first, euler, *ed;
    seg_tree sg;
    LCA(int _n, vi ted[], int root=1) {
        n = _n;
        vis.resize(n+1, 0), height.resize(n+1), first.resize(n+1);
        euler.reserve(2*n+1), ed = ted;
        dfs(root), sg.init(euler);
    }
    void dfs(int u, int h=0){
        vis[u]=1, height[u]=h;
        first[u] = euler.size(), euler.pb(u);
        for(int v : ed[u]){
            if(vis[v]) continue;
            vis[v] = 1, dfs(v, h+1); 
            euler.pb(u);
        }
    }
    int lca(int x, int y){
        int l = first[x], r = first[y];
        if(l>r) swap(l, r);
        return sg.query(l, r);
    }
};

int dis(int a, int b, LCA &lc){
    if(a==b) return 0;
    int r = lc.lca(a, b);
    return height[a] + height[b] - 2*height[r];
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin >> n;
    vi ed[n+1];
    FOR(i, n-1) {
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    LCA lc(n, ed);
    int q;
    cin>>q;
    while(q--){
        int x, y, a, b, k;
        cin>>x>>y>>a>>b>>k;
        int Dab= dis(a, b, lc);
        int Dax= dis(a, x, lc);
        int Dby= dis(b, y, lc), Daxyb= Dax+Dby+1;
        int Day= dis(a, y, lc);
        int Dbx= dis(b, x, lc), Dayxb= Day+Dbx+1;

        if(Dab <= k && (k-Dab)%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        if(Daxyb <= k && (k-Daxyb)%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        if(Dayxb <= k && (k-Dayxb)%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}