// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>>s;
    
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            int mini;
            if(s.empty()) mini = num;
            else mini = min(s.top().second,num);
            
            s.push({num,mini});
			// Write your code here.
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(!s.empty()){
                int x= s.top().first;
                s.pop();
                return x;
            }
            return -1;
			// Write your code here.
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(!s.empty()) return s.top().first;
            return -1;
			// Write your code here.
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            if(s.empty()) return -1;
            return s.top().second;
			// Write your code here.
		}
};


Second Apparoach using maths 

class MinStack {
    stack<long long>s;
    long long mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(s.empty()){
            mini = value;
            s.push(value);
        }else{
            if(value<mini){
                s.push(2*value*1LL - mini);
                mini = value;
            }else s.push(value);
        }
    }
    
    void pop() {
       if(s.empty()){
           return;
       } 
        long long el = s.top();
        s.pop();
        if(el<mini){
            mini = 2*mini - el;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        long long el = s.top();
        if(el<mini) return mini;
        else return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
