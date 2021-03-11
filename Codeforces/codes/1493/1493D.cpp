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

set < pair< int, int > > man[MAXC], lol[MAXC];
vector < int > prime, lp;

void linearSieve(int n){
    lp.resize(n+1);
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            prime.pb(i);
            lp[i] = i;
        }
        for (auto p : prime) {
            if (p * i > n) {
                break;
            }
            lp[p * i] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
}


lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    linearSieve(MAXC);

    int n, q;
    cin >> n >> q;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        while (x != 1) {
            int j = lp[x], cnt = 0;
            while (lp[x] == j) {
                x /= lp[x];
                cnt++;
            }
            lol[j].insert({cnt, i});
            man[i].insert({j, cnt});
        }
    }

    lli cur = 1;
    for (int i = 2; i < MAXC; i++) {
        if (lol[i].size() == n) {
            cur = cur * modp(i, lol[i].begin() -> fi) % mod;
        }
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        while (x != 1) {
            int j = lp[x], cnt = 0;
            while (lp[x] == j) {
                x /= lp[x];
                cnt++;
            }

            int prev = lol[j].size() == n ? lol[j].begin()->fi : 0;
            auto it = man[i].lower_bound(make_pair(j, -1));
            
            if (it != man[i].end() && it->fi == j) {
                pair< int, int > q = {it->fi, it->se + cnt};
                it = man[i].erase(it);
                man[i].insert(it, q);
                lol[j].erase({q.se - cnt, i});
                lol[j].insert({q.se, i});
            } else {
                man[i].insert({j, cnt});
                lol[j].insert({cnt, i});
            }
            
            int now = lol[j].size() == n ? lol[j].begin()->fi : 0;
            if (now > prev) {
                cur = cur * modp(j, now - prev) % mod;
            }
        }
        cout << cur << '\n';
    }
}