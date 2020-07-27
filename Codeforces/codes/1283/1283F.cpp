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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n-1), occ(n+1, 0), larg(n+1, 0);
    set < pair< int, int > > s;
    FOR(i, n){
        s.insert(make_pair(i+1, i+1));
        larg[i+1] = i+1;
    }
    FOR(i, n-1){
        cin >> v[i];
        occ[v[i]]++;
        s.erase(make_pair(v[i], v[i]));
    }
    cout << v[0] << "\n";
    for(int i=n-2;i>=0;i--){
        pair< int, int > x = *s.begin();
        s.erase(s.begin());
        cout << x.se << " " << v[i] << "\n";
        occ[v[i]]--;
        larg[v[i]] = max(larg[v[i]], x.fi);
        if(!occ[v[i]]){
            s.insert(make_pair(larg[v[i]], v[i]));
        }
    }
}