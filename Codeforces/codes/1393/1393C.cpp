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
int n, x;
vector< int > amt, ord;
bool can(int ans){
    if(ans >= n-1){
        return false;
    }
    vector< int > A;
    FOR(i, ans + 1){
        int cnt = 0;
        for(int j = i; j < n; j += ans+1){
            cnt++;
        }
        A.pb(cnt);
    }
    FOR(i, min(ord.size(), A.size())){
        if(A[i] < amt[ord[i]]){
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        amt.assign(n+1, 0);
        ord.clear();
        FOR(i, n){
            cin >> x;
            amt[x]++;
            if(amt[x] == 1){
                ord.pb(x);
            }
        }
        sort(ord.begin(), ord.end(), [&](int x, int y){
            return amt[x] > amt[y];
        });
        int ans = 0;
        for(int i = 18;i>=0;i--){
            if(can(ans + (1<<i))){
                ans += 1<<i;
            }
        }
        cout << ans << '\n';
    }
}