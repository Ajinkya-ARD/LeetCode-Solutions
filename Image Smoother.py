class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        # Get the number of rows and columns in the image
        num_rows, num_cols = len(img), len(img[0])
      
        # Initialize an output image with the same dimensions, filled with zeros
        smoothed_image = [[0] * num_cols for _ in range(num_rows)]
      
        # Iterate through each pixel in the image
        for row in range(num_rows):
            for col in range(num_cols):
                # Initialize the sum and count of neighboring pixels
                pixel_sum = pixel_count = 0
              
                # Check all 9 positions in the neighborhood (including the pixel itself)
                for neighbor_row in range(row - 1, row + 2):
                    for neighbor_col in range(col - 1, col + 2):
                        # Ensure the neighbor is within image boundaries before including it
                        if 0 <= neighbor_row < num_rows and 0 <= neighbor_col < num_cols:
                            pixel_count += 1
                            pixel_sum += img[neighbor_row][neighbor_col]
              
                # Calculate the smoothed value for the current pixel
                # by taking the average of the sum of the neighborhood pixels
                smoothed_image[row][col] = pixel_sum // pixel_count
      
        # Return the smoothed image
        return smoothed_image