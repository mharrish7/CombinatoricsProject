#include<stdio.h>
#include<stdlib.h>
void main()
{
    printf("Enter the size of the Queue : ");
    int n;
    scanf("%d",&n);
    int *cq=(int *)malloc(n*sizeof(int));
    int r=-1,f=-1;
    int isfull()
    {
        if(f==0&&r==n-1) // normal basic condition
            return 1;
        else if(f==r+1)  // when one round is completed and tail touches head
            return 1;
        return 0;
    }

    int isempty()
    {
        if(f==-1)  //normal basic condition
            return 1;
        return 0;
    }

    void Enqueue()
    {
        if(isfull())
        {
            printf("\nThe queue is full and Enqueue cannot be performed \n");
            return;
        }
        int a;
        printf("\nEnter the Element to be added : ");
        scanf("%d",&a);
        printf("\nEnqueue(%d)\n",a);
        r=(r+1)%n;
        cq[r]=a;
        if(f==-1)
            f=0;
    }
    void Dequeue()
    {
        if(isempty())
        {
            printf("\nThe queue is Empty and Dequeue cannot be performed\n");
            f=-1;
            r=-1;
            return; 
        }
        int a=cq[f];
        if(f==r) // When there is only one element after the Dequeue the queue is set to initial condition
        {
            f=-1;
            r=-1;
        }
        else 
            f=(f+1)%n;
        printf("\nDequeue()\n\n%d is removed \n",a);
    }
    void display()
    {
        printf("\n-------\nQueue\n\n");
            if(isempty())
            {
                printf("\nThe Queue is empty\n");
                return ;
            }
            if(f<=r)
                for(int i=f;i<=r;printf("%d\n",cq[i++]));
                
            else if(r<f )
            {
                for(int i=f;i<n;printf("%d\n",cq[i++]));
                for(int i=0;i<=r;printf("%d\n",cq[i++]));
            }    
            printf("\n------\n");
    }
    int temp=0;
    while(1)
    {
        int choice;
        printf("\n1)Enqueue\n2)Dequeue\n3)Exit\nEnter choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1: 
                Enqueue();
                break;
    
            case 2:
                Dequeue();
                break;

            case 3: 
                temp=1;
                break;
        }
        display(); // displaying the Queue
        if(temp==1)
                break;  // breaking the while loop
    }
    printf("\n\nThe Circular Queue process is now terminated ....\nThanks for using........\n\n\n");
}



