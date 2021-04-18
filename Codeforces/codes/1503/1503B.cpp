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
    vector< pair< int, int > > pos[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pos[(i + j) % 2].pb(i + 1, j + 1);
        }
    }
    for (int i = 0; i < n * n; i++) {
        int a;
        cin >> a;
        if (a != 1 && pos[0].size()) {
            cout << 1 << " " << pos[0].back().fi << " " << pos[0].back().se << endl;
            pos[0].pop_back();
        } else if (a != 2 && pos[1].size()) {
            cout << 2 << " " << pos[1].back().fi << " " << pos[1].back().se << endl;
            pos[1].pop_back();
        } else {
            int which = pos[0].empty()? 1: 0;
            cout << 3 << " " << pos[which].back().fi << " " << pos[which].back().se << endl;
            pos[which].pop_back();
        }
    }
}