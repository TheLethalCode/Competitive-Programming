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
        int n, m, high;
        cin >> n;
        vector< int > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        high = *max_element(v.begin(), v.end());
        set < int > S;
        for (int i = 1; i < n; i++) {
            S.insert(v[i] - v[i-1]);
        }
        if (S.size() > 2) {
            cout << "-1\n";
            continue;
        }
        if (S.size() < 2) {
            cout << "0\n";
            continue;
        }
        if (*S.begin() >= 0 || *S.rbegin() <= 0 || (m = abs(*S.begin()) + *S.rbegin()) <= high) {
            cout << "-1\n";
            continue;
        }
        cout << m << " " << *S.rbegin() << "\n";
    }
}