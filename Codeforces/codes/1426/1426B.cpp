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
#define MAXC 200005
// %

struct tile {
    int x0, x1, x2, x3;
    void inp() {
        cin >> x0 >> x1 >> x3 >> x2;
    }
    bool operator==(tile giv) {
        return x0==giv.x0 && x3==giv.x1 && x2==giv.x2 && x1==giv.x3;
    }
    bool diag(){
        return x1==x3;
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool diag = false, trans = false;
        vector< tile > v(n);
        for (int i = 0; i < n; i++) {
            v[i].inp();
            diag |= v[i].diag();
            for (int j = 0; j <= i; j++) {
                trans |= (v[i] == v[j]);
            }
        }
        cout << (diag && trans && !(m & 1) ? "YES\n" : "NO\n");
    }
}