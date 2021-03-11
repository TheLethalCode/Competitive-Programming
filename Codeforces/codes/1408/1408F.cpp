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
vector< pair< int, int > > ans;
vector< int > inds[15];

void conv2(int l, int r, int x) {
    if (x == 0) {
        return;
    } else if (x == 1) {
        ans.pb(l, r - 1);
        return;
    } else {
        int s = 1 << x - 1;
        for (int i = l; i + s < r; i++) {
            ans.pb(i, i + s);
        }
        conv2(l, l + s, x - 1);
        conv2(l + s, r, x - 1);
    }
}

void mvInd(int s, int d) {
    int x = inds[d].size();
    for (int i = 0; i < x; i++) {
        inds[d].pb(inds[s].back());
        inds[s].pop_back();
        ans.pb(inds[d][i], inds[d].back());
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s = 0, sum = 0, st = 0, up = 0;
    cin >> n;
    while ((1 << s) <= n) {
        if (n & 1 << s) {
            conv2(sum, sum + (1 << s), s);
            for (int i = sum; i < sum + (1 << s); i++) {
                inds[up].pb(i);
            }
            up++;
            sum += 1 << s;
        }
        s++;
    }
    
    while (up - st > 2) {
        while (inds[st].size() < inds[st+1].size()) {
            mvInd(up - 1, st);
        }
        mvInd(st, st + 1);
        st++;
    }

    cout << ans.size() << '\n';
    for (auto it : ans) {
        cout << it.fi + 1 << " " << it.se + 1<< '\n';
    }
}