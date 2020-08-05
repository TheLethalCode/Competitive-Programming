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
        int n, cnt = 1;
        string s;
        cin >> n >> s;
        vector< int > ans(n);
        set< int > S[2];
        FOR(i, n){
            S[s[i]-'0'].insert(i);
        }
        FOR(i, n){
            if(!ans[i]){
                int prev = s[i] - '0', next = prev ^ 1, ind = i-1;
                while(!S[prev].empty() && *S[prev].rbegin() > ind){
                    ind = *S[prev].lower_bound(ind+1);
                    S[prev].erase(ind);
                    ans[ind] = cnt;
                    swap(prev, next);
                }
                cnt++;
            }
        }
        cout << cnt - 1 << '\n';
        FORR(x, ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}