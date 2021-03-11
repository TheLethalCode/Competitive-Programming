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
    int n;
    cin >> n;
    vector< int > v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v.pb(mod);

    int prevMin = 0, prevMax = -1, larEq = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i-1] && v[i] < v[i+1]) {
            if (prevMax - prevMin == i - prevMax && (i - prevMax) % 2 == 0){
                larEq = max(larEq, i - prevMax);
            }
            prevMin = i;
        } else if (v[i] > v[i-1] && v[i] > v[i+1]) {
            prevMax = i;
        }   
    }

    int largest = 0, cnt = 0, temp = 1;
    for (int i = 2; i < n + 1; i++, temp++) {
        if (((v[i] > v[i-1]) ^ (v[i - 1] > v[i-2])) || i == n) {
            if (temp == largest) {
                cnt++;
            } else if (temp > largest) {
                largest = temp;
                cnt = 1;
            }
            temp = 0;
        }
    }
    
    cout << (largest == larEq && cnt <= 2 ? "1\n" : "0\n");
}