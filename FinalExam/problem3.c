#include <stdio.h>
int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int a[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int flag=1;
    if(col!=row){
        flag=0;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if((i==j || i+j==row-1) && a[i][j]!=1){
                flag=0;
            }else if ((i!=j && i+j!=row-1)&& a[i][j]!=0)
            {
                flag=0;
            }
            
        }
    }
    if(flag==1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}