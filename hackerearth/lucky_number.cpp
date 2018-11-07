#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long a[maxn];
int bit[maxn];
void update(int ind,int val){
  while(ind<=maxn){
    bit[ind]+=val;
    ind+=(ind&-ind);
  }
}
int query(int ind){
 int sum=0;
 while(ind>0){
  sum+=bit[ind];
  ind-=(ind&-ind);
 }
 return sum;
}
bool valid(long long val){

  int count=0;
  while(val>0){
    int rem=val%2;
    if(rem==1){
     count++;
    }
    val=val/2;
  }
  if(count==2)
    return true;

  return false;
}
int main(){
int n,q,t,x,y,z;
scanf("%d",&t);
while(t--){
  scanf("%d",&n);
  memset(bit,0,sizeof(bit));
  for(int i=1;i<=n;i++){
     scanf("%d",&a[i]);
     if(valid(a[i])){
        update(i,1);
     }
  }
  //for(int i=1;i<=n;i++)
  ////printf("%d ",bit[i]);
   // printf("\n");
  scanf("%d",&q);
  while(q--){
      scanf("%d%d%d",&x,&y,&z);
      if(x==1){
            if(valid(a[y])){
                update(y,-1);
            }
            a[y]=z;
            // for(int i=1;i<=n;i++)
             //   printf("%d ",bit[i]);
             //     printf("\n");
            if(valid(a[y]))
                update(y,1);
               //  for(int i=1;i<=n;i++)
               // printf("%d ",bit[i]);
              //  printf("\n");
      }
      else{
            if(y==z)
               printf("%d\n",0);
      else{
              int result=query(z)-query(y-1);
                printf("%d\n",result);
        }

      }
  }

}
return 0;
}
