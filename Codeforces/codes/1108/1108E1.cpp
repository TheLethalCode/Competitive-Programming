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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %


struct node{
    lli mi, ma, num;
    bool dummy;
    node() : num(0), dummy(true) {}
    void init(lli x, lli y, lli n){
        ma=x, mi=y, num=n, dummy = false;
    }
    void update(lli x){
        mi+=x; //Range min or max
        ma+=x;
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
            tr[ind].init(v[l], v[l], r-l+1);
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1), build(v, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    void update(lli x, int i, int j, int l, int r, int ind){
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
    pal query(int i, int j){ node temp = query1(i, j, 0, n-1, 1); return {temp.mi, temp.ma};}
    void upd(lli x, int i, int j){ update(x, i , j, 0, n-1, 1); }
};
node node::operator +(node r){
    if(r.dummy) return *(this);
    if(this->dummy) return r;
    node ans;
    ans.init(max(ma, r.ma), min(mi, r.mi), num+r.num);
    return ans;
}

// build(array)
// update(val, start, end) 0 based
// query(start, end) 0 based
// change + operator, update function in node

int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    vi v(n);
    vpa ar(m);
    FOR(i, n) cin>>v[i];
    FOR(i, m) cin>>ar[i].fi>>ar[i].se, ar[i].fi--, ar[i].se--;
    seg_tree sg(v);
    pal temp = sg.query(0, n-1);
    int cur = temp.se - temp.fi;
    vi ans;
    FOR(i, n){
        vi temp;
        FOR(j, m) if(!(ar[j].fi <= i && ar[j].se >= i)) temp.pb(j);
        FORR(x, temp) sg.upd(-1, ar[x].fi, ar[x].se);
        pal qw = sg.query(0, n-1);
        if(cur < qw.se-qw.fi) cur = qw.se - qw.fi, ans = temp;
        FORR(x, temp) sg.upd(1, ar[x].fi, ar[x].se);
    }
    cout<<cur<<endl;
    cout<<sz(ans)<<endl;
    FORR(i, ans) cout<<i+1<<" ";
    cout<<endl;
}