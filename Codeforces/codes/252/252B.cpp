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

bool check(int i, int j, vector < int > v) {
    swap(v[i], v[j]);
    return !is_sorted(v.begin(), v.end()) && !is_sorted(v.rbegin(), v.rend());
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector< int > v(n);
    map< int, int > M;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        M[v[i]] = i + 1;
    }
    if (M.size() == 1) {
        cout << -1 << "\n";
    } else if (M.size() > 2) {
        vector< int > temp;
        for (auto it : M) {
            temp.pb(it.fi);
            if (temp.size() > 2) {
                break;
            }
        }
        for (int i = 0; i < 3; i++) {
            int x = M[temp[i]], y = M[temp[(i+1) % 3]];
            if (check(x-1, y-1, v)) {
                cout << x << " " << y << "\n";
                return 0;
            }
        }
    } else if (v.size() <= 4){
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i] != v[j] && check(i, j, v)) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
        cout << "-1\n";
    } else {
        map< int, vector< int > > N;
        for (int i = 0; i < n; i++) {
            N[v[i]].pb(i+1);
        }
        vector< int > v1 = N.begin()->se, v2 = N.rbegin()->se;
        if (v1.size() > v2.size()) {
            swap(v1, v2);
        }
        cout << v1[0] << " " << v2[1] << "\n";
    }
} 