int findMinimumCoins(int amount) 
{
    int coins[] = {1000,500,100,50,20,10,5,2,1};
    int ans =0,i=0;
    while(amount and i<9){
        if(amount >= coins[i]){
            ans+=(amount/coins[i]);
            amount = amount%coins[i];
            i++;
        }else i++;
    }
    return ans;
    // Write your code here
}
