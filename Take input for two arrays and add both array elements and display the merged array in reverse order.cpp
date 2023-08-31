#include <stdio.h>

int main ()
{
    int n1,n2,m;
    int array1[500];
    int array2[500];
    int array3[500];
    scanf("%d",&n1);

    for(int i=0;i<n1;i++)
        scanf("%d",&array1[i]);

    scanf("%d",&n2);

    for(int i=0;i<n2;i++)
        scanf("%d",&array2[i]);

    if(n1>=n2)
    {
        m=n1;

    }
    else
    {
        m=n2;

    }

    for(int i=0;i<m;i++)
        array3[i]=array1[i]+array2[i];

    for(int i=(m-1);i>=0;i--)
        printf("%d ",array3[i]);

 return 0;
}

