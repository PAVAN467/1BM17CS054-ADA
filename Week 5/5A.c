#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 4
#define sqr 2
int urow,ucol;
int grid[N][N]={{2,0,0,0},{0,1,3,0},{3,0,0,1},{0,2,4,0}};
bool usedInRow(int row, int num)
{
    int i;
    //printf("In row %d",num);
    for(i=0;i<N;i++)
    {
        if(grid[row][i]==num)
        {
            return true;
        }
    }
    return false;
}
bool usedInColumn(int col, int num)
{
    int i;
    //printf("In col %d",num);
    for(i=0;i<N;i++)
    {
        if(grid[i][col]==num)
        {
            return true;
        }
    }
    return false;
}
bool usedInGrid(int srow, int scol, int num)
{
    int i,j;
    //printf("In grid %d ",num);
    for(i=srow; i<=srow+sqr;i++)
    {
        for(j=scol;j<scol+sqr;j++)
        {
            if(grid[i][j]==num)
            {
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int row, int col, int num)
{
    return (!usedInRow(row,num))&&(!usedInColumn(col,num))&&(!usedInGrid(row-row%sqr,col-col%sqr,num));
}

bool findUnassignedLocation()
{
    for(urow=0;urow<N;urow++)
    {
        for(ucol==0;ucol<N;ucol++)
        {
            if(grid[urow][ucol]==0)
                return true;
        }
    }
    return false;
}
bool solveSudoku()
{
    int num;
    if(!findUnassignedLocation())
        return true;
    for(num=1;num<=N;num++)
    {
        if(isSafe(urow,ucol,num))
        {
            //printf("HI");
            grid[urow][ucol]=num;
            if(solveSudoku())
                return true;
            grid[urow][ucol]=0;
        }
    }
    return false;  
}
int main()
{
    int i,j;
    if(solveSudoku())
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ",grid[i][j]);
            }
            printf("\n");
        }
    }
}