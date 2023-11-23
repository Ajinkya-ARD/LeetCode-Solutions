class Solution:

    def __init__(self):
        self.dx = [1, -1, 0, 0]
        self.dy = [0, 0, 1, -1]
    
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:

        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return matrix

        n, m = len(matrix), len(matrix[0])
        dist = [[0 for _ in range(m)] for _ in range(n)]
        queue = deque([])

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    dist[i][j] = 0
                    queue.append([i, j])
                else:
                    dist[i][j] = sys.maxsize
        
        while queue:
            x, y = queue.popleft()
            for d in range(4):
                next_x, next_y = x + self.dx[d], y + self.dy[d]
                if self.isValid(next_x, next_y, matrix):
                    if (dist[next_x][next_y] > dist[x][y] + 1):
                        dist[next_x][next_y] = dist[x][y] + 1
                        queue.append([next_x, next_y])

        return dist


    def isValid(self, x, y, matrix):
        return 0 <= x < len(matrix) and 0 <= y < len(matrix[0])
