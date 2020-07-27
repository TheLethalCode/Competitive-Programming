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


#define perc %
int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, k, sum=0;
        cin>>n>>k;
        vi v(n);
        FOR(i, n) cin>>v[i];
        sort(all(v));
        int i = 0;
        while(i<n && v[i] <= k) sum+=v[i], i++;
        if(i==n-1) sum+=v[i];
        else if(i<n-1){
            int temp = 0;
            for(;i<=n-3;i++) temp+=v[i]-k, sum+=k;
            if(temp >= v[n-2]-k) sum+=k + v[n-1] - ((temp-v[n-2]+k)&1);
            else {
                int var = v[n-2] - k - temp;
                sum += k + v[n-1] - var;
            }
        }
        cout<<sum<<endl;
    }
}