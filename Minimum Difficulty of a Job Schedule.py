class Solution:
    def minDifficulty(self, job_difficulty: List[int], days: int) -> int:
        num_jobs = len(job_difficulty)
        # Initialize DP table with infinity representing impossible scenarios.
        # dp_table[i][j] will hold the minimum difficulty of scheduling the first i jobs in j days
        dp_table = [[float('inf')] * (days + 1) for _ in range(num_jobs + 1)]
        dp_table[0][0] = 0 # Base case: 0 jobs in 0 days has 0 difficulty
      
        # Loop through each job
        for i in range(1, num_jobs + 1):
            # Only consider scheduling up to the minimum of days or jobs done so far
            for j in range(1, min(days + 1, i + 1)):
                max_difficulty_on_last_day = 0
                # Try to end the j-th day with each possible last job
                for k in range(i, 0, -1):
                    max_difficulty_on_last_day = max(max_difficulty_on_last_day, job_difficulty[k - 1])
                    # Update the DP table by adding the difficulty of the last job to the optimal difficulty of previous jobs in j-1 days
                    dp_table[i][j] = min(dp_table[i][j], dp_table[k - 1][j - 1] + max_difficulty_on_last_day)
                  
        # If the difficulty of scheduling all jobs in d days is infinite, it means it is not possible, thus return -1.
        # Otherwise, return the calculated difficulty
        return -1 if dp_table[num_jobs][days] == float('inf') else dp_table[num_jobs][days]
