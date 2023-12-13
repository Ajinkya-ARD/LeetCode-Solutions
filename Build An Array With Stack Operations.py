class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        results = []
        numbers = []
        
        for i in range(1, n + 1):
            if numbers == target:
                return results
            
            numbers.append(i)
            
            if numbers[len(numbers) - 1] == target[len(numbers) - 1]:
                results.append("Push")
            else:
                results.append("Push")                
                results.append("Pop")
                numbers.pop()
                
        return results