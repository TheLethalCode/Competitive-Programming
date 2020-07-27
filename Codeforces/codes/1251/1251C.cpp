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
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define xors ^

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string odd = "", even = "";
        for(auto x : s)
        {
            if((x - '0') perc 2) odd += x;
            else even += x;
        }
        string ans = "";
        int n = odd.length(), m = even.length();
        int i = 0, j =0;
        while(i < n && j < m)
            if(odd[i] < even[j])
                ans+=odd[i++];
            else
                ans+=even[j++];
        while(i != n)
            ans += odd[i++];
        while(j != m)
            ans += even[j++];
        cout<<ans;nl;
    }
}