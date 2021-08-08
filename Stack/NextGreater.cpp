class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
       stack <long long> s;
       
       vector <long long> V(n);
       
       for(int i=n-1;i>=0;i--)
       {
           while(s.empty()==false && s.top() <= arr[i])
                s.pop();
           
            if (s.empty ())
                V[i] = -1;
            else 
                V[i] = s.top ();
            
            s.push (arr[i]);
       }
       return V;
    }
};
