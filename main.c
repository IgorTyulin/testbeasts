#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int pole[SIZE][SIZE];
    char arr[SIZE*SIZE];
    int kor[n*m][2];
    int zn = 0;
    int x = 0, y = 0;
    int per = 0;
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            scanf("%s", arr);
            if(arr[0] == 'S')
            {
                pole[i][j] = 0;
                x = i; y = j;
                continue;
            }
                zn = 0;
                for(int k = 0; k<strlen(arr); k++)
                    zn = zn*10 + arr[k]-48;
            
                pole[i][j] = zn;
            }
    }
    
    
     for(int i = x; i<n; i++)
     {
         pole[i+1][y] = pole[i][y] + pole[i+1][y];
         
     }
    for(int i = y; i<m; i++)
    {
        pole[x][i+1] = pole[x][i] + pole[x][i+1];
    }

    for(int i = x+1; i<n; i++)
    {
        for(int j = y+1; j<m; j++)
        {
            if(pole[i-1][j] > pole[i][j-1])
                per = pole[i-1][j];
            else
                per = pole[i][j-1];
            pole[i][j] = pole[i][j] + per;
                
        }
    }
    
    int i = n-1; int j = m-1;
    int k=0;
    kor[k][0] = i;
    kor[k][1] = j;
    k++;
    while(i!=x || j!=y)
    {
        if(i>x && ((pole[i-1][j] >= pole[i][j-1]) || j == y))
        {
            kor[k][0] = i-1;
            kor[k][1] = j;
            k++;
            i--;
        
        }
        else if(j>y )
        {
            kor[k][0] = i;
            kor[k][1] = j-1;
            k++;
            j--;
        }
    }
    
    
    printf("Path:\n");
    
    for(int i=k-1; i>=0; i--)
    {
        printf("(%d,%d) ", kor[i][0], kor[i][1]);
    }
    printf("\n");
    printf("Coins: %d", pole[n-1][m-1]);
    return 0;

}
