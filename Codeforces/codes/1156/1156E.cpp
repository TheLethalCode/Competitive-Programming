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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, ar[MAXC], pos[MAXC], L[MAXC], R[MAXC], ans = 0;
vector< int > v;
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.pb(MAXC);
    FOR(i, n){
        cin >> ar[i+1];
        pos[ar[i+1]] = i+1;
        while(v.back() < ar[i+1]){
            R[v.back()] = i;
            v.pop_back();
        }
        v.pb(ar[i+1]);
    }
    while(v.size() > 1){
        R[v.back()] = n;
        v.pop_back();
    }
    for(int i=n;i;i--){
        while(v.back() < ar[i]){
            L[v.back()] = i+1;
            v.pop_back();
        }
        v.pb(ar[i]);
    }
    while(v.size() > 1){
        L[v.back()] = 1;
        v.pop_back();
    }
    for(int i = 1; i<=n; i++){
        if(R[i] - pos[i] < pos[i] - L[i]){
            for(int j = pos[i]+1; j <= R[i]; j++){
                if(pos[i-ar[j]] < pos[i] && pos[i-ar[j]] >= L[i]){
                    ans++;
                }
            }
        }
        else{
            for(int j = pos[i]-1; j >= L[i]; j--){
                if(pos[i-ar[j]] > pos[i] && pos[i-ar[j]] <= R[i]){
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}