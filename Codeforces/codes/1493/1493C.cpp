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
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k) {
            cout << "-1\n";
            continue;
        }

        int in[n+1][26];
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                in[i + 1][j] = in[i][j];
            }
            in[i + 1][s[i] - 'a']++;
        }
        int ok = 1;
        for (int i = 0; i < 26; i++) {
            if (in[n][i] % k) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << s << '\n';
            continue;
        }

        for (int i = n - 1; i >= 0; i--) {
            vector< int > rem(26), remCpy;
            int sum = 0;
            for (int j = 0; j < 26; j++) {
                int val = in[i][j] % k;
                if (val) {
                    rem[j] = k - val;
                    sum += rem[j];
                }
            }
            remCpy = rem;

            for (int j = s[i] - 'a' + 1; j < 26; j++, remCpy = rem) {
                int sumNew = sum;
                remCpy[j]--, sumNew--;
                if (remCpy[j] < 0) {
                    remCpy[j] += k;
                    sumNew += k;
                }
                
                int temp = (n - i - 1) - sumNew, up = i + 1;
                if (temp < 0 || temp % k) {
                    continue;
                }

                s[i] = j + 'a';
                remCpy[0] += temp;
                for (int i = 0; i < 26; i++) {
                    while (remCpy[i]) {
                        s[up++] = 'a' + i;
                        remCpy[i]--;
                    }
                }
                cout << s << '\n';
                goto lab;  
            }            
        }
        lab:;
    }
}