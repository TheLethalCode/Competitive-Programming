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
        string s, p;
        cin >> s >> p;
        vector< int > cnt(26);
        FORR(x, s){
            cnt[x-'a']++;
        }
        FORR(x, p){
            cnt[x-'a']--;
        }
        int tr = 0;
        for(int i=1;i < p.size();i++){
            if(p[i] != p[0]){
                tr = p[i] < p[0];
                break;
            }
        }
        FOR(i, p[0] - 'a' + 1 - tr){
            FOR(j, cnt[i]){
                cout << (char)(i + 'a');
            }
        }
        cout << p;
        for(int i = p[0]-'a'+1-tr; i<26;i++){
            FOR(j, cnt[i]){
                cout << (char)(i + 'a');
            }
        }
        cout << '\n';
    }
}