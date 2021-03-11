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

int ask(vector< int > &A, vector< int > &B) {
    cout << "? " << A.size() << " " << B.size() << endl;
    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;
    for (int x : B) {
        cout << x << " ";
    }
    cout << endl;
    int a;
    cin >> a;
    return !!a;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< int > A, B;
        set< int > S;
        for (int i = 0; i < n; i++) {
            S.insert(i+1);
        }
        
        A.pb(1);
        int dem = -1;
        for (int i = 2; i <= n; i++) {
            B.pb(i);
            if (ask(A, B)) {
                dem = i;
                S.erase(i);
                break;
            }
            B.pop_back();
            A.pb(i);
        }

        A.clear();
        for (int j = dem + 1; j <= n; j++) {
            A.pb(j);
            if (ask(A, B)) {
                S.erase(j);
            }
            A.pop_back();
        }

        A.clear();
        int lo = 1, hi = dem - 1, mid = lo;
        while (lo < hi) {
            mid = lo + hi >> 1;
            A.resize(mid - lo + 1);
            iota(A.begin(), A.end(), lo);
            if (ask(A, B)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        S.erase(lo);

        cout << "! "<< S.size() << " ";
        for (int x : S) {
            cout << x << " ";
        }
        cout << endl;
    }   
}