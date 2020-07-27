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

string s;
int count(string a)
{
    int temp=0;
    for(int i=0;i<a.size();i++)
        if(a[i]!=s[i])
            temp++;
    return temp;
}

int main()
{
    crap;
    int n;
    cin>>n;
    cin>>s;
    int ind,cnt=n;
    string ans;
    
    string temp1="",arr="BGR";
    for(int i=0;i<n/3;i++)
        temp1+=arr;
    for(int i=0;i<n%3;i++)
        temp1+=arr[i];

    string temp2="";
    arr="BRG";
    for(int i=0;i<n/3;i++)
        temp2+=arr;
    for(int i=0;i<n%3;i++)
        temp2+=arr[i];

    string temp3="";
    arr="RGB";
    for(int i=0;i<n/3;i++)
        temp3+=arr;
    for(int i=0;i<n%3;i++)
        temp3+=arr[i];

    string temp4="";
    arr="RBG";
    for(int i=0;i<n/3;i++)
        temp4+=arr;
    for(int i=0;i<n%3;i++)
        temp4+=arr[i];

    string temp5="";
    arr="GRB";
    for(int i=0;i<n/3;i++)
        temp5+=arr;
    for(int i=0;i<n%3;i++)
        temp5+=arr[i];

    string temp6="";
    arr="GBR";
    for(int i=0;i<n/3;i++)
        temp6+=arr;
    for(int i=0;i<n%3;i++)
        temp6+=arr[i];

    int t1=count(temp1);
    int t2=count(temp2);
    int t3=count(temp3);
    int t4=count(temp4);
    int t5=count(temp5);
    int t6=count(temp6);

    if(t1<cnt)
        ans=temp1,ind=1,cnt=t1;
    if(t2<cnt)
        ans=temp2,ind=2,cnt=t2;
    if(t3<cnt)
        ans=temp3,ind=3,cnt=t3;
    if(t4<cnt)
        ans=temp4,ind=4,cnt=t4;
    if(t5<cnt)
        ans=temp5,ind=5,cnt=t5;
    if(t6<cnt)
        ans=temp6,ind=6,cnt=t6;
    
    cout<<cnt<<endl;
    cout<<ans<<endl;
}