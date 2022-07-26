#include <iostream>
using namespace std;
int fibonacci(int n);
int numVec[40]={1,1,};
int main(){
    for(int z = 2; z<40; z++) numVec[z] = numVec[z-1] + numVec[z-2];
    int i;
    cin>>i;
    while(i>0){
        int j=0;
        cin>>j;
        if(j==1) cout<<"0 1";
        else if(j==0) cout<<"1 0";
        else cout<<numVec[j-2]<<" "<<numVec[j-1];
        cout<<endl;
        i--;
    }
    return 0;
}