//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node* next;
};

void initList(struct Node **head) 
{
    *head=NULL;
}


int isEmpty(struct Node *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}


int listData(struct Node *p) 
{
    return p->data;
}


void addNode(struct Node** head_ref, int new_data) 
{
    struct Node* current;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    if (*head_ref == NULL || (*head_ref)->data <= new_node->data)
    {
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    }
    else
    {
        current = *head_ref; 
        while (current->next != NULL && current->next->data > new_node->data)/
        {
            current = current->next; 
        }
        new_node->next = current->next; 
        current->next = new_node; 
    }
}


void toString(struct Node *head) 
{
    struct Node *curr;
    curr=head; 
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        if(curr->next==NULL)
            break; 
        printf(",");
        curr=curr->next;
    }
    return 0;
}


void deleteList(struct Node **head)
{
    if(isEmpty==1)
        return 0;
    struct Node *ptr;
    while(*head!=NULL)
    {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}


void deleteElement(struct Node** head_ref, int x)
{
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == x)
    {
        *head_ref = temp->next; 
        printf("\nList after deleting number %d :\n",x);
        free(temp); 
        return;
    }
    while (temp != NULL && temp->data != x)
    {
        prev = temp; 
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    printf("\nList after deleting number %d :\n",x);
    free(temp); 
}


int containsList(int x) 
{
    if(listData==x)
        return 1;
    else
        return 0;
}


void countList(struct Node *head)
{
    if(isEmpty==1)
        return 0;
    int i=0;
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        curr=curr->next;
        i++;
    }
    printf("\nLIST HAS %d NODES..\n",i);
}


void countElement(struct Node *head, int x)
{
    if(isEmpty==1)
        return 0;
    int i=0;
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
            i++;
        curr=curr->next;
    }
    printf("\nNUM %d PRESENTED %d TIMES IN LIST..\n",x,i);
}


int getElement(struct Node **head, int j) 
{
    if(isEmpty(*head)==1) 
        return 0;
    int i=0;
    struct Node *curr;
    curr=*head;
    while(curr!=NULL) 
    {
        i++;
        if(i==j) 
            printf("\nPosition %d equals to value : %d \n",i,curr->data);
        curr=curr->next;
    }
    return 0;
}


void firstLocationList(struct Node *head, int x)
{
    if(isEmpty==1)
        return 0;
    int i=0;
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        i++;
        if(curr->data==x)
            break;
        curr=curr->next;
    }
    printf("\nFIRST LOCATION OF NUM %d IS AT %d LOCATION..\n",x,i);
}


void lastLocationList(struct Node *head, int x)
{
    if(isEmpty==1)
        return 0;
    int i=0,a=0;
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        i++;
        if(curr->data==x)
        {
            a=i;
        }
        curr=curr->next;
    }
    printf("\nLAST LOCATION OF NUM %d IS AT %d LOCATION..\n",x,a);
}


void removeDuplicates(struct Node *head)
{
    struct Node * current = head; 

    struct Node * next_next;

    if (isEmpty(head)==1) 
        return;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
    printf("\nAfter removing Duplicates my list is : \n");
    toString(head);
}


int main()
{
    struct Node* head;
    initList(&head);
    addNode(&head,10);
    addNode(&head,3);
    addNode(&head,5);
    addNode(&head,5);
    addNode(&head,7);
    addNode(&head,8);
    addNode(&head,1);
    addNode(&head,2);
    addNode(&head,4);
    addNode(&head, 9);
    addNode(&head, 9);
    printf("\n Created Linked List\n");
    toString(head);
    printf("\n");
    deleteElement(&head,10);
    toString(head);
    printf("\n");
    getElement(&head,7);
    countElement(head,9);
    firstLocationList(head,9);
    lastLocationList(head,9);
    countList(head);
    removeDuplicates(head);
    deleteList(&head);
    return 0;
}
