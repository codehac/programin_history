#include<bits/stdc++.h>
using namespace std;
int cum[1000006];
void pre(){
cum[2]=1;
cum[3]=2;
for(int i=4;i<=1000006;i++){
    if(i%2==0)
        cum[i]=cum[i-1];
    else
        cum[i]=cum[i-1]+1;
}
}
void find_solution(int n){
   printf("%d\n",cum[n]);
}
 int main(){
  int n,t;
  pre();
  scanf("%d",&t);

  while(t--){
    scanf("%d",&n);
    find_solution(n);
  }
 return 0;
 }
