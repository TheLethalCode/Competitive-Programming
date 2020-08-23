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
#define MAXC 100005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int bit[MAXC];

void add(int idx, int val) {
    for (++idx; idx < MAXC; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector< lli > A(n);
        memset(bit, 0, sizeof(bit));
        FOR (i, n) {
            cin >> A[i];
        }
        FOR (i, m) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            range_add(a, b, 1);
        }
        vector < int > ord(n), che;
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return A[i] < A[j];
        });
        FORR (i, ord) {
            che.pb(point_query(i));
        }
        vector < lli > sum = {0};
        FORR (el, che) {
            lli next = sum.back() + el;
            sum.pb(next);
        }
        while (q--) {
            lli k;
            cin >> k;
            if (k > sum.back()) {
                cout << -1 << ' ';
                continue;
            }
            int pos = lower_bound(sum.begin(), sum.end(), k) - sum.begin();
            cout << A[ord[pos-1]] << ' ';
        }
        cout << '\n';
    }
}