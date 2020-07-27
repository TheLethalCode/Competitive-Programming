#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n;
    cin>>n;
    vi v(1011,0);
    for(int i=0;i<n*n;i++)
    {
        int a;
        cin>>a;
        v[a]++;
    }
    int ans[n][n];
    int fl=1;
    if(n%2)
    {
        int cnt=1,num=0;
        for(int i=0;i<n/2 && fl;i++)
        {
            for(int j=0;j<n/2 && fl;j++)
            {
                while(v[cnt] < 4 && cnt<=1000)
                    cnt++;
                if(cnt>1000)
                {
                    fl=0;
                    break;
                }
                ans[i][j]=ans[i][n-j-1]=ans[n-1-i][j]=ans[n-1-i][n-1-j]=cnt;
                v[cnt]-=4;
            }
        }
        cnt=1;
        for(int i=0;i<n/2 && fl;i++)
        {
            while(v[cnt] < 2 && cnt<=1000)
                    cnt++;
            if(cnt>1000)
            {
                fl=0;
                break;
            }
            ans[i][n/2]=ans[n-1-i][n/2]=cnt;
            v[cnt]-=2;
        }
        for(int i=0;i<n/2 && fl;i++)
        {
            while(v[cnt] < 2 && cnt<=1000)
                    cnt++;
            if(cnt>1000)
            {
                fl=0;
                break;
            }
            ans[n/2][i]=ans[n/2][n-1-i]=cnt;
            v[cnt]-=2;
        }
        cnt=1;
        while(v[cnt] < 1 && cnt<=1000)
            cnt++;
        if(cnt>1000)
            fl=0;
        ans[n/2][n/2]=cnt;
        v[cnt]--;
    }
    else
    {
        int cnt=1,num=0;
        for(int i=0;i<n/2 && fl;i++)
        {
            for(int j=0;j<n/2 && fl;j++)
            {
                while(v[cnt] < 4 && cnt<=1000)
                    cnt++;
                if(cnt>1000)
                {
                    fl=0;
                    break;
                }
                ans[i][j]=ans[i][n-j-1]=ans[n-1-i][j]=ans[n-1-i][n-1-j]=cnt;
                v[cnt]-=4;
            }
        }
    }
    if(!fl)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }   
}