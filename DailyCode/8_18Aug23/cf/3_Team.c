#include<stdio.h>
int main()
{
    int n;
    int count=0;
    scanf("%d",&n);
    int mat[n][3];
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&mat[i][0],&mat[i][1],&mat[i][2]);
        if((mat[i][0]+mat[i][1]+mat[i][2])>1)
            count++;
    }
    printf("%d",count);
}