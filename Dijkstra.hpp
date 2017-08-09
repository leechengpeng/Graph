#pragma once
#include <climits>
#include "AdjancencyMatrix.hpp"

namespace Graph
{
	template <typename T>
	inline T TYPE_MAX()
	{
		T Max = T();
		Max |= _UI64_MAX;

		return Max == -1 ? Max ^ (Max << (sizeof(T) * 8 - 1)) : Max;
	}

	template <typename T, unsigned N>
	void dijkstra(const AdjancencyMatrix<T, N>& vAdjancencyMatrix, size_t vSource, size_t vPrevVertex[], T vDest[])
	{
		_ASSERT(vSource < N);
		static T INF = TYPE_MAX<T>();

		bool Visited[N] = { false };
		for (size_t i = 0; i < N; ++i)
		{
			vPrevVertex[i] = vSource;
			vDest[i] = INF;
		}
		vDest[vSource] = T();

		for (size_t i = 0; i < N; ++i)
		{
			T MinWeight = INF;
			size_t MinWeightIndex = 0;
			for (size_t k = 0; k < N; ++k)
			{
				if (!Visited[k] && vDest[k] <= MinWeight)
				{
					MinWeightIndex = k;
					MinWeight = vDest[k];
				}
			}
			Visited[MinWeightIndex] = true;

			for (size_t k = 0; k < N; ++k)
			{
				if (!Visited[k] && vAdjancencyMatrix.connect(MinWeightIndex, k) 
					&& MinWeight + vAdjancencyMatrix.getEdgeWeight(MinWeightIndex, k) < vDest[k])
				{
					vDest[k]    = MinWeight + vAdjancencyMatrix.getEdgeWeight(MinWeightIndex, k);
					vPrevVertex[k] = MinWeightIndex;
				}
			}
		}
	}
}
