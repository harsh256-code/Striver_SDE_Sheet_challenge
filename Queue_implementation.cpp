class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        arr = new int[10000];
        qfront  = 0;
        rear = 0;
        size = 10000;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear)return 1;
        return 0;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        arr[rear++] = data;
        // Implement the enqueue() function
    }

    int dequeue() {
        if(qfront==rear)return -1;
        
        int x = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        return x;
        
        // Implement the dequeue() function
    }

    int front() {
        if(qfront==rear)return -1;
        return arr[qfront];
        // Implement the front() function
    }
};
