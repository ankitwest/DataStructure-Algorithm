


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        G = collections.defaultdict(dict)
        for (x, y), v in zip(equations, values):
            G[x][y] = v
            G[y][x] = 1/v
            
        
        def bfs(src, dst):
            if src not in G or dst not in G: return -1.0
            q, seen = [(src, 1.0)], set()
            for x, v in q:
                if x == dst: return v
                seen.add(x)
                for y in G[x]:
                    if y not in seen:
                        q.append((y, v*G[x][y]))
                        
            return -1.0
                    
            
        v = []
        for s, d in queries:
            v.append(bfs(s, d))
        return v
        # return [bfs(s, d) for s, d in queries]
            
          
          
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
