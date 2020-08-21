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
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

const int UP = 1000000;

lli solve(vector< pair< int, int > > &X, vector< pair< int, int > > &Y, int ch, int ty = 1) {
    ordered_set S;
    lli cnt = 0;
    auto it = Y.begin(), itX = X.begin();
    for (; it != Y.end() && itX != X.end();) {
        if (ty*(it->fi) <= ty*(itX->fi)) {
            S.insert({ch*(it->se), it->fi});
            it++;
        } else {
            cnt += S.size() - S.order_of_key(make_pair(ch*(itX->se), 0));
            itX++;
        }
    }
    while (itX != X.end()) {
        cnt += S.size() - S.order_of_key(make_pair(ch*(itX->se), 0));
        itX++;
    }
    return cnt;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    lli ans = 1;
    cin >> n >> m;
    vector< pair< int, int > > V[4];
    FOR (i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 0) {
            V[0].pb(c, a);
        } else {
            V[1].pb(b, a);
        }
        ans += (!b && c==UP);
    }
    FOR (i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 0) {
            V[2].pb(a, c);
        } else {
            V[3].pb(a, b);
        }
        ans += (!b && c==UP);
    }
    FOR (i, 4) {
        sort(V[i].begin(), V[i].end());
    }
    ans += solve(V[0], V[2], 1) + solve(V[0], V[3], -1);

    FOR (i, 4) {
        reverse(V[i].begin(), V[i].end());
    }
    ans += solve(V[1], V[2], 1, -1) + solve(V[1], V[3], -1, -1);
    cout << ans << '\n';
}