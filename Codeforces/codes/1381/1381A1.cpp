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

void op(string &s, int i){
    string temp = s.substr(0, i+1);
    reverse(temp.begin(), temp.end());
    FOR(j, i+1){
        s[j] = '0' + 1 - (temp[j]-'0');
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector< int > ans;
        for(int i = n-1;i>=0;i--){
            if(s[i]==t[i]){
                continue;
            }
            if(s[i] == s[0]){
                ans.pb(i+1);
                op(s, i);
                continue;
            }
            else{
                ans.pb(1);
                ans.pb(i+1);
                op(s, 0);
                op(s, i);
            }
        }
        cout << ans.size() << ' ';
        FORR(x, ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}