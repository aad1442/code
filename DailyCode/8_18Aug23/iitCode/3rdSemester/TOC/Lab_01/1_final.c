#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char alphabet[] = {'0', '1'};
const int alpha_size = 2;
#define maxLength 30
#define minLength 5

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateString(int length, char* str) {
    for (int i = 0; i < length; i++) {
        str[i] = alphabet[rand() % alpha_size];
    }
    str[length] = '\0';
}

int sizeCalculator(const char* str) {
    int size = 0;
    while (str[size]) {
        size++;
      
    }
    return size;
}

void alphabeCheck(char* str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]!=alphabet[0] && str[i]!=alphabet[1]){
            printf("Not From");
            return;
        }
        i++;
    }printf("From");
}

char* concatenatedStrings(char* a, char* b, char* c){
    int i,l1= sizeCalculator(a);
    int l2= sizeCalculator(b);
    for( i=0;i<l1;i++){
        c[i]=a[i];
    }
    for(int j=0;j<l2;i++,j++){
        c[i]=b[j];
    }c[i]='\0';

}

int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator with current time

    char* arr[5];

    for (int i = 0; i < 5; i++) {
        int length = generateRandomNumber(minLength, maxLength);

        // Allocate memory for arr[i] to hold the generated string
        arr[i] = (char*)malloc((length + 1) * sizeof(char));

        generateString(length, arr[i]);

        printf("%s - %d\n", arr[i], sizeCalculator(arr[i]));
    }
    //char a[]={'1','0','1'};
    char a[] = "110101011";
    alphabeCheck(a);
    char c[]="12345";
    char d[]="67890";
    int l=sizeCalculator(c)+sizeCalculator(d)+1;
    char b[l];
    concatenatedStrings(c,d,b);
    printf("b = %s\nc:%d,d:%d,b:%d,L:%d\n",b,sizeCalculator(c),sizeCalculator(d),sizeCalculator(b),l);
    // Free allocated memory
    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }

    return 0;
}
