#include<bits/stdc++.h>
using namespace std; main(){string s;cin>>s;while(cin>>s){cout<<(s.size()>10?s[0]+to_string(s.size()-2)+s[s.size()-1]:s)<<endl;}}
#include<stdio.h>
int main()
{
    int n;
    int mat[n][3];
    int count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&mat[i][0],&mat[i][1],&mat[i][2]);
        if((mat[i][0]+mat[i][1]+mat[i][2])>1)
            count++;
    }
    printf("%d",count);
}