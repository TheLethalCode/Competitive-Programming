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
        int n;
        string s;
        cin >> n >> s;
        vector< int > blocks;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (i == 0 || s[i] == s[i-1]) {
                cnt++;
            } else {
                blocks.pb(cnt);
                cnt = 1;
            }
        }
        blocks.pb(cnt);
        n = blocks.size();
        int ans = 0, done = 0, to = 0, ok = false;
        while(done < n) {
            while(to < done) to++;
            ans++;

            while(!ok && to < n && blocks[to] == 1) to++;
            if (to == n) {
                to = done;
                ok = true;
            }

            blocks[to]--;
            if (!blocks[to]) done++;
            done++;
        }
        cout << ans << '\n';
    }
}