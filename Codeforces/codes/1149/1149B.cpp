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
#define MAXC 100005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
#define INF 0x3f3f3f3f
int ar[MAXC][26], last[26], dp[251][251][251], x;
char t;
string s;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    cin >> s;
    fill_n(last, 26, n+1);
    fill_n(ar[n+1], 26, n+1);
    for(int i=n;i >= 0; i--){
        FOR(j, 26){
            ar[i][j] = last[j];
        }
        i?last[s[i-1]-'a']=i:i;
    }
    vector< string > S(3, "");
    while(q--){
        cin >> t;
        if(t=='+'){
            cin >> x >> t;
            S[x-1] += t;
            int i = S[0].size(), j = S[1].size(), k = S[2].size();
            if(x==1){
                FOR(j, S[1].size()+1){
                    FOR(k, S[2].size()+1){
                        int _1 = i?ar[dp[i-1][j][k]][S[0][i-1]-'a']:INF;
                        int _2 = j?ar[dp[i][j-1][k]][S[1][j-1]-'a']:INF;
                        int _3 = k?ar[dp[i][j][k-1]][S[2][k-1]-'a']:INF;
                        dp[i][j][k] = min(_1, min(_2, _3));
                    }
                }
            }
            else if(x==2){
                FOR(i, S[0].size()+1){
                    FOR(k, S[2].size()+1){
                        int _1 = i?ar[dp[i-1][j][k]][S[0][i-1]-'a']:INF;
                        int _2 = j?ar[dp[i][j-1][k]][S[1][j-1]-'a']:INF;
                        int _3 = k?ar[dp[i][j][k-1]][S[2][k-1]-'a']:INF;
                        dp[i][j][k] = min(_1, min(_2, _3));
                    }
                }
            }
            else{
                FOR(i, S[0].size()+1){
                    FOR(j, S[1].size()+1){
                        int _1 = i?ar[dp[i-1][j][k]][S[0][i-1]-'a']:INF;
                        int _2 = j?ar[dp[i][j-1][k]][S[1][j-1]-'a']:INF;
                        int _3 = k?ar[dp[i][j][k-1]][S[2][k-1]-'a']:INF;
                        dp[i][j][k] = min(_1, min(_2, _3));
                    }
                }
            }
        }
        else{
            cin >> x;
            S[x-1].pop_back();
        }
        cout << (dp[S[0].size()][S[1].size()][S[2].size()] <= n? "YES" : "NO") << "\n";
    }
}