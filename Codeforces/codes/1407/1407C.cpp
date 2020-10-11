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

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int a;
    cin >> a;
    return a;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans[n+1];
    set < int > S;
    for (int i = 0; i < n; i++) {
        S.insert(i+1);
    }
    int sum = 0;
    while (S.size() > 1) {
        int x = *S.begin(), y = *S.rbegin();
        int a = query(x, y), b = query(y, x);
        if (a > b) {
            ans[x] = a;
            S.erase(x);
            sum += a; 
        } else {
            ans[y] = b;
            S.erase(y);
            sum += b;
        }
    }
    ans[*S.begin()] = n * (n+1) / 2 - sum;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}