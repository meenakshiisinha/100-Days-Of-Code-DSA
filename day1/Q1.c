//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>
int main()
{
    printf("Enter size of array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Ennter elements of array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Enter number to be innserted: ");
    int x,m;
    scanf("%d",&m);
    printf("Enter position:");
    scanf("%d",&x);

    int a2[n+1];

    for(int i=0;i<n+1;i++)
    {
        if(i<x-1)
            a2[i]=a[i];
        else if(i==x-1)
            a2[i]=m;
        else
            a2[i]=a[i-1];
    }

    for(int i=0;i<n+1;i++)
        printf("%d ",a2[i]);
}