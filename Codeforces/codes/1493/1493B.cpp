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
int h, m;
map< char, char > mp;


bool val(string s) {
    pair< int, int > in = {(s[0] - '0')*10 + s[1] - '0', (s[3] - '0')*10 + s[4] - '0'};
    return in.fi < h && in.se < m;
}

bool reflect(string s) {
    string ne = "00:00";
    for (int i = 0; i < 5; i++) {
        if (!mp.count(s[i])) {
            return false;
        }
        ne[4 - i] = mp[s[i]];
    }
    return val(ne);
}

string nex(string s) {
    pair< int, int > in = {(s[0] - '0')*10 + s[1] - '0', (s[3] - '0')*10 + s[4] - '0'};
    in.se++;
    if (in.se >= m) {
        in.se = 0;
        in.fi++;
    }
    if (in.fi >= h) {
        in.fi = 0;
        in.se = 0;
    }
    string te = "00:00";
    te[0] = in.fi / 10 + '0';
    te[1] = in.fi % 10 + '0';
    te[3] = in.se / 10 + '0';
    te[4] = in.se % 10 + '0';
    return te;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    mp['0'] = '0';
    mp['1'] = '1';
    mp['2'] = '5';
    mp['5'] = '2';
    mp['8'] = '8';
    mp[':'] = ':';
    while (t--) {
        cin >> h >> m;
        string s;
        cin >> s;
        while (true) {
            if (reflect(s)) {
                cout << s << '\n';
                break;
            }
            s = nex(s);
        }
    }
}