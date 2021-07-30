#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 1000005
#define C2 2005

vector < int > prime, lp;
void linearSieve(int n){
    lp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            prime.push_back(i);
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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    linearSieve(C1);
    while (t--) {
        int n;
        cin >> n;
        map < int, int > remSq;
        int maxSet = 0, eveCnt = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            int ans = 1;
            while (x != 1) {
                int cnt = 0, p = lp[x];
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                if (cnt & 1) {
                    ans *= p;
                }
            }
            remSq[ans]++;
            maxSet = max(maxSet, remSq[ans]);
        }
        for (auto it : remSq) {
            if (!(it.se & 1) || it.fi == 1) {
                eveCnt += it.se;
            } 
        }
        int q;
        cin >> q;
        while (q--) {
            lli w;
            cin >> w;
            if (w > 0) {
                cout << max(eveCnt, maxSet) << "\n";
            } else {
                cout << maxSet << "\n";
            }
        }
    }
}