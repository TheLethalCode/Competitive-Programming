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
#define MAXC 1000005
// %

lli gcd(lli a, lli b, lli &x, lli &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x2, y2, g = gcd(b, a % b, x2, y2);
    x = y2;
    y = x2 - a / b * y2;
    return g;
} 

int pos1[MAXC], pos2[MAXC];
lli val1[MAXC], n, m, k, x, y;
vector< lli > pos;


int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(pos1, 0xff, sizeof(pos1));
    memset(pos2, 0xff, sizeof(pos2));
    
    cin >> n >> m >> k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pos1[x] = i;
    }
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        pos2[x] = i;
    }

    lli gc = gcd(n, m, x, y), lcm = n * m / gc;
    for (int i = 1; i < MAXC; i++) {
        lli q1 = pos1[i], q2 = pos2[i];
        if (q1 == -1 || q2 == -1 || (q2 - q1) % gc) {
            continue;
        }
        lli xf = x * (q2 - q1) / gc, xmul = m / gc; 
        val1[i] = (xf % xmul + xmul) % xmul;
        pos.pb(val1[i]*n + pos1[i]);
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++) {
        pos[i] -= i;
    }
    lli cnt = lcm - pos.size(), ans = k / cnt * lcm, left = k % cnt;
    if (!left) {
        ans -= lcm;
        left += cnt;
    } 
    ans += left + (upper_bound(pos.begin(), pos.end(), left-1) - pos.begin()); 
    cout << ans << "\n";
}