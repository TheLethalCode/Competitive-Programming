#include <bits/stdc++.h>
using namespace std;
 
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,flag=1;
		scanf("%d%d",&a,&b);
		if(a==1)
		 a++;
		if(b==1)
		 b--;
		for(int i=a;i<=b;i++)
		{
		    flag=1;
			for(int j=2;j<=sqrt(i);j++)
			{
				if(i%j==0)
				 {flag=0;break;}
			}
			if(flag)
			 cout<<i<<endl;
		}
		cout<<endl;
	}
 
	return 0;
}