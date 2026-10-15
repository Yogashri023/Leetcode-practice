bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    if (pushedSize!=poppedSize) return false;
    int j=0;
    int top=-1;
    int stack[1000];
    for (int i=0; i<pushedSize;i++){
        stack[++top]=pushed[i];
        while(top>=0 && stack[top]==popped[j]){
            top--;
            j++;
        }
    }
    return top==-1;
}