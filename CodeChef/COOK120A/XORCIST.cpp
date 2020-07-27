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
#define sz(a) (int)(a.size())
#define MAXC 500005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int ar[MAXC][30][2], ze[MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    vector< int > cnt;
    cin >> t;
    while(t--){
        int n, q, x, y;
        cin >> n >> q;
        FOR(i, n){
            cin >> x;
            y = 0;
            FOR(j, 30){
                FOR(k, 2){
                    ar[i+1][j][k] = ar[i][j][k];
                }
            }
            ze[i+1] = ze[i] + !x;
            while(x){
                if(x & 1){
                    cnt.pb(y);
                }
                y++;
                x >>= 1;
            }
            reverse(cnt.begin(), cnt.end());
            for(int j=0; j<cnt.size();j++){
                ar[i+1][cnt[j]][!!j]++;
            }
            cnt.clear();
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            lli ans = 1LL * (ze[r] - ze[l-1]) * (r-l+1);
            FOR(i, 30){
                int b1 = ar[r][i][0] - ar[l-1][i][0];
                int b2 = ar[r][i][1] - ar[l-1][i][1];
                ans += 1LL*b1*b2;
            }
            cout << ans << '\n';
        }
    }
}