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
int m, a, b;
struct data{
    bool exi;
    int ps, pt, pa, pb;
    data () : exi(false) {}
    void in(int s, int t, int a, int b){
        if(!exi){
            exi = true;
            ps = s;
            pt = t;
            pa = a;
            pb = b;
        }
    }
}dp[4][4][250][250];

void calC(){
    dp[0][0][0][0].in(0, 0, 0, 0);
    FOR(s, 3){
        FOR(t, 3){
            FOR(a, 201){
                FOR(b, 201){
                    if(dp[s][t][a][b].exi){
                        int gP = s+t==4?15:25;
                        FOR(k, gP-1){
                            dp[s+1][t][a+gP][b+k].in(s, t, a, b);
                            dp[s][t+1][a+k][b+gP].in(s, t, a, b);
                        }
                        for(int i=gP+1;a+i-2<=200 && b+i-2<=200;i++){
                            dp[s+1][t][a+i][b+i-2].in(s, t, a, b);
                            dp[s][t+1][a+i-2][b+i].in(s, t, a, b);
                        } 
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    calC();
    cin >> m;
    while(m--){
        cin >> a >> b;
        int s = -1, t = 3;
        FOR(i, 4){
            FOR(j, 4){
                if((i==3 || j==3) && dp[i][j][a][b].exi && i-j>s-t){
                    s = i;
                    t = j;
                }
            }
        }
        if(~s){
            cout << s << ":" << t << '\n';
            vector< pair< int, int > > ans;
            int pa, pb, ps, pt;
            while(s || t || a || b){
                pa = dp[s][t][a][b].pa;
                pb = dp[s][t][a][b].pb;
                ps = dp[s][t][a][b].ps;
                pt = dp[s][t][a][b].pt;
                ans.pb(a-pa, b-pb);
                a = pa;
                b = pb;
                s = ps;
                t = pt;
            }
            reverse(ans.begin(), ans.end());
            FORR(mat, ans){
                cout << mat.fi << ":" << mat.se << " ";
            }
            cout << '\n';
        }
        else{
            cout << "Impossible\n";
        }
    }
}