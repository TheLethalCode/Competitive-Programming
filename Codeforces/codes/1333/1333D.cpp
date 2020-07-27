#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int n, k, cnt=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vector< vi > ans;
    while(1){
        vi temp;
        int fl=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='R' && s[i+1]=='L') {
                temp.pb(i+1);
                s[i]='L';
                s[i+1]='R'; 
                i++, cnt++;
                fl=1;
            }
        }
        if(!fl) break;
        ans.pb(temp);
    }
    if(k < ans.size() || k > cnt) cout<<-1<<"\n";
    else{
        int rem = k - (int)ans.size(), i=0;
        while(rem){
            cout<<1<<" "<<ans[i].back()<<"\n";
            ans[i].pop_back(), rem--;
            if(ans[i].empty()) i++, rem++;
        }
        for(;i<ans.size();i++){
            cout<<ans[i].size()<<" ";
            for(int el : ans[i]) cout<<el<<" ";
            cout<<"\n";
        }
    }
}