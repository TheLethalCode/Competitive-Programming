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
random_device rd;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
// %

int ask(int x, int ty=0){
    if(x >= 1e9){
        return 0;
    }
    cout << (ty?"? ":"> ") << x << endl;
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
    int max = 0;
    for(int i=29;i>=0;i--){
        if(ask(max+(1<<i))){
            max += 1<<i;
        }
    }
    max++;
    vector< int > el;
    FOR(i, 30){
        el.pb(ask(uniform_int_distribution<int>(1, n)(mt), 1));
    }
    el.pb(max);
    sort(el.begin(), el.end());
    int x = unique(el.begin(), el.end()) - el.begin(), d = 0;
    FOR(i, x){
        FOR(j, i){
            d = __gcd(d, el[i]-el[j]);
        }
    }
    cout << "! " << max - (n-1)*d << " " << d << endl;
}