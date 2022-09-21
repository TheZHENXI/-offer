#include <stdio.h>


int Find(int a[3][3],int k,int* px,int* py)
{
    int x = 0;
    int y = *py - 1;

    while(x <= (*px-1) && y >=0)
    {
        if(a[x][y] > k)
        {
            y--;
        }
        else if(a[x][y] < k)
        {
            x++;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
    int k = 7;
    int x= 3;
    int y =3;
    int ret = Find(a,k,&x,&y);
    if(ret == 1)
    {
        printf("找打了\n");
        printf("[%d,%d]\n",x,y);
    }    
    else
        printf("找不到\n");
    return 0;
}