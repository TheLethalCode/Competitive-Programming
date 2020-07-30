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
        int n;
        cin >> n;
        if(n <= 30){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        set< int > S;
        S.insert(6);
        S.insert(10);
        S.insert(14);
        int sum = 6 + 10 + 14;
        if(S.count(n-sum)){
            cout << 6 << " " << 10 << " " << 15 << " " << n - sum - 1 << '\n';
        }
        else{
            cout << 6 << " " << 10 << " " << 14 << " " << n - sum << '\n';
        }
    }
}