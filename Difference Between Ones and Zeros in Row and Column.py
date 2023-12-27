class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        # Determine the number of rows (m) and columns (n) in the grid
        num_rows, num_cols = len(grid), len(grid[0])
      
        # Initialize lists to store the sum of '1's in each row and column
        sum_rows = [0] * num_rows
        sum_cols = [0] * num_cols
      
        # Calculate the sum of '1's for each row and column
        for i in range(num_rows):
            for j in range(num_cols):
                sum_rows[i] += grid[i][j]  # Sum '1's for row i
                sum_cols[j] += grid[i][j]  # Sum '1's for column j
      
        # Initialize a list to store the resulting differences for each cell
        differences = [[0] * num_cols for _ in range(num_rows)]
      
        # Compute the differences for each cell in the grid
        for i in range(num_rows):
            for j in range(num_cols):
                # Calculate the difference by adding the sum of '1's in the current row and column
                # and subtracting the sum of '0's (computed by subtracting the sum of '1's from the total count)
                differences[i][j] = sum_rows[i] + sum_cols[j] - (num_cols - sum_rows[i]) - (num_rows - sum_cols[j])
      
        # Return the list containing the differences for each cell
        return differences