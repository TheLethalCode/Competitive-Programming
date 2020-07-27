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

#define perc %
#define MAXC 200000


struct node{
    lli val, num, ind;
    bool dummy;
    node() : val(0), num(0), dummy(true) {}
    void init(lli v, lli i, lli n){
        ind = i, val=v, num=n, dummy = false;
    }
    void update(lli x){
        val+=x; //Range min or max
        // val+=x*num; // Range sum
    }
    node operator +(node r);
};

struct seg_tree{

    int n;
    vli lazy;
    vector< node > tr;

    seg_tree(vli &v){
        n = v.size(), tr.resize(4*n);
        lazy.resize(4*n, 0);
        build(v, 0, n-1, 1);
    }
    void build( vli &v, int l, int r, int ind){
        if(l==r){
            tr[ind].init(v[l], l, r-l+1);
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
    pal query(int i, int j){ node temp = query1(i, j, 0, n-1, 1); return {temp.val, temp.ind}; }
    void upd(lli x, int i, int j){ update(x, i , j, 0, n-1, 1); }
};
node node::operator +(node r){
    if(r.dummy) return *(this);
    if(this->dummy) return r;
    node ans;
    if(val < r.val) ans.init(r.val, r.ind, num+r.num);
    else ans.init(val, ind, num+r.num);
    return ans;
}

// build(array)
// update(val, start, end) 0 based
// query(start, end) 0 based
// change + operator, update function in node
int main(int argc, char **argv)
{
    crap;
    int n;
    lli k;
    cin>>n>>k;
    vli p(n);
    vector< pair< pal, int > > w(n);
    FOR(i, n){
        cin>>w[i].fi.fi>>w[i].fi.se>>p[i];
        w[i].se=i;
    }
    sort(all(w));
    vli pref(MAXC+1, 0);
    FOR(i, MAXC) pref[i+1] = pref[i] - k;
    seg_tree sg(pref);

    FORR(x, w) sg.upd(p[x.se], x.fi.se, MAXC);
    lli ans = 0, L, R;

    FOR(i, n){
        if(i) sg.upd(-p[w[i-1].se], w[i-1].fi.se, MAXC);
        lli q = w[i].fi.fi;
        pal temp = sg.query(q, MAXC);
        temp.fi += k*(q-1);
        if(temp.fi > ans) ans=temp.fi, L=q, R = temp.se;
    }
    if(!ans) cout<<0<<endl;
    else{
        vi v;
        FORR(x, w) if(x.fi.fi >= L && x.fi.se <= R) v.pb(x.se+1);
        cout<<ans<<" "<<L<<" "<<R<<" "<<v.size()<<endl;
        FORR(x, v) cout<<x<<" ";
        cout<<endl;
    }
}