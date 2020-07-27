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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
string s = "abacaba", temp;
int n;
int chkCnt(){
    int cnt = 0;
    FOR(i, n-6){
        cnt += (temp.substr(i, 7)==s);
    }
    return cnt;
}

void fill(){
    FOR(i, n){
        if(temp[i] == '?'){
            temp[i] = 'x';
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int cur = 0, fl = 0;
        cin >> n >> temp;
        fl = chkCnt();
        if(!fl){
            FOR(i, n){
                vector< int > ind;
                int j = 0;
                for(;j<7 && i+j<n;j++){
                    if(temp[i+j] == '?'){
                        temp[i+j] = s[j];
                        ind.pb(i+j);
                    }
                    if(temp[i+j]!=s[j]){
                        break;
                    }
                }
                if(j==7 && (fl=chkCnt())==1){
                    break;
                }
                while(ind.size()){
                    temp[ind.back()]='?';
                    ind.pop_back();
                }
            }
        }
        if(fl==1){
            fill();
            cout << "YES\n" << temp << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
}