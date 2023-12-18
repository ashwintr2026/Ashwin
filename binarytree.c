#include <stdio.h>
#include<math.h>
void main()
{
    int i, size, h, nodes;
    printf("Enter the height of the tree: ");
    scanf("%d", &h);
    nodes =(pow(2,h+1))-1;
    char arr[nodes];
    printf("Enter the root element: ");
    scanf(" %c", &arr[0]);
    printf("\nEnter '_' to represent free spaces\n");
    for (i=1;i<nodes;i++)
    {
        int p=(i-1)/2;
        if (arr[p]=='_')
        {
            arr[i] = '_';
        }
        else if(2*p+1==i)
        {
            printf("Enter the left child of %c: ",arr[p]);
            scanf(" %c", &arr[i]);
        }
        else if(2*p+2==i)
        {
            printf("Enter the right child of %c: ",arr[p]);
            scanf(" %c",&arr[i]);
        }
    }
    printf("The tree representation using array:\n");
    for (i=0;i<nodes;i++)
       printf("%c\t",arr[i]);
       printf("\n");
}
