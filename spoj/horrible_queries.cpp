#include<bits/stdc++.h>
using namespace std;
long long bit[100005];
long long bit1[100005];
void update(long long *b ,int ind,long long val,int n){
    while(ind<=n){
        b[ind]+=val;
        ind+=(ind&-ind);
    }
}
long long query(long long *b,int ind){
 long long sum=0;
 while(ind>0){
    sum+=b[ind];
    ind-=(ind&-ind);
 }
 return sum;
}

int main(){
int t,n,q;
int x,y,z;
long long w;
scanf("%d",&t);
while(t--){
 scanf("%d%d",&n,&q);
   memset(bit,0,(n+1)*sizeof(long long));
   memset(bit1,0,(n+1)*sizeof(long long));

while(q--){
       // printf("hello");
   scanf("%d%d%d",&x,&y,&z);
   if(x==0){
     scanf("%lld",&w);
     update(bit,y,w,n);
     update(bit,z+1,-w,n);
     update(bit1,y,w*(y-1),n);
     update(bit1,z+1,-w*z,n);
   }
   else{
      long long res=query(bit,z)*z-query(bit1,z);
      long long res1=query(bit,y-1)*(y-1)-query(bit1,y-1);
      res=res-res1;
      printf("%lld\n",res);
   }
}

}
return 0;
}
