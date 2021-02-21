#The key insight is that we do not want to recursively eat 1 orange as that can take #too much time, so we can calculate how many "1 steps" we have to take in order to eat #n/2 or 2n/3 oranges.
class Solution:
    def minDays(self, n: int) -> int:
        self.cache = {}
        return self.dfs(n)

    def dfs(self, n):
        if n in self.cache:
            return self.cache[n]
        if n <= 2:
            return n

        ans = min(n % 3 + self.dfs(n // 3), n % 2 + self.dfs(n // 2)) + 1
        self.cache[n] = ans
        return ans


"""
def minDays(self, n: int) -> int:
        return self.dp(n, dict())
    
    def dp(self, n, memo):
        if n <= 2:
            return n
        
        if n not in memo:
            memo[n] = 1 + min([
                n % 2 + self.dfs_solution(n // 2, memo),  # eat one orange for n%2 days, then solve for n//2
                n % 3 + self.dfs_solution(n // 3, memo),  # eat one orange for n%3 days, then solve for n//3
            ])
        
        return memo[n]
"""