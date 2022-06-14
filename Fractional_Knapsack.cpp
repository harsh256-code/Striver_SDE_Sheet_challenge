// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(Item i1,Item i2){
        double a = (double)i1.value / (double) i1.weight;
        double b = (double)i2.value / (double)i2.weight;
        return a>b;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int weight = 0;
        double ans = 0.0;
        for(int i = 0;i<n;i++){
            if(weight+arr[i].weight<=W){
                ans+=arr[i].value;
                weight+=arr[i].weight;
            }else{
                int remain = W-weight;
                ans+=((double)arr[i].value/(double)arr[i].weight *remain);
                break;
            }
        }
        return ans;
        // Your code here
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
