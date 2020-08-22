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
    while(t--){
        int n, p, q;
        cin >> n >> p >> q;
        int gc = __gcd(p, q);
        p /= gc;
        q /= gc;
        vector< pair< int, int > > A(n);
        FOR(i, n){
            cin >> A[i].fi >> A[i].se;
        }
        FOR(i, n){
            vector< bitset< 805 > > Ans(805), cpy(805);
            Ans[0][0] = 1;
            FOR(j, n){
                if(j!=i){
                    FOR(k, 805){
                        if(k + A[j].fi >= 805){
                            break;
                        }
                        cpy[k + A[j].fi] = Ans[k + A[j].fi] | Ans[k] << A[j].se;
                    }
                    FOR(k, 805){
                        Ans[k] |= cpy[k];
                    }
                }
            }
            int ok = 0;
            for(int al = 1; al*p < 805 && al*q < 805; al++){
                if(Ans[al * p][al * q]){
                    ok = 1;
                    break;
                }
            }
            cout << (ok?"YES":"NO") << ' ';
        }
        cout << '\n';
    }
}