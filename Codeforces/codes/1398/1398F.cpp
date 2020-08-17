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

struct obj {
    int d, l, r, i;
    obj (int _d, int _l, int _r, int _i) : i(_i), d(_d), l(_l), r(_r) {}
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s += '*';
    vector< pair < int , int > > blocks;
    for (int i = 0, cur = 0; i <= n; i++) {
        if (!i || s[i] == s[i-1]) {
            cur++;
        } else {
            if (!blocks.empty() || s[i-1] != '?') {
                int x = blocks.size();
                if (x >= 2 && blocks[x-1].se == 2 && blocks[x-2].se == s[i-1] - '0') {
                    cur += blocks[x-2].fi += blocks[x-1].fi;
                    blocks.pop_back();
                    blocks.pop_back();
                }   
                blocks.pb(cur, s[i-1]=='?'? 2 : s[i-1]-'0');
                cur = 0;
            }
            cur++;
        }
    }
    if (blocks.empty()) {
        blocks.pb(n, 1);
    }
    if (blocks.back().se == 2) {
        int x = blocks.back().fi;
        blocks.pop_back();
        blocks.back().fi += x;
    }
    vector < obj > data[n+1];
    for (int i = 0, l, r, cur; i < blocks.size(); i++) {
        l = r = 0;
        if (blocks[i].se != 2) {
            cur = blocks[i].fi;
            if (i && blocks[i-1].se == 2) {
                l = blocks[i-1].fi;
            }
            if (i + 1 != blocks.size() && blocks[i+1].se == 2) {
                r = blocks[i+1].fi;
            }
            for (int j = 1; j <= l + r + cur; j++) {
                data[j].pb(cur, l, r, i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = 0, pr = 0, m = data[i].size();
        for (int j = 0; j < m; j++) {
            int x = data[i][j].d + data[i][j].r + data[i][j].l - pr, rem = x - x / i * i;
            cur += x / i;
            if (j < m-1 && data[i][j+1].i - 1 == data[i][j].i + 1 && blocks[data[i][j].i + 1].se == 2) {
                pr = max(0, data[i][j].r - rem);
            } else {
                pr = 0;
            }
        }
        cout << cur << " ";
    }
    cout << '\n';
}