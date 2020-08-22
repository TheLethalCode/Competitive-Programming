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
    vector< int > v(n), prime;
    vector< bool > check(MAXC, 1);
    check[0] = check[1] = 0;
    for(int i=2;i<MAXC;i++){
        if(check[i]){
            prime.pb(i);
            for(lli j = 1LL*i*i;j<MAXC;j+=i){
                check[j] = 0;
            }
        }
    }
    int sm = mod, bi = 0;
    FOR(i, n){
        cin >> v[i];
        sm = min(sm, v[i]);
        bi = max(bi, v[i]);
    }
    vector< bool > fin(bi - sm + 1, 1);
    FORR(num, prime){
        int st = (sm + num - 1) / num * num;
        for(lli j = max(1LL*num*num, 1LL*st); j <= bi; j+=num){
            fin[j - sm] = 0;
        }
    }
    if(sm == 1){
        fin[0] = 0;
    }
    int ans = 0, temp = 0;
    FOR(i, n){
        v[i] = fin[v[i] - sm];
        if(v[i]){
            temp++;
        }
        else{
            ans = max(ans, temp);
            temp = 0;
        }
    }
    cout << max(ans, temp) << '\n';
}