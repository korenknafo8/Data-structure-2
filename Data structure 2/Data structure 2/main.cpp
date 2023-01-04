#include "system.h"

void roadBuilding(System TLV, int actions_size);


int main()
{
	int road_size, actions_size;
	char selection;
	float bridge_height;
	cin >> road_size >> actions_size;

	System TLV(road_size, actions_size);
	cin >> selection;
	if (selection != 'a')
		return 0; //exception
	if (selection > 'd' || selection < 'a')
		return 0; //exception

	roadBuilding(TLV, actions_size - 1);

	return 0;
}

void roadBuilding(System TLV, int size)
{
	int road_size, road;
	char selection;
	float bridge_height;
	for (int i = 0; i < size; i++)
	{
		cin >> selection;
		switch (selection)
		{
		case 'b':
			cin >> bridge_height >> road;
			TLV.AddBridge(bridge_height, road);
			break;
		case 'c':
			cin >> bridge_height;
			TLV.WhichRoad(bridge_height);
			break;
		case 'd':
			cin >> road;
			TLV.print(road);
		default:
			//error
			break;
		}
	}
}