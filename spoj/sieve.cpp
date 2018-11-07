#include <bits/stdc++.h>
#define MAX 10000009
using namespace std;
bool p_[MAX];
int cum[MAX];
void calculate(){
	 	 for( int i = 3; i*i < MAX; i += 2 ){
	        if( p_[i]==false){
	      for( int j = i*i; j <=MAX; j += i+i ){
	        p_[j] = true;
           }
        }
    }
    cum[2]=1;
    for(int i=3;i<=MAX;i++){
        if(p_[i]==false && i%2!=0)
            cum[i]=cum[i-1]+1;
        else
            cum[i]=cum[i-1];
    }
}
void SieveOfEratosthenes(int n)
{
   printf("%d\n",cum[n]-cum[n>>1]);
}

int main()
{
int t,n;
calculate();
scanf("%d",&t);
while(t--){
	scanf("%d",&n);
	SieveOfEratosthenes(n);
}
	return 0;
}

