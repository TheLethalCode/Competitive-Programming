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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

struct state{
    int i, j, k, vis;
    bool start;
    char ch;
    state *par;
    state() : start(false) {}
    void init(int x, int y, int z){
        i = x;
        j = y;
        k = z;
        vis = 1;
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t, br = "()";
    cin >> s >> t;
    int n = sz(s), m = sz(t), l=max(n, m);
    state dp[n+1][m+1][l+1];
    FOR(i, n+1){
        FOR(j, m+1){
            FOR(k, l+1){
                dp[i][j][k].init(i, j, k);
            }
        }
    }
    dp[0][0][0].start = true;
    s += '$';
    t += '#';
    queue< state* > que;
    que.push(&dp[0][0][0]);
    while(!que.empty()){
        state *cur = que.front();
        que.pop();
        if(cur->i==n && cur->j==m && !cur->k){
            string ans = "";
            while(!cur->start){
                ans += cur->ch;
                cur = cur->par;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
            return 0;
        }
        FORR(x, br){
            if((x == '(' && cur->k<l) || (x == ')' && cur->k)){
                int p = cur->i + (s[cur->i]==x), q = cur->j + (t[cur->j]==x), r = cur->k + (x=='('?1:-1);
                if(dp[p][q][r].vis){
                    dp[p][q][r].ch = x;
                    dp[p][q][r].par = cur;
                    dp[p][q][r].vis = 0;
                    que.push(&dp[p][q][r]);
                }
            }
        }
    }

}