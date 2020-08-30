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
        vector <int > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        int ok, cur = 1;
        set < pair < int, int > , greater < pair <int, int > > > S;
        for (int i = 0; i < n; i++) {
            S.insert({v[i], i});
        }
        pair < int, int > la1 = {0, 0}, la2 = {0, 0};
        while (S.size()) {
            la2 = *S.begin();
            la2.fi--;
            S.erase(S.begin());
            if (la1.fi) {
                S.insert(la1);
            }
            swap(la1, la2);
            cur = !cur;
        }
        ok = !cur;
        cout << (ok? "T": "HL") << '\n';
    }
}