#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>input,output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(val);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        // Implement the enqueue() function.
    }

    int deQueue() {
        if(input.empty())return -1;
        int x= input.top();
        input.pop();
        return x;
        // Implement the dequeue() function.
    }

    int peek() {
        if(input.empty())return -1;
        return input.top();
        // Implement the peek() function here.
    }

    bool isEmpty() {
        return input.empty();
        // Implement the isEmpty() function here.
    }
};
