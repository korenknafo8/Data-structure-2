#include "system.h"

System::System(int roads_size)
{
	roads_size_ = roads_size;
	Road* roads_ = new Road[roads_size];

	for (int index = 0; index < roads_size; index++)
		roads_->setMin(UN_INITIALIZED);
}
