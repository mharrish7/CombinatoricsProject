#include<iostream>
using namespace std;
int main(){
    int m;
    cin>> m;
    int *adj=new int[m*m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int ele;
            cin>>ele;
            *(adj+i*m+j)=ele;
        }
    }
    //Traversing
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int ele;
            ele=*(adj+i*m+j);
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
