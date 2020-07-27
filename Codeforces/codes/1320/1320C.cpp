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

// RANGE MAXIMUM QUERY
struct node{
    // Elements of the tree node
    lli val, num;
    bool dummy;

    node() : val(0), num(0), dummy(true) {}

    // Initialise
    void init(lli v, lli n){
        val=v, num=n, dummy = false;
    }

    // Change accordingly
    void update(lli x){
        val+=x; //Range min or max
        // val+=x*num // Range sum
    }

    // Combine operation for Max query
    node operator +(node r){
        if(r.dummy)
            return *(this);
        if(this->dummy)
            return r;
        node ans;
        ans.init(max(val, r.val), num+r.num);
        return ans;
    }
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

    // i-j update range
    void update(int x, int i, int j, int l, int r, int ind){
        
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind].update(lazy[ind]), lazy[ind]=0;
        }
        
        if(i>r || j<l || l>r)
            return;
        if(l>=i && r<=j){
            tr[ind].update(x);
            if(l!=r) lazy[ind<<1] += x, lazy[(ind<<1)+1] += x;
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1), update(x, i, j, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }

    // i-j query range
    node query1(int i, int j, int l, int r, int ind){
        
        if(i>r || j<l || l>r){
            node dum;
            return dum;
        }

        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] += lazy[ind], lazy[(ind<<1)+1] += lazy[ind];
            tr[ind].update(lazy[ind]), lazy[ind]=0;
        }

        if(l>=i && r<=j)
            return tr[ind];
        
        int mid=l+r>>1;
        node Lt = query1(i, j, l, mid, ind<<1), Rt = query1(i, j, mid+1, r, (ind<<1)+1);
        return Lt + Rt;
    }

    // Actual query
    lli query(int i, int j){
        return query1(i, j, 0, n-1, 1).val;
    }

    void upd(lli x, int i, int j){
        update(x, i , j, 0, n-1, 1);
    }
};

int main(int argc, char **argv)
{
    crap;
    int n, m, p;
    cin>>n>>m>>p;
    vpal we(n), ar(m);
    for(pal &el : we) cin>>el.fi>>el.se;
    for(pal &el : ar) cin>>el.fi>>el.se;
    vector< pair< pal, lli > > mon(p);
    FOR(i, p) cin>>mon[i].fi.fi>>mon[i].fi.se>>mon[i].se;

    sort(all(we)), sort(all(ar)), ar.pb({1e6+1, 0}), sort(all(mon));
    vi an(m+1, 0);
    FOR(i, m+1) an[i]-=ar[i].se;
    seg_tree sg(an);

    lli ans = -1e18;
    int cnt = 0;
    for(pal el : we){
        while(cnt<p && mon[cnt].fi.fi < el.fi){
            int pos = upper_bound(all(ar), make_pair(mon[cnt].fi.se, 1LL<<40)) - ar.begin();
            sg.upd(mon[cnt].se, pos, m);
            cnt++;
        }
        ans=max(ans, sg.query(0, m-1) - el.se);
    }
    cout<<ans<<endl;
}