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
    int val1, val2, num;
    bool dummy;
    node() : dummy(true) {}
    void init(int v1, int v2, int n){
        val1=v1, val2=v2, num=n, dummy = false;
    }
    void update(int x){
        val1+=x; //Range min or max
        val2+=x;
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
    pal query(int i, int j){ auto t = query1(i, j, 0, n-1, 1); return {t.val1, t.val2};}
    void upd(int x, int i, int j){ update(x, i , j, 0, n-1, 1); }
};
node node::operator +(node r){
    if(r.dummy) return *(this);
    if(this->dummy) return r;
    node ans;
    ans.init(max(val1, r.val1), min(val2, r.val2), num+r.num);
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int n, cnt=0, cur=0, prev=0, bra = 0;
    cin>>n;
    
    string q;
    cin>>q;
    FORR(x, q) if(x=='R') cnt++;
    cnt++;

    string s(cnt+1, ' ');
    vi pref(cnt+1, 0);
    seg_tree sg(pref);

    FORR(x, q){
        if(x=='L') {
            if(cur) cur--;
            cout<<prev<<" ";
            continue;
        }
        if(x=='R') {
            cur++;
            cout<<prev<<" ";
            continue;
        }
        if(s[cur]=='(') sg.upd(-1, cur, cnt), bra--;
        if(s[cur]==')') sg.upd(1, cur, cnt), bra++;
        s[cur]=x;
        if(x=='(') sg.upd(1, cur, cnt), bra++;
        if(x==')') sg.upd(-1, cur, cnt), bra--;
        if(bra){
            cout<<(prev=-1)<<" ";
            continue;
        }
        pa q = sg.query(0, cnt);
        if(q.se < 0) cout<<(prev=-1)<<" ";
        else cout<<(prev=q.fi)<<" ";
    }
    cout<<endl;
}