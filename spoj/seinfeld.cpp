#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
stack<int> a;
int main()
{
	string s;
	int i,j,n,b,c,d,e,ans,t=0;
	cin>>s;
	while(s[0]!='-')
	{
		t++;
		while(!a.empty())
			a.pop();
		for(i=0;i<s.size();i++)
		{
			if(a.empty())
				a.push(int(s[i])-123);
			else
				if(s[i]=='}')
				{
					if(a.top()==0)
						a.pop();
					else
						a.push(int(s[i])-123);
				}
				else
					a.push(int(s[i])-123);
		}
		ans=0;
		while(!a.empty())
		{
			b=a.top();
			a.pop();
			if(b==a.top())
				ans=ans+1;
			else
				ans=ans+2;
			a.pop();
		}
		cout<<t<<". "<<ans<<endl;
		cin>>s;
	}
	return 0;
}
