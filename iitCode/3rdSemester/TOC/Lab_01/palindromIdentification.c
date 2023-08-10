#include<stdio.h>
int lengthCalculate(char* str){
    int size=0;
    while (str[size])size++;
    return size;
}
int isPalindrome(char* a){
    for(int i=0;i<lengthCalculate(a);i++){
        if(a[i]!=a[lengthCalculate(a)-1-i])
            return 0;
    }
    return 1;
}

// int isPalindrome(char* a) {
//     int length = lengthCalculate(a);
//     for (int i = 0; i < length / 2; i++) {
//         if (a[i] != a[length - 1 - i])
//             return 0;
//     }
//     return 1;
// }

int main(){
    char a[]="11001100110011";
    if(isPalindrome(a)){
        printf("\nIt\'s Palindrome\n");
    }else{
        printf("\nIt\'s not.\n");
    }

}