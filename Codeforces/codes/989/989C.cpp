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
    char G[50][50];
    int V[4];
    FOR(i, 4){
        cin >> V[i];
        V[i]--;
    }
    FOR(i, 48){
        FOR(j, 50){
            G[i][j] = 'A' + i/12;
        }
    }
    FOR(i, 4){
        int cnt = 0;
        while(V[i]){
            int r = 12 * ((i + 1) % 4) + 2 * (cnt/25) + 1;
            int c = 2 * (cnt % 25);
            G[r][c] = 'A' + i;
            V[i]--;
            cnt++;
        }
    }
    cout << "48 50\n";
    FOR(i, 48){
        FOR(j, 50){
            cout << G[i][j];
        }
        cout << '\n';
    }
}