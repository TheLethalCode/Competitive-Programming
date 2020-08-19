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
    int n, cur = 0, nem = 0;
    string s;
    cin >> n >> s;
    vector < int > ans;
    FOR (i, n) {
        if(s[i] == 'x') {
            cur++;
        } else {
            ans.pb(cur);
            cur = 0;
        }
    }
    nem += max(0, cur - 2);
    FORR (v, ans) {
        nem += max(0, v - 2);
    }
    cout << nem << '\n';
}