class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days. 
    vector <int> calculateSpan(int *price, int n)
    {
        stack<int> s;
        s.push(0);
        vector <int> S (n);
        
        //span value of first day is always 1. 
        S[0] =1;
        
        for(int i=1;i<n;i++)
        {
            //we pop elements from the stack till price at top of stack 
            //is less than or equal to current price.
            while(s.empty()==false and price[s.top()] <= price[i])
                s.pop();
            
            //if stack becomes empty, then price[i] is greater than all 
            //elements on left of it in list so span is i+1.
            //Else price[i] is greater than elements after value at top of stack.
            int span = (s.empty()) ? (i+1) : (i-s.top());
            S[i] = span;
            
            //pushing this element to stack.
            s.push(i);
       	}
       	//returning the list.
       	return S;
    }
};
 
