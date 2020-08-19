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
#define sz(a) (int)(a.size())
#define MAXC 300005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

struct data{
    
    lli high, sum, lazyVal;
    bool exist, lazy;

    data(): exist(false) {} 
    data(lli v) : sum(v), high(v), exist(true), lazy(false), lazyVal(0) {}

    // Node combination
    data operator+(data r){
        if(!r.exist) return *this;
        if(!this->exist) return r;
        data ans(max(high, r.high));
        ans.sum = sum + r.sum;
        return ans;
    }
    
    // Lazy updation
    void upd(int l, int r){
        high += lazyVal;
        sum += (r - l + 1) * lazyVal;
        lazy = false;
        lazyVal = 0;
    }
};

struct seg_tree{
    int n;
    vector< data > tr;
    seg_tree(int size){
        n = size;
        tr.resize(4*n, data(0));
    }
    seg_tree(vector< lli > &v){
        n = v.size();
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
            tr[ind].upd(l, r);
        }
    }
    void build( vector< lli > &v, int l, int r, int ind){
        if(l==r){
            tr[ind].sum = tr[ind].high = v[l];
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
            tr[ind].lazyVal += x;
            pushdown(ind, l, r);
            return;
        }
        int mid=l+r>>1;
        update(x, i, j, l, mid, ind<<1);
        update(x, i, j, mid+1, r, ind<<1|1);
        tr[ind] = tr[ind<<1] + tr[ind<<1|1];
    }
    int findNext(lli val, int i, int l, int r, int ind){
        pushdown(ind, l, r);
        if (r < i || tr[ind].high < val){
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = l + r >> 1;
        int pos = findNext(val, i, l, mid, ind << 1);
        if (pos == -1) {
            pos = findNext(val, i, mid + 1, r, ind << 1 | 1);
        } 
        return pos;
    }
    data query1(int i, int j, int l, int r, int ind){
        if(i>r || j<l || l>r){
            return data();
        }
        pushdown(ind, l, r);
        if(l>=i && r<=j){
            return tr[ind];
        }
        int mid=l+r>>1;
        return query1(i, j, l, mid, ind<<1) + query1(i, j, mid+1, r, ind<<1|1);
    }
    lli query(int i, int j){ 
        data temp = query1(i, j, 0, n-1, 1); 
        return temp.sum;
    }
    void upd(lli x, int i, int j){ 
        update(x, i , j, 0, n-1, 1); 
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector< lli > v(n);
    FOR (i, n) {
        cin >> v[i];
    }
    seg_tree sg(v);
    while (q--) {
        int x, y;
        cin >> x >> y;
        sg.upd(y - v[x-1], x - 1, x - 1);
        v[x-1] = y;
        if (v[0] == 0) {
            cout << "1\n";
            continue;
        }
        lli curSum = v[0], ind = 0;
        while((ind = sg.findNext(curSum, ind + 1, 0, n-1, 1)) != -1) {
            if ((curSum = sg.query(0, ind)) == 2 * v[ind]) {
                cout << ind + 1 << '\n';
                break;
            }
        }
        if (ind == -1) {
            cout << "-1\n";
        }
    }
}