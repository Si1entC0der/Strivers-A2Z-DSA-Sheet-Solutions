class Solution {
  public:
    // const int mod = 1e9+7;
    
    long long power(long long x,long long y) {
        long long res = 1;
        while(y > 0) {
            if(y & 1)
                res = res * x;
            x = x * x;
            y /= 2;
        }
        return res;
    }
    
    long long count(int n) {
        // your code here
        long long x = n * (n - 1) / 2;
        
        return power(2,x);
    }
};
