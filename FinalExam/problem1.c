#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);    

    while(t--){
        int n;
        scanf("%d", &n);

        char result[n+1];
        scanf("%s", result);

        int tigerWins=0, pathanWins=0;
        for(int i=0; i<n; i++){
            if(result[i]=='T'){
                tigerWins++;
            }else if(result[i]=='P'){
                pathanWins++;
            }
        }
        if(tigerWins>pathanWins){
            printf("Tiger\n");
        }else if(pathanWins>tigerWins){
            printf("Pathan\n");
        }else{
            printf("Drawn\n");
        }
    }

    return 0;
}