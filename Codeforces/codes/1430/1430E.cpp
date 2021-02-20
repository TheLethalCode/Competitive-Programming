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
    string s;
    cin >> n >> s;
    vector< int > pos[26], rpos[26];
    ordered_set pS[26], rpS[26];
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].pb(i+1), pS[s[i] - 'a'].insert(i+1);
        rpos[s[i] - 'a'].pb(n - i), rpS[s[i] - 'a'].insert(n - i);
    }
    lli ans = 0;
    for (int i = 0; i < 26; i++) {
        reverse(rpos[i].begin(), rpos[i].end());
        for (int j = 0; j < pos[i].size(); j++) {
            for (int k = 0; k < 26; k++) {
                ans += abs((int)pS[k].order_of_key(pos[i][j]) - (int)rpS[k].order_of_key(rpos[i][j]));
            }
        }
    }
    cout << ans / 2 << '\n';
}