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
lli a, b, m;
int q, i;
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--){
        cin >> a >> b >> m;
        if(a == b){
            cout << 1 << ' ' << a << '\n';
            continue;
        }
        for(i=0;(a+m<<i)<b;i++);
        if((a+1<<i)>b){
            cout << -1 << '\n';
            continue;
        }
        cout << i+2 << ' ';
        b -= a+1<<i;
        vector< lli > v(i+1, 1), ans(i+2, 0);
        for(int j=i-1;j>=0;j--){
            lli temp = min(b/(1LL<<j), m-1);
            v[i-j-1] += temp;
            b -= temp<<j;
        }
        v[i] += b;
        cout << (ans[0]=a) << ' ';
        for(int j=1;j<=i+1;j++){
            for(int k=0;k<j;k++){
                ans[j] += ans[k];
            }
            ans[j] += v[j-1];
            cout << ans[j] << ' ';
        }
        cout << '\n';
    }
}