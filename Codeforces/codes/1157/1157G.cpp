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
#define MAXC 205
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int ar[MAXC][MAXC], col[MAXC], row[MAXC], n, m, x;

void solve(int res){
    int ok = 0;
    FOR(i, n-1){
        int st = 0, en = m-1;
        while(st<m-1 && (ar[i][st]^col[st])==(ar[i][st+1]^col[st+1])){
            st++;
        }
        while(en && (ar[i][en]^col[en])==(ar[i][en-1]^col[en-1])){
            en--;
        }
        if(st < en-1){
            return;
        }
        if(st == en-1){
            if(ok){
                return;
            }
            ok++;
            row[i] = ar[i][0]^col[0];
            continue;
        }
        row[i] = ok?1-ar[i][0]^col[0]:ar[i][0]^col[0];
    }
    if(ok <= res){
        cout << "YES\n";
        FOR(i, n){
            cout << row[i];
        }
        cout << '\n';
        FOR(j, m){
            cout << col[j];
        }
        cout << '\n';
        exit(0);   
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, n){
        FOR(j, m){
            cin >> ar[i][j];
        }
    }
    FOR(i, m+1){
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        FOR(j, m){
            col[j] = j<i?ar[n-1][j]:1-ar[n-1][j];
        }
        solve((i==0) || (i==m));
    }
    cout << "NO\n";
}