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

int n, m, a, b, t, q, ok, cnt;
lli k, r, x, y, z, ans;

struct trip{
    int i, j, k;
    lli cur;
    trip(){
        cur = -1e18;
    }
    void ass(lli val, int _i, int _j, int _k){
        if(val > cur){
            cur = val;
            i = _i;
            j = _j;
            k = _k;
        }
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector< lli > v(n), pref(n+2);
    vector< pair< lli, int > > ans(n+1);
    FOR(i, n){
        cin >> v[i];
        pref[i+1] = pref[i] + v[i];
    }
    for(int i=0;i<=n;i++){
        lli temp = -1e18;
        for(int j=i;j<=n;j++){
            if(temp < pref[j]-pref[i] - (pref[n]-pref[j])){
                temp = pref[j]-pref[i] - (pref[n]-pref[j]);
                ans[i] = {temp, j};
            }
        }
    }
    trip s;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            lli cur = pref[i]-pref[0] - (pref[j]-pref[i]) + ans[j].fi;
            s.ass(cur, i, j, ans[j].se);
        }
    }
    cout << s.i << ' ' << s.j << ' ' << s.k << '\n';
}