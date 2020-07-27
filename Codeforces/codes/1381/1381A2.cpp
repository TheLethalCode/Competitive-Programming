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
string s, t;
int n;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        cin >> n;
        int first = 0, cur = n-1, in = 0;
        cin >> s >> t;
        vector< int > ans;
        for(int i = n-1;i>=0;i--){
            if((s[cur]^in)!=t[i]){
                if((s[cur]^in) != (s[first]^in)){
                    ans.pb(1);
                }
                ans.pb(i+1);
                in = !in;
                swap(cur, first);
            }
            in?cur++:cur--;
        }
        cout << ans.size() << ' ';
        FORR(x, ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}