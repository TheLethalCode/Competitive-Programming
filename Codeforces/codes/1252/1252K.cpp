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


struct node{
    int num;
    bool dummy;
    pal Av, Bv;
    node() : dummy(true) {}
    void init(int x, int n){
        num=n, dummy = false;
        Av = {1, 0}, Bv = {0, 1};
        if(x) Bv.fi = 1;
        else Av.se = 1;
    }
    void update(){
        swap(Av, Bv);
        swap(Av.fi, Av.se), swap(Bv.fi, Bv.se);
    }
    node operator +(node r);
};

struct seg_tree{

    int n;
    vi lazy;
    vector< node > tr;

    seg_tree(string &v){
        n = v.size(), tr.resize(4*n);
        lazy.resize(4*n, 0);
        build(v, 0, n-1, 1);
    }
    void build( string &v, int l, int r, int ind){
        if(l==r){
            tr[ind].init(v[l]-'A', r-l+1);
            return;
        }
        int mid = l+r>>1;
        build(v, l, mid, ind<<1), build(v, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    void update(int i, int j, int l, int r, int ind){
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1]  ^= 1, lazy[(ind<<1)+1]  ^= 1;
            tr[ind].update(), lazy[ind]=0;
        }
        if(i>r || j<l || l>r || i>j) return;
        if(l>=i && r<=j){
            tr[ind].update();
            if(l!=r) lazy[ind<<1]  ^= 1, lazy[(ind<<1)+1]  ^= 1;
            return;
        }
        int mid=l+r>>1;
        update(i, j, l, mid, ind<<1), update(i, j, mid+1, r, (ind<<1)+1);
        tr[ind] = tr[ind<<1] + tr[(ind<<1)+1];
    }
    node query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            node dum;
            return dum;
        }
        if(lazy[ind]){
            if(l!=r) lazy[ind<<1] ^= 1, lazy[(ind<<1)+1] ^= 1;
            tr[ind].update(), lazy[ind]=0;
        }
        if(l>=i && r<=j) return tr[ind];
        int mid=l+r>>1;
        node Lt = query1(i, j, l, mid, ind<<1), Rt = query1(i, j, mid+1, r, (ind<<1)+1);
        return Lt + Rt;
    }
    node query(int i, int j){ return query1(i, j, 0, n-1, 1);}
    void upd(int i, int j){ update(i , j, 0, n-1, 1); }
};
node node::operator +(node r){
    if(r.dummy) return *(this);
    if(this->dummy) return r;
    node ans;
    ans.dummy = false;
    ans.Av.fi = (r.Av.fi * Av.fi + r.Av.se * Bv.fi) % mod;
    ans.Av.se = (r.Av.fi * Av.se + r.Av.se * Bv.se) % mod;
    ans.Bv.fi = (r.Bv.fi * Av.fi + r.Bv.se * Bv.fi) % mod;
    ans.Bv.se = (r.Bv.fi * Av.se + r.Bv.se * Bv.se) % mod;
    ans.num = num + r.num;
    return ans;
}

// build(array)
// update(val, start, end) 0 based
// query(start, end) 0 based
// change + operator, update function in node

int main(int argc, char **argv)
{
    crap;
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    seg_tree sg(s);
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int b, c;
            cin>>b>>c;
            sg.upd(b-1, c-1);
        }
        else{
            int b, c;
            lli y, z;
            cin>>b>>c>>y>>z;
            node tem = sg.query(b-1, c-1);
            cout<< ( y * tem.Av.fi + z * tem.Av.se ) % mod << " " ;
            cout<< ( y * tem.Bv.fi + z * tem.Bv.se ) % mod << endl ;
        }
    }
}