#include<stdlib.h>
#include<stdio.h>
struct node
{
  int coef;
  int expo;
  struct node *next;
}*poly1=NULL , *poly2 =NULL, *result=NULL;
void readpoly(struct node** poly);
void addpoly();
void printpoly();
void main()
{
    printf("Enter the details of first polynomial\n");
    readpoly(&poly1);
    printf("\nThe first polynomial is: ");
    printpoly(poly1);
    printf("\nEnter the details of second polynomial\n");
    readpoly(&poly2);
    printf("\nThe second polynomial is: ");
    printpoly(poly2);
    addpoly();
    printf("\nThe result of polynomial addition is: ");
    printpoly(result);
}
void readpoly(struct node** poly)
{
    int coef, expo , no;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&no);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
   *poly = temp;
    for(int i=1; i<=no; i++)
    {
		printf("Enter the coefecient of term %d: ",i);
		scanf("%d", &coef);
		printf("Enter the exponent of term %d: ",i);
		scanf("%d", &expo);
		temp->coef = coef;
		temp->expo = expo;
		temp-> next = NULL;
		if(i!=no)
		{
			temp->next = (struct node*)malloc(sizeof(struct node));
			temp = temp->next;
			temp->next = NULL;
		}
	}
}
void addpoly()
{
    result=(struct node*) malloc(sizeof(struct node)); 
    result->next=NULL;
    struct node* ptr=result;
    while(poly1!=NULL && poly2!=NULL) 
    {  
        if (poly1->expo > poly2->expo) 
        { 
            ptr->expo = poly1->expo; 
            ptr->coef = poly1->coef;
            poly1 = poly1->next; 
        } 
        else if (poly1->expo < poly2->expo) 
        { 
            ptr->expo = poly2->expo; 
            ptr->coef = poly2->coef; 
            poly2 = poly2->next; 
        }  
        else 
        { 
            ptr->expo = poly1->expo; 
            ptr->coef = poly1->coef + poly2->coef; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        }
        if(poly1!=NULL && poly2!=NULL)
        {  
            ptr->next = (struct node*) malloc(sizeof(struct node)); 
            ptr = ptr->next; 
            ptr->next = NULL;
        }
        else
           ptr->next=NULL; 
    } 
    while (poly1!=NULL || poly2!=NULL) 
    { 
        ptr->next = (struct node*)malloc(sizeof(struct node)); 
        ptr = ptr->next; 
        ptr->next = NULL;
        if (poly1!=NULL) 
        { 
            ptr->expo = poly1->expo; 
            ptr->coef = poly1->coef; 
            poly1 = poly1->next; 
        } 
        else if (poly2!=NULL) 
        { 
            ptr->expo = poly2->expo; 
            ptr->coef = poly2->coef; 
            poly2 = poly2->next; 
        } 
    } 
}
void printpoly(struct node* poly)
{
   struct node *ptr=poly;
   while(ptr!= NULL)
   {
        printf("%dX^%d", ptr->coef, ptr->expo);
        if(ptr->next!= NULL)
	   printf("+");
        ptr = ptr->next;
   }
   printf("\n");
}
