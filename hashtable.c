#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 5
int h[TABLE_SIZE]={0};
void insert()
{
 int key,index,i,flag=0,hkey;
 printf("Enter a value to insert into hash table: ");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {
     index=(hkey+i)%TABLE_SIZE;
     if(h[index] == 0)
     {
        h[index]=key;
         break;
     }
    }
    if(i == TABLE_SIZE)
     printf("Element cannot be inserted.\n");
}

void search()
{
 int key,index,i,flag=0,hkey;
 printf("Enter the element to be searched: \n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i)%TABLE_SIZE;
    if(h[index]==key)
    {
      printf("The value is found at index %d\n",index);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("The value is not found\n");
}

void display()
{

  int i;

  printf("Elements in the hash table are: \n");

  for(i=0;i< TABLE_SIZE; i++)

  printf("Index: %d \t Value: %d\n",i,h[i]);

}

int main()
{
    int opt,i;
  while(1)
    {
    printf("Choose an option:\n1.Insert\n2.Display\n3.Search\n4.Exit\nEnter: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}
