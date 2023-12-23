class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        # Initialize the total time to 0.
        total_time = 0
      
        # A helper function to calculate the time to move from one point to another.
        # The time is determined by the maximum of the absolute horizontal (x-axis)
        # or vertical (y-axis) distances between two points, since one can move diagonally.
        def time_to_move(point1, point2):
            return max(abs(point1[0] - point2[0]), abs(point1[1] - point2[1]))
      
        # Iterate over each point and the next point in the list,
        # calculate the time to move between them, and add it to the total time.
        for i in range(len(points) - 1):
            total_time += time_to_move(points[i], points[i + 1])
      
        # Return the total time calculated.
        return total_time

# Example usage:
# solution = Solution()
# time_needed = solution.minTimeToVisitAllPoints([[1,1],[3,4],[-1,0]])
# print(time_needed)