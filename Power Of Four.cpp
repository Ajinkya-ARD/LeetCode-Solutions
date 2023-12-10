class Solution {
public:
    bool isPowerOfTwo(int n){
        return ( (n > 0) and ( ( n & (n-1)) == 0 )  );
    }
    bool isPowerOfFour(int n) {
        return (isPowerOfTwo(n) and (n & 0x55555555)!=0);
    }
};