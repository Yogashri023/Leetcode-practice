


typedef struct {
    int *instack;
    int *outstack;
    int intop;
    int outtop;
    int c;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj=(MyQueue*)malloc(sizeof(MyQueue));
    obj->c=100;
    obj->instack=(int *)malloc(obj->c*sizeof(int));
    obj->outstack=(int *)malloc(obj->c*sizeof(int));
    obj->intop=-1;
    obj->outtop=-1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->instack[++obj->intop]=x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outtop==-1){
        while(obj->intop!=-1){
            obj->outstack[++obj->outtop]=obj->instack[obj->intop--];
        }
    }
    return obj->outstack[obj->outtop--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outtop==-1){
        while (obj->intop!=-1){
            obj->outstack[++obj->outtop]=obj->instack[obj->intop--];
        }
    }
    return obj->outstack[obj->outtop];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->outtop==-1 && obj->intop==-1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->outstack);
    free(obj->instack);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/