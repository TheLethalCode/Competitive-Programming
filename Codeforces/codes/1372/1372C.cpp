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
int ar[MAXC];
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        FOR(i, n){
            cin >> ar[i];
            ar[i]--;
        }
        int l = 0, r = n-1;
        while(l < n  && ar[l]==l) l++;
        while(r >= 0 && ar[r]==r) r--;
        if(l == n){
            cout << 0 << "\n";
            continue;
        }
        int ok = 0;
        while(l <= r){
            if(ar[l] == l){
                ok = 1;
                break;
            }
            l++;
        }
        if(ok){
            cout << 2 << "\n";
            continue;
        }
        cout << 1 << "\n";
    }
}