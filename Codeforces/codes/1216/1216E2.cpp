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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
// % ;

vli pow_10(10,1);

lli sume(lli n)
{
    return n%2?((n+1)/2)*n:(n/2)*(n+1);
}

lli calc_sum_n(lli n)
{
    lli sum = 0;
    lli j=n,i=0;
    while(j)
    {
        sum += sume(n-pow_10[i]+1);
        j/=10,i++;
    }
    return sum;
}

lli calc_v_n(lli n)
{
    lli v = 0;
    lli j=n,i=0;
    while(j)
    {
        v += n - pow_10[i] + 1;
        j/=10,i++;
    }
    return v;
}

int main(int argc, char **argv)
{
    crap;
    for(int i=1;i<=9;i++)
        pow_10[i] = pow_10[i-1]*10;

    int q;
    cin>>q;
    while(q--)
    {
        lli n ;
        cin >> n;
        lli l=1, r= 5*1e8;
        lli mid,ans,j,k;
        vi temp;
        while(r-l > 1)
        {
            mid = l + r >> 1;
            // cout<<calc_sum_n(l)<<" "<<calc_sum_n(mid)<<" "<<calc_sum_n(r)<<endl;
            if(calc_sum_n(mid) == n)
            {
                cout<<mid%10;
                goto done;
            }
            else if(calc_sum_n(mid) < n)
                l=mid;
            else r=mid;
        }
        ans = calc_sum_n(r)<=n?r:r-1;
        // cout<<l;
        if(calc_sum_n(ans) == n)
        {
            cout<<ans%10;
            goto done;
        }
        n -= calc_sum_n(ans);
        // cout<<n<<endl;

        l=1, r=ans+1;
        while(r - l > 1)
        {
            mid = l + r >> 1;
            if(calc_v_n(mid) == n)
            {
                cout<<mid%10;
                goto done;
            }
            else if(calc_v_n(mid) < n)
                l=mid;
            else r=mid;
        }
        ans = calc_v_n(r)<=n?r:r-1;
        if(calc_v_n(ans) == n)
        {
            cout<<ans%10;
            goto done;
        }
        n-= calc_v_n(ans);

        j = n, k = ans + 1;
        while(k)
            temp.push_back(k%10),k/=10;
        reverse(temp.begin(),temp.end());
        cout<<temp[j-1];
        done:cout<<endl;
    }

}