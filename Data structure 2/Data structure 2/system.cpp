#include "system.h"

System::System(int roads_size, int actions_size) : roads_size_(roads_size), actions_size_(actions_size), roads_(new Road * [roads_size]), heap_(Heap(roads_size, &roads_))
{
	for (int index = 0; index < roads_size; index++)
		roads_[index] = new Road(index, actions_size);
}

void System::AddBridge(float height, int road)
{
	int new_bridge_road = road - 1;
	roads_[new_bridge_road]->insertBridge(height);
	if (roads_[new_bridge_road]->getMin() > height)
	{
		roads_[new_bridge_road]->setMin(height);
		if (roads_[new_bridge_road]->getHeapIndex() == NO_BRIDGE)
			heap_.insert(road);
		else
			heap_.updateRoad(new_bridge_road);
	}
}

int System::WhichRoad(float height)
{
	float max_val = heap_.getMaxVal();

	if (max_val < height)
		return heap_.getMaxRoad();
	else
		return 0;
}