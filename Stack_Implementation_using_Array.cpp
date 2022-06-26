// Stack class.
class Stack {
    int *arr;
    int topp;
    int size;
public:
    
    Stack(int capacity) {
        this->size = capacity;
        arr = new int[size];
        topp = -1;
        // Write your code here.
    }

    void push(int num) {
        
        if(size-topp!=1){
            topp++;
            arr[topp]= num;
        }
        // Write your code here.
    }

    int pop() {
       if(topp!=-1){
           int x =arr[topp];
           topp--;
           return x;
       }
        return -1;
        // Write your code here.
    }
    
    int top() {
        if(topp!=-1){
            return arr[topp];
        }
        return -1;
        // Write your code here.
    }
    
    int isEmpty() {
        if(topp==-1)return 1;
        return 0;
        // Write your code here.
    }
    
    int isFull() {
        if(size-topp==1)return 1;
        return 0;
        // Write your code here.
    }
    
};
