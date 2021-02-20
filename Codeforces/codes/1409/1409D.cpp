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

int sumD(lli x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli n;
        int s;
        cin >> n >> s;
        lli fin = n, po = 10;
        while (sumD(fin) > s) {
            lli rem = fin % po;
            fin += po - rem;
            po *= 10;
        }
        cout << fin - n << '\n';
    }
}