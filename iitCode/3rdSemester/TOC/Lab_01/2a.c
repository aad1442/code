#include<stdio.h>
#include<math.h>

const char alpha[]={'0','1'};
const int alpha_size = 2;

void setOfStrings(int k){
    int l = (int)pow(2,k);
    printf("%d\n",l);
    char arr[l][k+1];
    for(int i=0;i<l;i++){
        int j;
        for( j=0;j<k;j++){
            arr[i][j]=alpha[0];
        }arr[i][j]='\0';
    }
    for(int i=0;i<l;i++){
        printf("%s",arr[i]);
    }
}

int main(){
    int k=3;
    setOfStrings(k);
}