#include<iostream>
using namespace std;

int main(){
    int arr[5][30];
    
    for(int i=0;i<5;i++){
        
        int l=rand()%30;
        cout<<"Length of array:"<<i<<": "<<l<<endl;
        for(int j=0;j<l;j++){
            arr[i][j]=rand()%2;
            cout<<arr[i][j];
        }
    }
    
    for(int i=0;i<5;i++){
        printf("\n     %s     \n",arr[i]);
        int j=0;
        while(arr[i][j]!=NULL){
            cout<<"a"<<endl;
            j++;}
        cout<<"Length of array:"<<i<<": "<<j<<endl;
    }
    
}
