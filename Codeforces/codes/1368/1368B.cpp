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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    lli k;
    cin>>k;
    if(k==1) {
        cout<<"codeforces"<<endl;
        return 0;
    }
    int x=100, i;
    for(i=2;x>10;i++){
        lli te = k;
        x=0;
        while(te) te/=i, x++;
    }
    x = i-1;
    lli te = 1;
    FOR(i, 10) te*=x-1;
    vi ans(10, x-1);
    FOR(i, 10){
        if(te>=k) break;
        ans[i]++, te = (te/(ans[i]-1))*ans[i];
    }
    string s = "codeforces";
    FOR(i, 10) FOR(j, ans[i]) cout<<s[i];
    cout<<endl;
}