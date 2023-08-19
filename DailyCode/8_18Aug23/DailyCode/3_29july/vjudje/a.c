#include<stdio.h>

void swap(long unsigned int *xp,long unsigned int *yp) {
   long unsigned int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(long unsigned int arr[],long unsigned int n) {
   long unsigned int i, j;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place, so we reduce the inner loop range accordingly.
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element.
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(){
   long unsigned int nAppli, nAppart, dif;
    scanf("%lu%lu%lu",&nAppli,&nAppart, &dif);
   long unsigned int nAppli_size[nAppli],nAppart_size[nAppart];
    for(int i=0;i<nAppli;i++){
        scanf("%lu",&nAppli_size[i]);
    }
    for(int i=0;i<nAppart;i++){
        scanf("%lu",&nAppart_size[i]);
    }

    bubbleSort(nAppart_size,nAppart);
    bubbleSort(nAppli_size,nAppli);
   long unsigned int count =0;

    for(int i=0;i<nAppli;i++){
        for(int j=0;j<nAppart;j++){
            if((nAppli_size[i]>=(nAppart_size[j]-dif))&&(nAppli_size[i]<=(nAppart_size[j]+dif))){
                count++;
                nAppart_size[j]=0;
                continue;
            }
        }
    }

    printf("%lu",count);
}