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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, fl=1;
        cin >> n;
        string s;
        cin >> s;
        vector< int > c(26);
        FORR(x, s){
            c[x-'a']++;
        }
        FOR(i, 26){
            if(c[i]&1){
                fl=0;
                break;
            }
        }
        cout << ( fl? "YES" : "NO" ) << '\n';
    }
}