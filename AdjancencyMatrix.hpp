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
	inline bool AdjancencyMatrix<T, N>::connect(size_t vSourceIndex, size_t vDestIndex) const
	{
		_ASSERT(vSourceIndex < N && vDestIndex < N);
		return m_Matrix[vSourceIndex][vDestIndex] != 0;
	}

	template <typename T, unsigned N>
	inline T AdjancencyMatrix<T, N>::getEdgeWeight(size_t vSourceIndex, size_t vDestIndex) const
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
