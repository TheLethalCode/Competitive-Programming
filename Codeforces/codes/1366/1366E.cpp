#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
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

// %
int main(int argc, char **argv)
{
    crap;
    int n, m, fl=0;
    cin>>n>>m;
    vi v(n), b(m), inds;
    map<int, int> last;
    lli ans = 1;
    inds.pb(-1);
    FOR(i, n) cin>>v[i], last[v[i]]=i;
    FOR(i, m) {
        cin>>b[i];
        if(!last.count(b[i]) || inds.back()>last[b[i]]) fl=1;
        else inds.pb(last[b[i]]);
    }
    inds.pb(n);
    seg_tree sg(v);
    for(int i=1;i<=m && !fl;i++){
        set< int > mi; int j;
        for(j=inds[i];j>inds[i-1];j--){
            mi.insert(v[j]);
            if(!mi.empty() && *mi.begin()<b[i-1]) break;
        }
        if(i==1 && j!=-1) fl=1;
        if(inds[i]+1<inds[i+1] && sg.query(inds[i]+1, inds[i+1]-1) < b[i-1]) fl=1;
        if(!fl && i>=2) ans*=inds[i]-j, ans %= mod;
    }
    if(fl){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
}