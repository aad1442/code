#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char name[100];
        int p;

        scanf("%s",name);
        // printf("%s",name);
        p=strlen(name);
        if(p>10){
            //printf("%d",p);
            printf("%c%d%c\n",name[0],p-2,name[p-1]);
        }else{
            puts(name);
        }

    }
}