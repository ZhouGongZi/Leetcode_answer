class Solution {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        else if(n == 1) return k;
        
        int one = 1;  /* it is one because consider
        n = 3, there it should be two cases: 
        1. painting the 1, 2 to be the other k-1 colors (k-1)*1
        2. painting 2 to be the k-1 colors when house 1 can have k colors (that why two = k) 
        */
        int two = k;
        
        int curr = k;
        for(int i=2; i<n; ++i){
            curr = (k-1) * (one + two);
            one = two;
            two = curr;
        }
        return curr * k;
        
    }
};