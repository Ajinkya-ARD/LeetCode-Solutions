class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # Initialize the answer to zero.
        result = 0
      
        # Continue the loop until n becomes zero.
        while n:
            # Apply bitwise XOR to the current result and n.
            # This is part of the process to find the minimum operations.
            result ^= n
          
            # Right shift the bits of n by one position.
            # This operation reduces the number being processed bit by bit.
            n >>= 1
      
        # Return the computed result.
        return result