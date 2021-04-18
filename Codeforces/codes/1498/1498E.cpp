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
    vector< int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] = n - 1 - v[i];
    }
    vector < int > ord(n * n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return abs(v[i / n] - v[i % n]) > abs(v[j / n] - v[j % n]);
    });

    string ret;
    for (int q : ord) {
        int x = q / n, y = q % n;
        if (v[x] >= v[y] && x != y) {
            cout << "? " << y + 1 << " " << x + 1 << endl;
            cin >> ret;
            if (ret == "Yes") {
                cout << "! " << x + 1 << " " << y + 1 << endl;
                return 0;
            }
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}