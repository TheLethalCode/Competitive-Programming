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

int n, m, a, b, c, t, ok, V[MAXC];
lli k, r, x, y, z;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        ok = 1;
        string a, b;
        cin >> n;
        cin >> a >> b;
        vector< int > pos[26];
        FOR(i, n){
            pos[a[i]-'a'].pb(i);
        }
        int cnt = 0;
        FOR(i, 20){
            vector< int > temp;
            int which = 30;
            FORR(el, pos[i]){
                if(a[el] > b[el]){
                    cout << -1 << '\n';
                    goto done;
                }
                if(a[el] < b[el]){
                    temp.pb(el);
                    which = min(which, b[el]-'a');
                }
            }
            if(temp.size()){
                FORR(el, temp){
                    pos[which].pb(el);
                    a[el] = which + 'a';
                }
                cnt++;
            }
            temp.clear();
        }
        cout << cnt << '\n';
        done:;
    }
}