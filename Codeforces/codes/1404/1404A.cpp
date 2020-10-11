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
        int n, k, ok = 1, cnt = 0, cnt1 = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < k; i++) {
            set< char > S;
            for (int j = i; j < n; j+=k) {
                if(s[j] != '?') {
                    S.insert(s[j]);
                }
            }
            char temp;
            if (S.size() == 1) {
                cnt += (*S.begin() == '0');
                cnt1 += (*S.begin() == '1');
                for (int j = i; j < n; j+=k) {
                    if (s[j] == '?') {
                        s[j] = *S.begin();
                    }
                }
            }
            if (S.size() > 1 || cnt > k/2 || cnt1 > k/2) {
                ok = 0;
                break;
            }
        }
        cout << (ok? "YES" : "NO") << '\n';
    }
}