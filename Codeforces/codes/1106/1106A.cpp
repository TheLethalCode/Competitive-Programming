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
    char arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    
    int cnt=0;
    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
        {
            if(arr[i][j] == 'X')
            {
                if(arr[i-1][j-1] == arr[i-1][j+1] && arr[i-1][j-1] == arr[i+1][j+1] && arr[i-1][j-1] == arr[i+1][j-1] && arr[i-1][j-1] == 'X')
                    cnt++;
            }
        }
    cout<<cnt<<endl;
}