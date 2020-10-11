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
        cin >> n;
        int A[n], mark[n] = {}, ans[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int pos = max_element(A, A + n) - A;
        mark[pos] = 1;
        ans[0] = A[pos];
        int gc = A[pos];
        for (int i = 1; i < n; i++) {
            pair< int, int > temp = {0, 0};
            for (int i = 0; i < n; i++) {
                if (!mark[i]) {
                    temp = max(temp, make_pair(__gcd(gc, A[i]), i));
                }
            }
            gc = temp.fi;
            ans[i] = A[temp.se];
            mark[temp.se] = 1;
        } 
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}