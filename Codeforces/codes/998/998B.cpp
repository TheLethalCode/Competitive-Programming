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
    int n, b;
    cin >> n >> b;
    vector< int > v(n), cnt(2), ind;
    FOR(i, n){
        cin >> v[i];
        cnt[v[i] & 1]++;
        if(i < n-1 && cnt[0] == cnt[1]){
            ind.pb(i);
        }
    }
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return abs(v[i+1] - v[i]) < abs(v[j+1] - v[j]);
    });
    int cost = 0, whi=0;
    FORR(i, ind){
        if(cost + abs(v[i] - v[i+1]) > b){
            break;
        }
        cost += abs(v[i] - v[i+1]);
        whi++;
    }
    cout << whi << '\n';
}