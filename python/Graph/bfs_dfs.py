from collections import deque

class Graph:
    def __init__(self, num_vertics):
        self._num_vertics = num_vertics
        self._adjacency = [[] for _ in range(num_vertics)]

    def add_edge(self, s, t):
        self._adjacency[s].append(t)
        self._adjacency[t].append(s)

    def _generate_path(self, s, t, prev):
        if prev[t] or s != t:
            yield from self._generate_path(s, prev[t], prev)
        yield str(t)

    def bfs(self, s, t):
        if s == t:
            return
        visited = [False] * self._num_vertics
        visited[s] = True
        d = deque()
        d.append(s)
        prev = [None] * self._num_vertics

        while d:
             v = d.popleft()
             for neighbour in self._adjacency[v]:
                 if not visited[neighbour]:
                     prev[neighbour] = v
                     if neighbour == t:
                         print('->'.join(self._generate_path(s, t, prev)))
                         return
                 visited[neighbour] = True
                 d.append(neighbour)

    def dfs(self, s, t):
        found = False
        visited = [False] * self._num_vertics
        prev = [None] * self._num_vertics

        def _dfs(from_vertex):
            nonlocal found
            if found == True:
                return
            visited[from_vertex] = True
            if from_vertex == t:
                found = True
                return
            for neighbour in self._adjacency[from_vertex]:
                if not visited[neighbour]:
                    prev[neighbour] = from_vertex
                    _dfs(neighbour)
        _dfs(s)
        print('->'.join(self._generate_path(s, t, prev)))





if __name__ == '__main__':
    graph = Graph(8)
    graph.add_edge(0, 1)
    graph.add_edge(0, 3)
    graph.add_edge(1, 2)
    graph.add_edge(1, 4)
    graph.add_edge(2, 5)
    graph.add_edge(4, 5)
    graph.add_edge(4, 6)
    graph.add_edge(5, 7)

    graph.bfs(0, 7)
    graph.dfs(0, 7)
