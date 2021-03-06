# Graph
> **Compile Environment**：VS2015

## 1. Adjancency Matrix
#### Usage: `#include "AdjancencyMatrix.hpp"`
```C++
Graph::AdjancencyMatrix<int, 4> AdjancencyMatrix;
AdjancencyMatrix.addEdge(0, 1, 5);	// Vertex 0 -> 1: weight 5
AdjancencyMatrix.addEdge(0, 2, 1);	// Vertex 0 -> 2: weight 1
AdjancencyMatrix.addEdge(0, 3, 8);	// Vertex 0 -> 3: weight 8
AdjancencyMatrix.addEdge(1, 2, 3);	// Vertex 1 -> 2: weight 3
AdjancencyMatrix.addEdge(2, 3, 1);	// Vertex 2 -> 3: weight 1

// Method 1: visit inner elment
std::cout << "Method 1: " << std::endl;
if (AdjancencyMatrix.connect(0, 1))
{
	std::cout << "0 -> 1: " << AdjancencyMatrix.getEdgeWeight(0, 1) << std::endl;
}
if (AdjancencyMatrix.connect(0, 2))
{
	std::cout << "0 -> 2: " << AdjancencyMatrix.getEdgeWeight(0, 2) << std::endl;
}
if (AdjancencyMatrix.connect(0, 3))
{
	std::cout << "0 -> 3: " << AdjancencyMatrix.getEdgeWeight(0, 3) << std::endl;
}

// Method 2: visit inner elment
size_t SourceIndex = 0;
auto AdjancencyVertices = AdjancencyMatrix.getAdjancencyVertices(SourceIndex);
std::cout << "Method 2: " << std::endl;
for (auto Index : AdjancencyVertices)
{
	std::cout << SourceIndex <<" -> " << Index << ": " << AdjancencyMatrix.getEdgeWeight(SourceIndex, Index) << std::endl;
}
```

## 2. Dijkstra
#### Usage: `#include "Graph.hpp"`
```C++
constexpr unsigned Vertices = 4;

Graph::AdjancencyMatrix<int, Vertices> AdjancencyMatrix;
AdjancencyMatrix.addEdge(0, 1, 5);	// Vertex 0 -> 1: weight 5
AdjancencyMatrix.addEdge(0, 2, 1);	// Vertex 0 -> 2: weight 1
AdjancencyMatrix.addEdge(0, 3, 8);	// Vertex 0 -> 3: weight 8
AdjancencyMatrix.addEdge(1, 2, 3);	// Vertex 1 -> 2: weight 3
AdjancencyMatrix.addEdge(2, 3, 1);	// Vertex 2 -> 3: weight 1

size_t SourceVertex = 0;
size_t DestVertex = 1;
std::vector<size_t> Path;

int SmallestWeight = Graph::dijkstra(AdjancencyMatrix, SourceVertex, DestVertex, Path);

std::cout << "vertex " << SourceVertex << " to vertex " << DestVertex << "`s shortest path is: " << std::endl;
for (auto Vertex : Path)
{
	std::cout << Vertex << " ";
}
std::cout << "\nAnd the smallest weight is: " << SmallestWeight << std::endl;
```

## 3. Prim
#### Usage: `#include "Graph.hpp"`
```C++
constexpr unsigned Vertices = 4;

Graph::AdjancencyMatrix<int, Vertices> AdjancencyMatrix;
AdjancencyMatrix.addEdge(0, 1, 5);	// Vertex 0 -> 1: weight 5
AdjancencyMatrix.addEdge(0, 2, 1);	// Vertex 0 -> 2: weight 1
AdjancencyMatrix.addEdge(0, 3, 8);	// Vertex 0 -> 3: weight 8
AdjancencyMatrix.addEdge(1, 2, 3);	// Vertex 1 -> 2: weight 3
AdjancencyMatrix.addEdge(2, 3, 1);	// Vertex 2 -> 3: weight 1

Graph::AdjancencyMatrix<int, Vertices> MST;
int MinWeight = Graph::prim(AdjancencyMatrix, MST);
```
