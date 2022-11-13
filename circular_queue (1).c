#include<stdio.h>
int isfull();
int enqueue(int val);
int dequeue();
int isempty();
int top_el();
void display();
int Q[8];
int f=-1;
int r=-1;
int isempty(){
    if((f==-1)){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(){
    if(r==7 && f==0 || f==r+1){
        return 1;
    }
    return 0;    
}
int top_el(){
    printf("Top element is %d\n",Q[r]);
}
int enqueue(int val){
    if(isfull()!=1){
        r=(r+1)%7;
        Q[r]=val;
    }
    else{
        printf("Queue is full\n");
    }
    if(isempty()){
        f++;
    }
}
int dequeue(){
    if(!isempty()){
        if(f==r){
            f=r=-1;
        }
        else{
            f=(f+1)%7;
        }
    }
    else{
        printf("Queue is empty\n");
    }
}
void display(){
    for (int i=0;i<7;i++){
        printf("%d ",Q[i]);
    }
}
void main(){
    enqueue(5);
    enqueue(6);
    enqueue(8);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();
    enqueue(50);
    enqueue(60);
    enqueue(80);
    enqueue(100);
    top_el();
    display();
}
