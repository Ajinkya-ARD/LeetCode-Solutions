class Solution {

    // Method to calculate the number of ways to decode a message
    public int numDecodings(String s) {
        // String length
        int length = s.length();
        // Variables to hold previous and current number of decodings
        int prevCount = 0, currentCount = 1;

        // Loop through each character in the string
        for (int i = 1; i <= length; ++i) {
            // Initialize the next count as 0
            int nextCount = 0;
          
            // If the current character is not '0', it can stand alone, so add current count to next count
            if (s.charAt(i - 1) != '0') {
                nextCount = currentCount;
            }
          
            // If there are more than one characters and the substring of two characters can represent a valid alphabet
            if (i > 1 && s.charAt(i - 2) != '0' && Integer.valueOf(s.substring(i - 2, i)) <= 26) {
                // Add the previous count to next count
                nextCount += prevCount;
            }
          
            // Update prevCount and currentCount for the next iteration
            prevCount = currentCount;
            currentCount = nextCount;
        }
      
        // Return the total count of decodings for the entire string
        return currentCount;
    }
}
