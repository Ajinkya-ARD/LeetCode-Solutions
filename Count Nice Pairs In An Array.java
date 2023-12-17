class Solution {
    public int countNicePairs(int[] nums) {
        // Create a HashMap to store the counts of each difference value
        Map<Integer, Integer> countMap = new HashMap<>();
      
        // Iterate through the array of numbers
        for (int number : nums) {
            // Calculate the difference between the number and its reverse
            int difference = number - reverse(number);
            // Update the count of the difference in the HashMap
            countMap.merge(difference, 1, Integer::sum);
        }
      
        // Define the modulo value to ensure the result fits within integer range
        final int mod = (int) 1e9 + 7;
      
        // Initialize the answer as a long to handle potential overflows
        long answer = 0;
      
        // Iterate through the values in the countMap
        for (int count : countMap.values()) {
            // Calculate the number of nice pairs and update the answer
            answer = (answer + (long) count * (count - 1) / 2) % mod;
        }
      
        // Cast the answer back to an integer before returning
        return (int) answer;
    }

    // Helper function to reverse a given integer
    private int reverse(int number) {
        // Set initial reversed number to 0
        int reversed = 0;
      
        // Loop to reverse the digits of the number
        while (number > 0) {
            // Append the last digit of number to reversed
            reversed = reversed * 10 + number % 10;
            // Remove the last digit from number
            number /= 10;
        }
      
        // Return the reversed integer
        return reversed;
    }
}