#include "road.h"

Road::Road(int index, int actions_size)
{
	bridge_phs_size_ = actions_size;
	bridges_ = new float[bridge_phs_size_];
	heap_index_ = index;
}


void Road::printBridges()
{
	for (int i = 0; i < bridges_log_size_; i++)
		cout << bridges_[i] << endl;
}