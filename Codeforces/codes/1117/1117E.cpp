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
int W = 3;
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t, ans;
    cin >> t;
    int n = t.size();
    ans.resize(n);
    map< int , string > mp;
    map< string, int > Imp;
    vector< string > q(3, ""), r(3, "");
    int cnt = 0;
    FOR(i, 26){
        FOR(j, 26){
            FOR(k, 26){
                string temp = "aaa";
                q[0] += temp[0] += i;
                q[1] += temp[1] += j;
                q[2] += temp[2] += k;
                Imp[temp] = cnt++;
                if(cnt == n){
                    goto brk;
                }
            }
        }
    }
    brk:;
    while(W--){
        cout << "? " << q[W] << endl;
        cin >> r[W];
    }
    FOR(i, n){
        mp[i] = string(1, r[0][i]) + string(1, r[1][i]) + string(1, r[2][i]);
        ans[Imp[mp[i]]] = t[i];
    }
    cout << "! " << ans << endl;
}