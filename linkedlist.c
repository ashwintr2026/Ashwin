#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
}*head;

void beginInsert();  
void lastInsert();  
int randomInsert();  
void beginDelete();  
void lastDelete();  
int randomDelete();  
void display();

int main()
{
    int op=0 , choice;
    while(op!=4)
    {
      printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice: ");
      scanf("%d", &op);
      switch(op)  
      {  
         case 1:  
           printf("1.Insertion at beginning\n2.Insertion at End\n3.Insertion at any position\nEnter your choice: ");
           scanf("%d",&choice);
           if(choice==1)
              beginInsert();
           else if(choice==2)
              lastInsert();
           else if(choice==3)
              randomInsert();
           else
              printf("Wrong Choice\n");
              break;  
         case 2:  
            printf("1.Delete from beginning\n2.Delete from end\n3.Delete from any position\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice==1)
              beginDelete();
            else if(choice==2)
              lastDelete();
            else if(choice==3)
              randomDelete();
            else
              printf("Wrong Choice\n");
              break;  
         case 3:  
            display();    
            break;  
         case 4:  
            return 0;
         default:  
            printf("Invalid choice\n");
        }
    }  
}
void beginInsert()
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   int item;
   printf("Enter the data to be inserted: ");
   scanf("%d",&item);
   ptr->data=item;
   ptr->next=head;
   head=ptr;
   printf("Element Inserted!\n");
}
void lastInsert()
{
   struct node ptr = (struct node) malloc(sizeof(struct node)) , *temp;
   int item;
   printf("Enter the data: ");
   scanf("%d",&item);
   ptr->data=item;
   if(head==NULL)
   {
      ptr->next=NULL;
      head=ptr;
      printf("Node is empty,Element Inserted at beginning.\n");
   }
   else
   {
      temp=head;
      while (temp->next!=NULL)
         temp=temp->next;
      temp->next=ptr;
      ptr->next=NULL;
      printf("Node Inserted at last.\n");
   }
}
int randomInsert()
{
   if (head==NULL)
   {
      printf("List is Empty,Element will be inserted at beginning.\n");
      beginInsert();
   }
   else
   {
      int item , pos;
      struct node *ptr=(struct node *)malloc(sizeof(struct node)), *temp , *temp1;
      printf("Enter the position at which element is to be inserted: ");
      scanf("%d",&pos);
      if (pos==1)
        beginInsert();
      else if(pos<1)
        printf("Enter valid position\n");
      else
      {
         temp1=head;
         for (int i = 1; i < pos; i++)
         {
            temp=temp1;
            if (temp==NULL)
            {
              printf("Invalid position.\n");
              return 0;
            }
            temp1=temp1->next;
            if (i+1==pos && temp1==NULL)
            {
               lastInsert();
               return 0;
            }
         }
         printf("Enter the data to be inserted: ");
         scanf("%d",&item);
         ptr->data=item;      
         ptr->next=temp1;
         temp->next=ptr;
         printf("New Node Inserted at position %d\n" , pos);
      }
   }
}
void beginDelete()
{
   if(head==NULL)
     printf("List is Empty!\n");
   else
   {
      struct node* ptr = head;
      head=ptr->next;
      printf("Node Deleted and deleted element is %d\n" , ptr->data);
      free(ptr);
   }
}
void lastDelete()
{
   if (head==NULL)
      printf("List is empty\n");
   else if (head->next==NULL)
      beginDelete();
   else
   {
      struct node *ptr=head , *temp;
      while (ptr->next!=NULL)
      {
        temp=ptr;
        ptr=ptr->next;
      }
      temp->next=NULL;
      printf("Node deleted and deleted element is %d\n", ptr->data);
      free(ptr);
   }
}
int randomDelete()
{
   if (head==NULL)
      printf("List is empty\n");
   else
   {
      int pos;
      printf("Enter the position at which element is to be deleted: ");
      scanf("%d",&pos);
      if (pos<1)
         printf("Invalid position\n");
      else if(pos==1)
         beginDelete();
      else
      {
         struct node *ptr, *temp=head;
         for (int i = 1; i < pos; i++)
         {
            ptr=temp;
            temp=temp->next;
            if (temp==NULL)
            {
               printf("Invalid position\n");
               return 0;
            }
         }      
         ptr->next=temp->next;
         printf("Node deleted and deleted element is %d\n" , temp->data);
         free(temp);
      }
   }  
}
void display()
{
   struct node* ptr=head;
   if (head!=NULL)
   {
      printf("The Elements in the list are:\n");
      while (ptr->next!=NULL)
      {
        printf("%d,",ptr->data);
        ptr=ptr->next;
      }
      printf("%d\n",ptr->data);
   }
   else
     printf("List is Empty\n");
}
