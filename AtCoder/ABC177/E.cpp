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
vector < int > prime, lp;

void linearSieve(int UP){
    lp.resize(UP, 0);
    for (int i = 2; i < UP; i++) {
        if (!lp[i]) {
            prime.pb(i);
            lp[i] = i;
        }
        for (auto p : prime) {
            if (p * i >= UP) {
                break;
            }
            lp[p * i] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    int gc = 0, ok = 1;
    linearSieve(1e6+1);
    map< int, int > pri;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        gc = __gcd(gc, v[i]);
        set < int > S;
        while (v[i] != 1) {
            S.insert(lp[v[i]]);
            v[i] /= lp[v[i]];
        }
        for (int x : S) {
            pri[x]++;
            ok &= (pri[x] <= 1);
        }
    }
    cout << (ok? "pairwise coprime" : gc == 1? "setwise coprime" : "not coprime") << '\n';    
}