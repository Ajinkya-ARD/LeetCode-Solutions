class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        # Dictionary to store the first occurrence of each character
        first_occurrence = {}
      
        # Initialize the answer with -1 as per problem constraints
        max_length = -1
      
        # Iterate over the string to find the max length between equal characters
        for index, char in enumerate(s):
            # If character is already seen, calculate the length between the current and first occurrence
            if char in first_occurrence:
                length_between = index - first_occurrence[char] - 1
                max_length = max(max_length, length_between)
            else:
                # Store the first occurrence of the character
                first_occurrence[char] = index
      
        # Return the maximum length found
        return max_length