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
     int X;
     cin >> X;
     for (lli i = 2; i <= 2*X; i+=2) {
         lli tot = i*i*(i*i-1)*(i*i-2)/6 - 4*(i-1)*(i-2)*(i*i-2);
         if (i >= 4) {
             tot += 4*(i-1)*(i-4);
             tot += 4*(i-2)*(i-4);
         }
         if (i >= 3) {
             tot += 4*(i-3)*(i-3);
             tot += 8*(i-3)*(i-2);
         }
         if (i >= 2) {
             tot += 8*(i-2)*(i-2);
         }
         cout << tot << '\n';
     }
 }