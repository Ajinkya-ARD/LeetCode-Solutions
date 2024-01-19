class Solution:
    def isPathCrossing(self, path: str) -> bool:
        # initialize starting point
        x, y = 0, 0
        # set to keep track of visited coordinates
        visited = {(0, 0)}
      
        # iterate over each character in the path string
        for direction in path:
            # move in the corresponding direction
            if direction == 'N':
                x -= 1
            elif direction == 'S':
                x += 1
            elif direction == 'E':
                y += 1
            elif direction == 'W':
                y -= 1
          
            # check if the new position has already been visited
            if (x, y) in visited:
                # if we've been here before, path crosses. Return True
                return True
          
            # add the new position to the set of visited coordinates
            visited.add((x, y))
      
        # if visited all positions without crossing, return False
        return False