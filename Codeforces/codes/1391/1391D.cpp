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
    int n, m;
    cin >> n >> m;
    char v[min(n, m)][max(n, m)];
    FOR(i, n){
        FOR(j, m){
            if(n <= m){
                cin >> v[i][j];
            }
            else{
                cin >> v[j][i];
            }
        }
    }
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    if(n >= 4){
        cout << "-1\n";
        return 0;
    }
    if(n == 2){
        int cnt[m][2];
        FOR(i, m){
            cnt[i][0] = cnt[i][1] = 100;
            FOR(j, 2){
                FOR(k, 2){
                    cnt[i][(j+k) & 1] = min(cnt[i][(j+k) & 1], (v[0][i] != '0'+j) + (v[1][i] != '0'+k));
                }
            }
        }
        int ans = mod;
        FOR(r, 2){
            int prev = r, temp = 0;
            FOR(i, m){
                temp += cnt[i][prev];
                prev = !prev;
            }
            ans = min(ans, temp);
        }
        cout << ans << '\n';
        return 0;
    }
    else{
        int cnt[m][2][2];
        memset(cnt, 0x3f, sizeof(cnt));
        FOR(i, m){
            FOR(j, 2){
                FOR(k, 2){
                    FOR(l, 2){
                        cnt[i][(j+k)&1][(k+l)&1] = min(cnt[i][(j+k)&1][(k+l)&1], (v[0][i] != '0'+j) + (v[1][i] != '0'+k) + (v[2][i] != '0'+l));
                    }
                }
            }
        }
        int ans = mod;
        FOR(p, 2){
            FOR(q, 2){
                int pr1 = p, pr2 = q, temp = 0;
                FOR(i, m){
                    temp += cnt[i][pr1][pr2];
                    pr1 = !pr1;
                    pr2 = !pr2;
                }
                ans = min(ans, temp);
            }
        }
        cout << ans << '\n';
    }
}