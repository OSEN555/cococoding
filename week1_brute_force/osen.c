// 191112 osen
// incorrect code

#include <stdio.h>

int n;
int s[10][10];

//Making pairs with array p which contains existing pairs
int makepair(int p[10])
{
    int i, tmpr=0, start=-1; //Start student number
    for(i=0; i<n; i++)
    {
        if(!p[i])
        {
            start = i;
            break;
        }
    }
    
    if(start == -1) //All students make pairs
        return 1;
    {
        for(i=start+1; i<n; i++)
        {
            if(s[start][i] && !p[i])
            {
                p[start] = 1;
                p[i] = 1;
                tmpr += makepair(p); //Make pairs for the other students
                p[start] = 0; //Clean pair informantion for additional case
                p[i] = 0;
            }
        }
    }
    return tmpr;

}
    
    
int main()
{
    int c, m, l, i, j, s1, s2, cnt=0;
    int r[50];
    int p[10];
    scanf("%d", &c);
    
    for(l=0; l<c; l++)
    {
        scanf("%d %d", &n, &m);
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &s1, &s2);
            s[s1][s2] = 1;
            s[s2][s1] = 1;
        }
        
        r[l] = makepair(p);
        
        for(i=0; i<n; i++) 
        {
            p[i] = 0;
            for(j=0; j<n; j++)
                s[i][j] = 0;
        }
        
    }
    
    for(i=0; i<c; i++)
        printf("%d ", r[i]);

    return 0;
}
