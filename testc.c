


void main(){
    int m;
    scanf("%d" , &m);
    int *adj;
    adj = (int*)malloc(sizeof(int) * m * m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int ele;
            scanf("%d",&ele);
            *(adj+i*m+j)=ele;
        }
    }
    //Traversing
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<m;j++){
    //         int ele;
    //         ele=*(adj+i*m+j);
    //         printf
    //     }
    //     cout<<endl;
    // }

    int *adjc;
    adjc = (int*)malloc(sizeof(int) * m);
    for(int i =0; i<m; i++){
        adjc[i] = 0;
    }
    int *visited;
    visited = (int*)malloc(sizeof(int) * m);
    enqueue(0);
    int temp;
    while(!isempty()){
        temp = dequeue();
        
    }

    return 0;
}
