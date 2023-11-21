class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid[0])
        n = len(obstacleGrid)

        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j]==0:
                    obstacleGrid[i][j]=1
                else:
                    obstacleGrid[i][j]=0

        for j in range(m):
            if obstacleGrid[0][j]==0 and j!=m-1:
                for k in range(j,m):
                    obstacleGrid[0][k]=0
        
        for i in range(n):
            if obstacleGrid[i][0]==0 and i!=n-1:
                for k in range(i,n):
                    obstacleGrid[k][0]=0

        for i in range(1,n):
            for j in range(1,m):
                if obstacleGrid[i][j]!=0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                    
        return obstacleGrid[-1][-1]