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

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
string solve(string s, string t){
    
    int n = s.length();
    vi a(n,0);
    a[0]=t[0]-s[0]-1;
    for(int i=1;i<n;i++)
        a[i]='z'-s[i];
    for(int i=1;i<n;i++)
        a[i]+=t[i]-'a';
    for(int i=n-1;i>0;i--)
        a[i-1]+=(a[i]>=26), a[i]%=26;

    a[n-1] = (a[n-1]+1)/2;
    for(int i=n-2;i>=0;i--)
        a[i+1] += 13*(a[i]&1), a[i]/=2;
    
    string ans(n, 'a');
    for(int i=n-1;i>0;i--){
        a[i-1]+=(s[i]-'a'+a[i]>=26);
        ans[i] = 'a' + (s[i]-'a' + a[i])%26;
    }
    ans[0] = s[0]+a[0];
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    int i=0;
    while(s[i]==t[i])i++;
    string ans = s.substr(0,i) + solve(s.substr(i), t.substr(i));
    cout<<ans<<endl;
}