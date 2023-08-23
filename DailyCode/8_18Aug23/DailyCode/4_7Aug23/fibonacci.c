#include<stdio.h>


int fibonacci(int n,int * steps){
    (*steps)++;
    if(n<2){
        return n;
    }else{
        return fibonacci(n-1,steps)+fibonacci(n-2,steps);
    }
}

int main(){
    int n;
    int steps = 0;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Fibonacci of the %d is %d,%d",n,fibonacci(n,&steps),steps);
}