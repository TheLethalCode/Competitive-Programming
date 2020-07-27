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

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    string s;
    cin>>s;

    bool flag = true;
    string cur = s;
    while(flag)
    {
        int k = cur.size();
        int ma = -1, ind = -1;
        for(int i=1;i<k-1;i++)
        {
            if(cur[i-1] + 1 == cur[i] || cur[i+1] + 1 == cur[i])
                if(cur[i]>ma)
                    ma = cur[i], ind = i;
        }
        if(k > 1)
        {
            if(cur[0] == cur[1] + 1)
                if(cur[0]>ma)
                    ma = cur[0], ind = 0;
            if(cur[k-1] == cur[k-2] + 1)
                if(cur[k-1]>ma)
                    ma = cur[k-1], ind = k-1;
        }
        if(ind != -1)
        {
            string temp = "";
            for(int i=0;i<k;i++)
                if(i!=ind)
                    temp += cur[i];
            cur = temp;
        }
        else
            flag = false;
    }
    cout<<n-cur.size()<<endl;
}