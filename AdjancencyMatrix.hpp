#pragma once
#include <vector>

namespace Graph
{
	template <typename T, unsigned N>
	class AdjancencyMatrix
	{
	public:
		AdjancencyMatrix() : m_Matrix() {}

		void addEdge(size_t vSourceIndex, size_t vDestIndex, T vWeight = T());
		bool connect(size_t vSourceIndex, size_t vDestIndex) const;
		T    getEdgeWeight(size_t vSourceIndex, size_t vDestIndex) const;

		// TODO：Using iterator to visit inner element
		std::vector<size_t> getAdjancencyVertices(size_t vVertexIndex) const;

	private:
		T m_Matrix[N][N];
	};

	template <typename T, unsigned N>
	void AdjancencyMatrix<T, N>::addEdge(size_t vSourceIndex, size_t vDestIndex, T vWeight)
	{
		_ASSERT(vSourceIndex < N && vDestIndex < N);
		// NOTE：Vertex X to X`s self default zero
		if (vSourceIndex != vDestIndex)
		{
			m_Matrix[vSourceIndex][vDestIndex] = vWeight;
			m_Matrix[vDestIndex][vSourceIndex] = vWeight;
		}
	}

	template <typename T, unsigned N>
	bool AdjancencyMatrix<T, N>::connect(size_t vSourceIndex, size_t vDestIndex) const
	{
		_ASSERT(vSourceIndex < N && vDestIndex < N);
		return m_Matrix[vSourceIndex][vDestIndex] != 0;
	}

	template <typename T, unsigned N>
	T AdjancencyMatrix<T, N>::getEdgeWeight(size_t vSourceIndex, size_t vDestIndex) const
	{
		_ASSERT(vSourceIndex < N && vDestIndex < N);
		return m_Matrix[vSourceIndex][vDestIndex];
	}

	template <typename T, unsigned N>
	std::vector<size_t> AdjancencyMatrix<T, N>::getAdjancencyVertices(size_t vVertexIndex) const
	{
		_ASSERT(vVertexIndex < N);
		
		std::vector<size_t> AdjancencyVertices;
		for (size_t i = 0; i < N; ++i)
		{
			if (m_Matrix[vVertexIndex][i] != 0)
			{
				AdjancencyVertices.push_back(i);
			}
		}

		return AdjancencyVertices;
	}
}

// ***************************************************************
// testcase
void test_AdjancencyMatrix()
{
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
	_ASSERT(AdjancencyVertices.at(0) == 1);
	_ASSERT(AdjancencyVertices.at(1) == 2);
	_ASSERT(AdjancencyVertices.at(2) == 3);
}
