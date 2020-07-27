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
    map< char, char > mp1;
    mp1['R'] = 'P';
    mp1['P'] = 'S';
    mp1['S'] = 'R';
    cin >> t;
    while(t--){
        map< char, int > mp;
        string s;
        cin >> s;
        FORR(x, s){
            mp[x]++;
        }
        int val = 0;
        char x;
        FORR(el, mp){
            if(el.se > val){
                val = el.se;
                x = el.fi;
            }
        }
        FOR(i, s.size()){
            cout << mp1[x];
        }
        cout << '\n';
    }
}