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
bool V[500][5001];
int N[500][5001];
pair< int , int > P[500][5001];
queue< pair< int , int > > Q;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D, S;
    cin >> D >> S;
    Q.push({0, 0});
    V[0][0] = true;
    while(!Q.empty()){
        pair< int, int > u = Q.front();
        Q.pop();
        if(!u.fi && u.se==S){
            string ans = "";
            while(u.fi || u.se){
                ans += N[u.fi][u.se]+'0';
                u = P[u.fi][u.se];
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
            return 0;
        }
        FOR(i, 10){
            int rem = (u.fi*10+i) % D, sum = u.se + i;
            if(sum <= S && !V[rem][sum]){
                V[rem][sum] = true;
                P[rem][sum] = u;
                N[rem][sum] = i;
                Q.push({rem, sum});
            }
        }
    }
    cout << -1 << '\n';
}