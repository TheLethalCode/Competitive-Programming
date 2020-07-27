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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)


struct node{
    lli val, num;
    bool dummy;
    node() : val(0), num(0), dummy(true) {}
    void init(lli v, lli n){
        val=v, num=n, dummy = false;
    }
    void update(lli x){
        val+=x; //Range min or max
        // val+=x*num; // Range sum
    }
    node operator +(node r);
};

struct seg_tree{

    int n;
    vi lazy;
    vector< node > tr;

    seg_tree(vi &v){
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
        if(i>r || j<l || l>r || i>j) return;
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
    ans.init(min(val, r.val), num+r.num);
    return ans;
}

// build(array)
// update(val, start, end) 0 based
// query(start, end) 0 based
// change + operator, update function in node

int n, m, k, fl=0, a[5010], b[5010]={}, c[5010], p[5010];
// %
int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>k;
    FOR(i, n) cin>>a[i+1]>>b[i+1]>>c[i+1], p[i+1]=i+1;
    FOR(i, m) {
        int a, b;
        cin>>a>>b;
        p[b]=max(p[b], a);
    }
    
    vi req(n+2, 0), ord(n), ext(n+1);
    for(int i=n;i>0;i--){
        req[i] = max(a[i], req[i+1]-b[i]);
    }
    if(req[1] > k){
        cout<<-1<<endl;
        return 0;
    }

    int cur = k, ans = 0;
    FOR(i, n+1){
        ext[i]=cur+b[i]-req[i+1];
        cur += b[i];
    }
    iota(all(ord), 1), sort(all(ord), [&](int i, int j){ return c[i]>c[j]; });
    
    seg_tree sg(ext);
    FORR(x, ord){
        if(!sg.query(p[x], n)) continue;
        ans += c[x];
        sg.upd(-1, p[x], n);
    }
    cout<<ans<<endl;
}