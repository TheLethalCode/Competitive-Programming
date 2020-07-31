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
    string s;
    cin >> s;
    int n = s.length();
    set< int > S[n];
    FOR(i, n){
        if(s[i]!='.'){
            if(i){
                S[i-1].insert(s[i]);
            }
            if(i!=n-1){
                S[i+1].insert(s[i]);
            }
            S[i].insert(s[i]);
        }
    }
    FOR(i, n){
        if(S[i].size()==3){
            cout << "Yes\n";
            return 0; 
        }
    }
    cout << "No\n";
}