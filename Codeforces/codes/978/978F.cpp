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
#define ordered_set tree<pair< int, int >, null_type, less<pair< int, int >>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector < int > V(n+1), Q(n+1);
    ordered_set S;
    FOR (i, n) {
        cin >> V[i+1];
        S.insert(make_pair(V[i+1], i+1));
    }
    FOR (i, k) {
        int a, b;
        cin >> a >> b;
        if (V[a] > V[b]) Q[a]++;
        if (V[b] > V[a]) Q[b]++;
    }
    FOR (i, n) {
        int cnt = S.order_of_key(make_pair(V[i+1], 0));
        cout << cnt - Q[i+1] << ' ';
    }
    cout << '\n';
}