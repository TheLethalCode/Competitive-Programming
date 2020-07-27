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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin >> s;
        sort(all(s));
        if(s[k-1]!=s[0]){
            cout << s[k-1] << "\n";
            continue;
        }
        if(s[k] == s[n-1]){
            FOR(i, n){
                if(i % k == 0){
                    cout<<s[i];
                }
            }
            cout << "\n";
            continue;
        }
        cout<< string(1, s[0]) + s.substr(k) << "\n";
    }
}