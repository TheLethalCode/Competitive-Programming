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

pair< int, string > append(pair< int, string > S, string add) {
    pair< int, string > ret;
    if (S.fi < 10) {
        ret.se = add + S.se;
    } else {
        ret.se = add + S.se.substr(0, 4) + "..." + S.se.substr(8); 
    }
    ret.fi = S.fi + 1;
    return ret;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), after[n + 1];
    vector< pair< int, string > > ans(n + 1);
    char nextNE[n];
    ans[n] = {0, ""};
    ans[n - 1] = {1, string(1, s[n-1])}, nextNE[n - 1] = 2;
    after[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) {
            after[i] = after[i + 1];
            if ((ans[after[i]].fi && ans[after[i]].se[0] > s[i]) || 
                    (ans[after[i]].fi > 1 && ans[after[i]].se[0] == s[i] && nextNE[after[i]] > s[i])){
                nextNE[i] = (s[i] == ans[i + 1].se[0]? nextNE[i + 1]: ans[i + 1].se[0]);
                ans[i] = append(ans[i + 1], string(1, s[i]));
            } else {
                nextNE[i] = nextNE[i + 2];
                ans[i] = ans[i + 2];
            }
        } else {
            after[i] = i + 1;
            nextNE[i] = (s[i] == ans[i + 1].se[0]? nextNE[i + 1]: ans[i + 1].se[0]);
            ans[i] = append(ans[i + 1], string(1, s[i]));
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}