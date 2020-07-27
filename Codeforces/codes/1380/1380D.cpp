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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, m, A[MAXC];
lli ans = 0, x, k, y;

void solve(int l, int r){
    if(l == r-1){
        return;
    }
    int ma = 0, cnt = r-l-1;
    for(int i=l;i<=r;i++){
        ma = max(ma, A[i]);
    }
    if(cnt < k && ma > max(A[l], A[r])){
        cout << -1 << "\n";
        exit(0);
    }
    if(k*y < x){
        ans += ma > max(A[l], A[r])? x + (cnt-k)*y: cnt*y; 
    }
    else{
        ans += cnt/k*x + (cnt%k)*y;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> k >> y;
    vector< int > B(m);
    FOR(i, n){
        cin >> A[i+1];
    }
    FOR(i, m){
        cin >> B[i];
    }
    int cur = 0, prev = 0;
    for(int i=1; i<=n && cur<m; i++){
        if(A[i] == B[cur]){
            solve(prev, i);
            prev = i;
            cur++;
        }
    }
    if(cur != m){
        cout << -1 << "\n";
        return 0;
    }
    solve(prev, n+1);
    cout << ans << "\n";
}