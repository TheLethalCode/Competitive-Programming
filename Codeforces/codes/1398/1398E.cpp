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
    int n;
    cin >> n;
    set < int, greater< int > > B, S;
    set < int > Y;
    lli mult = 0, tot = 0;
    int cntY = 0;
    auto remove = [&](int r) {
        if (S.count(r)) {
            S.erase(r);
        } else if (B.count(r)) {
            B.erase(r);
            mult -= r;
        }
    };  
    FOR(i, n) {
        int t, d;
        cin >> t >> d;
        tot += d;
        if (d > 0) {
            if (t == 0) {
                S.insert(d);
            } else {
                cntY++;
                if (!Y.empty() && *Y.begin() < d) {
                    S.insert(d);
                } else if (!Y.empty()) {
                    S.insert(*Y.begin());
                }
                Y.insert(d);
            }
        } else {
            d = -d;
            if (t == 0) {
                remove(d);  
            } else {
                cntY--;
                int x = *Y.begin();
                Y.erase(d), remove(d);
                if (!Y.empty() && x != *Y.begin()) {
                    remove(*Y.begin());
                }
            }
        }
        while (B.size() > cntY) {
            S.insert(*B.rbegin());
            mult -= *B.rbegin();
            B.erase(*B.rbegin());
        }
        while (!S.empty() && B.size() < cntY) {
            B.insert(*S.begin());
            mult += *S.begin();
            S.erase(S.begin());
        }
        while (!S.empty() && !B.empty() && *B.rbegin() < *S.begin()) {
            int x = *B.rbegin(), y = *S.begin();
            mult += y - x;
            B.erase(x), S.erase(y);
            B.insert(y), S.insert(x);
        }
        cout << tot + mult << '\n';
    }
}