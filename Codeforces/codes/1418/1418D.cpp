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

set < int > S;
multiset < int > D;
    
void ans() {
    if (D.empty()) {
        cout << 0 << '\n';
    } else {
        int ans = *S.rbegin() - *S.begin() - *D.rbegin();
        cout << ans << '\n';
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        S.insert(x);
    }
    for (auto it = S.begin(); it != S.end(); it++) {
        if (it == S.begin()) {
            continue;
        }
        auto cu = it, pr = prev(it);
        int diff = *cu - *pr;
        D.insert(diff);
    }
    ans();
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (!t) {
            auto it = S.find(x);
            if (it != S.begin()) {
                auto a = *it, b = *prev(it);
                D.erase(D.find(a - b));
            }
            if (++it != S.end()) {
                auto a = *it, b = *prev(it);
                D.erase(D.find(a - b));
            }
            --it;
            it = S.erase(it);
            if (it != S.begin() && it != S.end()) {
                auto a = *it, b = *prev(it);
                D.insert(a - b);
            }
        } else {
            auto it = S.lower_bound(x);
            if (it != S.begin() && it != S.end()) {
                auto a = *it, b = *prev(it);
                D.erase(D.find(a - b));
            }
            it = S.insert(x).fi;
            if (it != S.begin()) {
                auto a = *it, b = *prev(it);
                D.insert(a - b);
            }
            if (++it != S.end()) {
                auto a = *it, b = *prev(it);
                D.insert(a - b);
            }
        }
        ans();
    }
}