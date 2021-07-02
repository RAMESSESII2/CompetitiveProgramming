#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;
int length ( struct node *p )
{
     int count = 0 ;
     while ( p != NULL )
     {
         count++;
         p = p->next;
     }
     return ( count ) ;
}

Node* delete(Node *p, int node_no){
    if( p == NULL ){
        printf("Nothing to be deleted");
    }
    else{
        if( node_no > length(p)){
            printf("Node no. not available");
        }
        else{
            Node *prev, *cur;
            prev = NULL;
            cur = p;
            while(node_no-- > 1){
                prev = cur;
                cur = cur->next;
            }
            if( prev == NULL ){
                p = cur->next;
                free(cur);
            }
            else{
                prev->next = cur->next;
                free(cur);
            }
        }
    }
    return p;
}

struct node *insert(struct node *p, int n)
{
     struct node *temp;
     if(p==NULL)
     {
         p=(struct node *)malloc(sizeof(struct node));
         if(p==NULL)
         {
             printf("Error ");
             exit(0);
         }
         p-> data = n;
         p-> next = NULL;
     }
     else
     {
         temp = p;
         while (temp-> next != NULL){
             temp = temp-> next;
         }
         temp-> next = (struct node *)malloc(sizeof(struct node));
         if(temp -> next == NULL)
         {
         printf("Error ");
         exit(0);
         }
         temp = temp-> next;
         temp-> data = n;
         temp-> next = NULL;
     }
     return (p);
}

void printlist ( struct node *p )
{
     printf("The data values in the list are ");
     while (p!= NULL)
     {
         printf("%d	",p-> data);
         p = p-> next;
     }
     printf("|n");
}

Node* reverse(Node *p){
    struct node *prev, *cur;
    prev = NULL;
    cur = p;
    while( cur != NULL ){
        p = p->next;
        cur->next = prev;
        prev = cur;
        cur = p;
    }
    return prev;
}

int main()
{
     int n;
     int x;
     struct node *start = NULL;
     printf("Enter the nodes to be created \n");
     scanf("%d",&n);
     while ( n--  )
     {
         printf( "Enter the data values to be placed in a node \n");
         scanf("%d",&x);
         start = insert ( start, x );
     }
     printf(" The list before deletion id \n");
     printlist ( start );
     printf("\nEnter the node no \n");
     scanf ( "%d",&n);
     start = delete (start , n );
     printf(" The list after deletion is \n");
     printlist ( start );
     start = reverse(start);
     printf("\nThe reversed list is ");
     printlist ( start );
     //loop over all the nodes and use free()
     free(start);
     //
     return 0;
}

