#pragma once
#include "Queue.h"
#include <vector>

class BFS
{
public:
	std::vector<int> VisitVertex(std::vector<std::vector<int>> v)
	{
		Queue<int> queue(v.size());
		std::vector<int> visited;
		queue.Enqueue(0);

		int cur;
		while (queue.Count() != 0)
		{
			cur = queue.Dequeue();
			for (int Neighbor : v[cur])
				if (std::find(visited.begin(), visited.end(), Neighbor) == visited.end())
					queue.Enqueue(Neighbor);
			visited.push_back(cur);
		}
		return visited;
	}
};