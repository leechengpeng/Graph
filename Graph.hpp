#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include "AdjancencyMatrix.hpp"

namespace Graph
{
	template <typename T, unsigned N>
	T dijkstra(const AdjancencyMatrix<T, N>& vAdjancencyMatrix, size_t vSource, size_t vDest, std::vector<size_t>& vPath)
	{
		_ASSERT(vSource < N && vDest < N && vPath.empty());

		T      Dest[N] = { 0 };
		size_t PrevVertices[N] = { 0 };

		Graph::dijkstra(vAdjancencyMatrix, vSource, PrevVertices, Dest);

		std::vector<size_t> TempPath;
		for (size_t i = vDest; i != vSource; i = PrevVertices[i])
		{
			TempPath.push_back(i);
		}
		TempPath.push_back(vSource);

		for (auto Iter = TempPath.rbegin(); Iter != TempPath.rend(); ++Iter)
		{
			vPath.push_back(*Iter);
		}

		return Dest[vDest];
	}

	template <typename T, unsigned N>
	void dijkstra(const AdjancencyMatrix<T, N>& vAdjancencyMatrix, size_t vSource, size_t vPrevVertex[], T vDest[])
	{
		_ASSERT(vSource < N);
		static T INF = _TYPE_MAX<T>();

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
					vDest[k] = MinWeight + vAdjancencyMatrix.getEdgeWeight(MinWeightIndex, k);
					vPrevVertex[k] = MinWeightIndex;
				}
			}
		}
	}

	template <typename T, unsigned N>
	T prim(const AdjancencyMatrix<T, N>& vAdjancencyMatrix, AdjancencyMatrix<T, N>& voMST)
	{
		static T INF = _TYPE_MAX<T>();

		T	   Dest[N] = { INF };
		size_t PrevVertex[N] = { 0 };
		size_t Source = 0;

		T MSTWeight = prim(vAdjancencyMatrix, Source, PrevVertex, Dest);

		for (size_t i = 0; i < N; ++i)
		{
			if (i != Source)
			{
				voMST.addEdge(i, PrevVertex[i], Dest[i]);
			}
		}

		return MSTWeight;
	}

	template <typename T, unsigned N>
	T prim(const AdjancencyMatrix<T, N>& vAdjancencyMatrix, size_t vSource, size_t vPrevVertex[], T vDest[])
	{
		_ASSERT(vSource < N);
		static T INF = _TYPE_MAX<T>();

		bool Visited[N] = { false };
		for (size_t i = 0; i < N; ++i)
		{
			if (vAdjancencyMatrix.connect(vSource, i))
			{
				vDest[i] = vAdjancencyMatrix.getEdgeWeight(vSource, i);
			}
		}
		Visited[vSource] = true;

		T MSTWeight = T();
		for (size_t i = 1; i < N; ++i)
		{
			T MinEdge = INF;
			size_t MinIndex = 0;
			for (size_t k = 0; k < N; ++k)
			{
				if (!Visited[k] && vDest[k] <= MinEdge)
				{
					MinIndex = k;
					MinEdge = vDest[k];
				}
			}
			Visited[MinIndex] = true;

			MSTWeight += MinEdge;

			for (size_t k = 0; k < N; ++k)
			{
				if (!Visited[k] && vAdjancencyMatrix.connect(MinIndex, k)
					&& vAdjancencyMatrix.getEdgeWeight(MinIndex, k) < vDest[k])
				{
					vDest[k] = vAdjancencyMatrix.getEdgeWeight(MinIndex, k);
					vPrevVertex[k] = MinIndex;
				}
			}
		}

		return MSTWeight;
	}

	template <typename T>
	inline T _TYPE_MAX()
	{
		T Max = T();
		Max |= _UI64_MAX;

		return Max == -1 ? Max ^ (Max << (sizeof(T) * 8 - 1)) : Max;
	}
}
