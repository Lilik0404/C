#include <stdio.h>
#define INT_MAX 2147483647;
#define INT_MIN -2147483647;
int main() {
 int v[12]= {1, 5, 7, 2, 5, 7, 1, 2,8,9,9,1};
 int n=12;
 int minn=INT_MIN;
 int temp=INT_MAX;
 for(int i=0;i<n;i++)
    printf("\n%i",v[i]);
printf("\n");
 for(int i=0;i<n;i++){
     temp=INT_MAX;
    for(int j=0;j<n;j++){
        if(v[j]<temp&&v[j]>minn){
            temp=v[j];
        }
        if(v[j]==minn)
            printf("\n%i",minn);
    }

    minn=temp;
 }

  return 0;
}