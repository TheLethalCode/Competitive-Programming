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
    int n, p, ok=1;
    string s;
    cin >> n >> p >> s;
    FOR(i, p){
        for(int j=i+p;j<n;j+=p){
            if(s[j] != s[i] || s[j]=='.'){
                ok = 0;
                if(s[j] == '.' && s[i]=='.'){
                    s[j] = '0';
                    s[i] = '1';
                }
                else if(s[j] == '.'){
                    s[j] = s[i] xor 1;
                }
                else if(s[i] == '.'){
                    s[i] = s[j] xor 1;
                }
                break;
            }
        }
        if(!ok){
            FORR(x, s){
                cout << (x=='.'?'0':x);
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "No\n";
}