#include<iostream>
#include <fstream>
using namespace std;
ifstream f("soarece.in");
ofstream g("soarece.out");

int sol[100][2],m,n,lin,col;
char a[20][20];
int index=0,i,j;

int vizitat(int k, int lin, int col)
{
    int v=0;
    for(i=1;i<=k;i++)
        if(sol[i][0]==lin && sol[i][1]==col)
            v=1;
    return v;
}
void tipar(int k, int lin, int col)
{
    int i;
    for(i=1;i<=n;i++)
    {
        for(j=1; j<=m;j++)
        {
            for(index=1; index<=k; index++)
            {
                if(a[i][j]==a[sol[index][0]][sol[index][1]])
                {
                    g<<index<<" ";
                    break;
                }
                else
                {
                    g<<"0 ";
                }
            }
        }
        g<<endl;
    }
}

void bk(int k, int lin, int col)
{
    if(a[lin][col]=='B')
        tipar(k,lin,col);
    else
    {
        sol[k][0]=lin;
        sol[k][1]=col;
        for(int i=1;i<=4;i++)
            switch(i)
        {
        case 1:
            if(a[lin-1][col]=='_' && !vizitat(k, lin-1,col))
                bk(k+1,lin-1, col); break;
        case 2:
            if(a[lin][col+1]=='_' && !vizitat(k, lin,col+1))
                bk(k+1,lin, col+1); break;
        case 3:
            if(a[lin+1][col]=='_' && !vizitat(k, lin+1,col))
                bk(k+1,lin+1, col);break;
        case 4:
            if(a[lin][col-1]=='_' && !vizitat(k, lin,col-1))
                bk(k+1,lin, col-1);break;
        }
    }
}
int main()
{
    f>>n>>m;
    for(i = 1; i <= n; i++) 
    {
        a[i][0] = '#';
        a[i][m + 1] = '#';
    }
    for(j = 1; j <= m; j++) 
    {
        a[0][j] = '#';
        a[n + 1][j] = '#';
    }
    for(i=1;i<=n;i++)
       {
        for(j=1;j<=m;j++)
           {
             f>>a[i][j];
             if(a[i][j]=='S')
             {
                lin=i;
                col=j;
             }
           }
       } 
    bk(1,lin,col);
}
