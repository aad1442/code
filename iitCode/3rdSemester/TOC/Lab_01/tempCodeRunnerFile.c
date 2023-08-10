#include<stdio.h>
int lengthCalculate(char* str){
    int size=0;
    while (str[size])size++;
    return size;
}
int isPalindome(char* a){
    for(int i=0;i<lengthCalculate(a);i++){
        if(a[i]!=a[lengthCalculate(a)-i])
            return 0;
    }
    return 1;
}
int main(){
    char a[]="11001100110011";
    if(isPalindome(a)){
        printf("It's Palindrome");
    }else{
        printf("It's not.");
    }

}