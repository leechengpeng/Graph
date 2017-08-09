# Graph
## Adjancency Matrix
**Source Code**: [AdjancencyMatrix.hpp](AdjancencyMatrix.hpp)

**Usage and test**: 
```C++
Graph::AdjancencyMatrix<int, 4> AdjancencyMatrix;
AdjancencyMatrix.addEdge(0, 1, 5);	// Vertex 0 -> 1: weight 5
AdjancencyMatrix.addEdge(0, 2, 1);	// Vertex 0 -> 2: weight 1
AdjancencyMatrix.addEdge(0, 3, 8);	// Vertex 0 -> 3: weight 8
AdjancencyMatrix.addEdge(1, 2, 3);	// Vertex 1 -> 2: weight 3
AdjancencyMatrix.addEdge(2, 3, 1);	// Vertex 2 -> 3: weight 1

_ASSERT(AdjancencyMatrix.connect(0, 1) == true);
_ASSERT(AdjancencyMatrix.connect(0, 2) == true);
_ASSERT(AdjancencyMatrix.connect(0, 3) == true);
_ASSERT(AdjancencyMatrix.connect(1, 2) == true);
_ASSERT(AdjancencyMatrix.connect(2, 1) == true);
_ASSERT(AdjancencyMatrix.connect(2, 3) == true);
_ASSERT(AdjancencyMatrix.connect(1, 3) == false);

_ASSERT(AdjancencyMatrix.getEdgeWeight(0, 1) == 5);
_ASSERT(AdjancencyMatrix.getEdgeWeight(0, 2) == 1);
_ASSERT(AdjancencyMatrix.getEdgeWeight(0, 3) == 8);
_ASSERT(AdjancencyMatrix.getEdgeWeight(2, 1) == 3);
_ASSERT(AdjancencyMatrix.getEdgeWeight(2, 3) == 1);
_ASSERT(AdjancencyMatrix.getEdgeWeight(1, 3) == 0);

auto AdjancencyVertices = AdjancencyMatrix.getAdjancencyVertices(0);
_ASSERT(AdjancencyVertices.size() == 3);
_ASSERT(AdjancencyVertices.at(0)  == 1);
_ASSERT(AdjancencyVertices.at(1)  == 2);
_ASSERT(AdjancencyVertices.at(2)  == 3);
```
