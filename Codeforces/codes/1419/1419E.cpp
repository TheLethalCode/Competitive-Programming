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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, j;
        cin >> n;
        set< int > fact;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                fact.insert(i);
                fact.insert(n / i);
            }
        }
        fact.erase(1);

        vector< int > pri;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                pri.pb(i);
            }
        }
        if (n != 1) {
            pri.pb(n);
        }

        if (fact.size() == 3 || pri.size() == 1) {
            for (int x : fact) {
                cout << x << " ";
            }
            cout << (pri.size() == 1? "\n0\n":"\n1\n");
        } else if (pri.size() == 2) {
            int n = *fact.rbegin(), a = pri[0], b = pri[1], c = a * b;
            fact.erase(a), fact.erase(b), fact.erase(c), fact.erase(n);
            
            auto f = [&](int x) {
                auto it = fact.begin();
                while (it != fact.end()) {
                    j = *it;
                    if (!(j % x)) {
                        cout << j << " ";
                        it = fact.erase(it);
                    } else {
                        it++;
                    }
                }
            };
            cout << a << " ";f(a);
            cout << c << " " << b << " ";f(b);
            cout << n << "\n0\n";
        } else {
            n = pri.size();
            for (int i = 0, up = 0; i < n; i++) {
                cout << pri[i] << " ";
                fact.erase(pri[i]);

                auto it = fact.begin();
                while (it != fact.end()) {
                    j = *it;
                    if (!(j % pri[i]) && j/pri[i] != pri[(i+1) % n] && j/pri[i] != pri[(i+n-1) % n]) {
                        cout << j << " ";
                        it = fact.erase(it);
                    } else {
                        it++;
                    }
                }
                cout << (j = pri[i] * pri[(i+1) % n]) << " ";
                fact.erase(j);
            }
            cout << "\n0\n";
        }
    }
}