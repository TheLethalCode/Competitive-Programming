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

int cntNum[MAXC];
vector< int > fact[MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    lli l, r;
    cin >> n >> m >> l >> r;
    for (int i = 1; i < MAXC; i++) {
        for (int j = i; j < MAXC; j+=i) {
            fact[j].pb(i);
        }
    }
    
    set < int > curFacts;
    int curL = -1, curR = -1;
    for (int i = 1; i <= n; i++) {
        lli l_new = (l + i - 1) / i, r_new = min(1LL * m, r / i);
        if (l_new > r_new) {
            cout << "-1\n";
            continue;
        }
        if (curR == -1) {
            curR = curL = r_new;
        }
        while (curL >= l_new) {
            for (int x : fact[curL]) {
                if (!cntNum[x]) {
                    curFacts.insert(x);
                }
                cntNum[x]++;
            }
            curL--;
        }
        while (curR > r_new) {
            for (int x : fact[curR]) {
                cntNum[x]--;
                if (!cntNum[x]) {
                    curFacts.erase(x);
                }
            }
            curR--;
        }
        int ok = 0;
        for (int r1 : fact[i]) {
            auto temp = curFacts.upper_bound(r1);
            if (temp == curFacts.end()) {
                continue;
            }
            int r2 = *temp, g1 = i / r1;
            if (1LL * g1 * r2 > n) {
                continue;
            }
            int g2 = r_new / r2;
            cout << i << " " << g2 * r2 << " ";
            cout << r2 * g1 << " " << g2 * r1 << "\n";
            ok = 1;
            break;
        }
        if (!ok) {
            cout << "-1\n";
        }
    }
}