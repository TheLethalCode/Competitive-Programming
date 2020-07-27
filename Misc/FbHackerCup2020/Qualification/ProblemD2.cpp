#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 1000005
// %

int n, m, a, b, i, l, t, q, ok, cnt, V[MAXC];
lli k, r, x, y, z, ans;
string s, c;
vector< int > to[MAXC];
vector< lli > dp;

struct data{
    
    lli x, lazyVal;
    bool exist, lazy;

    data(): exist(false) {} 
    data(lli v) : x(v), exist(true), lazy(false) {}
    // Node combination
    data operator+(data r){
        if(!r.exist) return *this;
        if(!this->exist) return r;
        data ans(min(x, r.x));
        return ans;
    }
    // Lazy updation
    void upd(){
        x += lazyVal;
        lazy = false;
    }
};

struct seg_tree{
    int n;
    vector< data > tr;
    seg_tree() {}
    void init(vector< lli > &v){
        n = v.size();
        tr.clear();
        tr.resize(4*n, data(0));
        build(v, 0, n-1, 1);
    }
    // Lazy propagaton
    void pushdown(int ind, int l, int r){
        if(tr[ind].lazy){
            if(l!=r){
                tr[ind<<1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1|1].lazyVal += tr[ind].lazyVal;
                tr[ind<<1].lazy = tr[ind<<1|1].lazy = true;
            }
            tr[ind].upd();
        }
    }
    void build( vector< lli > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].x = v[l];
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1);
        build(v, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    void update(lli x, int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i>r || j<l || l>r || i>j){
            return;
        }
        if(l>=i && r<=j){
            tr[ind].lazy = true;
            tr[ind].lazyVal = x;
            pushdown(ind, l, r);
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1);
        update(x, i, j, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    data query1(int i, int j, int l, int r, int ind){
        pushdown(ind, l, r);
        if(i>r || j<l || l>r){
            return data();
        }
        if(l>=i && r<=j){
            return tr[ind];
        }
        int mid=l+r>>1;
        return query1(i, j, l, mid, ind<<1) + query1(i, j, mid+1, r, ind<<1|1);
    }
    lli query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.x;
    }
    void upd(lli x, int i, int j){ update(x, i , j, 0, n-1, 1); }
}sg;

vector< int > bfs(){
    vector< int > par(n+1, -1);
    queue< int > q;
    q.push(b);
    par[b]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == a){
            vector< int > path;
            while(u){
                path.pb(u);
                u = par[u];
            }
            return path;
        }
        FORR(v, to[u]){
            if(par[v] == -1){
                q.push(v);
                par[v] = u;
            }
        }
    }
}

void dfs(int u, int dis, int p1 = 0, int p2 = 0){
    if(V[u]){
        lli temp = sg.query(i+1, min(l-1, i+m-dis)) + V[u];
        if(dp[i+dis] > temp){
            sg.upd(temp - dp[i+dis], i+dis, i+dis);
            dp[i+dis] = temp;
        }
    }
    if(dis < m && dis+i+1 < l){
        FORR(v, to[u]){
            if(v != p1 && v!=p2){
                dfs(v, dis+1, u);
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(q=1;q<=t;q++){
        cin >> n >> m >> a >> b;
        FOR(i, n){
            to[i+1].clear();
        }
        FOR(i, n){
            cin >> x >> V[i+1];
            if(x){
                to[i+1].pb(x);
                to[x].pb(i+1);
            }
        }
        vector< int > path = bfs();
        l = path.size();
        dp.assign(l, 1e18);
        dp[l-1] = 0;
        sg.init(dp);
        for(i = l-2;i;i--){
            dfs(path[i], 0, path[i+1], path[i-1]);
        }
        ans = sg.query(1, min(m, l-1));
        if(ans > 1e15){
            ans = -1;
        }
        cout << "Case #" << q << ": " << ans << endl;
    }
}