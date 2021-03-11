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

bool corr(string &s) {
    vector< char > v;
    for (auto x : s) {
        if (x == '0') {
            v.pb(x);
        } else if (v.size()) {
            v.pop_back();
        } else {
            return false;
        }
    }
    return v.empty();
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ok = 0;
        string s;
        cin >> s;
        n = s.size();
        vector< int > v(3);
        for (int i = 0; i <= 1 && !ok; i++) {
            for (int j = 0; j <= 1 && !ok; j++) {
                for (int k = 0; k <= 1 && !ok; k++) {
                    string temp = s;
                    for (auto &x : temp) {
                        if (x == 'A') {
                            x = i + '0';
                        } else if (x == 'B') {
                            x = j + '0';
                        } else {
                            x = k + '0';
                        }
                    }
                    if (corr(temp)) {
                        ok = 1;
                    }
                }
            }
        }
        cout << (ok? "Yes\n" : "No\n");
    }
}