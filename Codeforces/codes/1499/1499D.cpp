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
#define MAXC 20000005
// %

int prime[MAXC/10], cnt[MAXC], up = 0;
lli c, d, x;

void linearSieve(int n){
    for (int i = 2; i <= n; i++) {
        if (!cnt[i]) {
            prime[up++] = i;
            cnt[i] = 1;
        }
        for (int j = 0; j < up && prime[j] * i <= n; j++) {
            cnt[prime[j] * i] = cnt[i];
            if (i % prime[j] == 0) {
                break;
            }
            cnt[prime[j] * i]++;
        }
    }
}


int solve(int f) {
    int temp = f + d;
    if (temp % c) {
        return 0;
    }
    return 1 << cnt[temp/c];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    linearSieve(MAXC - 1);
    
    int t;
    cin >> t;
    while (t--) {
        lli ans = 0;
        cin >> c >> d >> x;
        lli gc = __gcd(c, d);
        if (x % gc) {
            cout << "0\n";
            continue;
        }
        x /= gc;
        c /= gc;
        d /= gc;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ans += solve(i);
                if (i * i != x) {
                    ans += solve(x / i);
                }
            }
        }
        cout << ans << "\n";
    }
}