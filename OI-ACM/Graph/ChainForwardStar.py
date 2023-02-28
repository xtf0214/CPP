class ChainForwardStar:

    def __init__(self, V) -> None:
        self.V = V + 1
        self.E = 0
        self.head = [-1] * (V + 1)
        self.next = []
        self.edges = []

    def addEdge(self, u, v, w=1):
        self.edges.append((v, w))
        self.next.append(self.head[u])
        self.head[u] = self.E
        self.E += 1

    def __getitem__(self, u):
        i = self.head[u]
        while i != -1:
            yield self.edges[i]
            i = self.next[i]


V = 6
E = 11
txt = [[1, 2, 24], [2, 1, 54], [5, 2, 34], [6, 3, 87], [2, 3, 124], [1, 4, 675], [2, 4, 345], [4, 1, 321], [2, 5, 587],
       [4, 5, 87], [5, 6, 956]]

Graph = ChainForwardStar(V)
for u, v, w in txt:
    Graph.addEdge(u, v, w)
for u in range(1, 7):
    for v, w in Graph[u]:
        print(u, v, w)
    print()