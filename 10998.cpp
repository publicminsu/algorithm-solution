#include <iostream>
using namespace std;
int notSelf(int n);
int main(){
    int arr[10001],i,j;
    for(i=1;i<10001;i++){
        j=notSelf(i);
        if(j<=10000)
        arr[j]=1;
    }
    for(i=1;i<10001;i++){
        if(arr[i]!=1)
        cout<<i<<endl;
    }
    return 0;
}
int notSelf(int n){
    int sum=n;
    while (n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}