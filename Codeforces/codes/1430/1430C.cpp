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
        vector< pair< int, int > > ans;
        multiset< int, greater< int > > O, E;
        for (int i = 1; i <= n; i++) {
            if(i % 2) {
                O.insert(i);
            } else {
                E.insert(i);
            }
        }
        while (O.size() > 1 || E.size() > 1) {
            int a, b;
            if (O.size() == 1) {
                a = *E.begin(), E.erase(E.begin());
                b = *E.begin(), E.erase(E.begin());
            } else if (E.size() == 1) {
                a = *O.begin(), O.erase(O.begin());
                b = *O.begin(), O.erase(O.begin());
            } else {
                auto &X = (*E.begin() > *O.begin() ? E : O);
                a = *X.begin(), X.erase(X.begin());
                b = *X.begin(), X.erase(X.begin());
            }
            ans.pb(a, b);
            int x = (a + b + 1)/2;
            if (x & 1) {
                O.insert(x);
            } else {
                E.insert(x);
            }
        }
        if (O.size() == 1 && E.size() == 1) {
            int a = *O.begin(), b = *E.begin();
            O.erase(a), E.erase(b);
            ans.pb(a, b);
            int x = (a + b + 1)/2;
            if (x & 1) {
                O.insert(x);
            } else {
                E.insert(x);
            }
        }
        cout << (E.empty()? *O.begin() : *E.begin()) << '\n';
        for (auto x : ans) {
            cout << x.fi << " " << x.se << '\n';
        }
    }
}