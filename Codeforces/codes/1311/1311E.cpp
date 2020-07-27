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
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, d, cur = 1, tot = 0;
        cin>>n>>d;
        vector< int > dep(n+2, 0);
        dep[0] = 1;
        for(int i=1;cur < n;i++){
            dep[i] = min(2*dep[i-1], n-cur);
            cur += dep[i];
            tot += dep[i] * i;
        }
        if(d < tot || d > n*(n-1)/2){
            cout << "NO\n" ;
            continue;
        }
        while(tot < d){
            int  i;
            for(i=1;2*(dep[i]-1) < dep[i+1]+1;i++);
            tot++;
            dep[i]--;
            dep[i+1]++;
        }
        cout << "YES\n" ;
        int cnt = 0, prev = 1, amt = 1;
        for(int i=1;i<=n;i++){
            FOR(j, dep[i]){
                cout << prev << " ";
                cnt++;
                if(cnt == 2){
                    cnt = 0;
                    prev++;
                }
            }
            amt += dep[i-1];
            prev = amt;
            cnt = 0;
        }
        cout << "\n" ;
    }
}