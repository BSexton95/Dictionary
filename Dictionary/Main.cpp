#include "Dictionary.h"
#include <iostream>

void main()
{
	Dictionary<int, int> inventory;

	inventory.addItem(1, 4);
	inventory.addItem(2, 5);
	inventory.addItem(3, 6);
	inventory.remove(1);
	std::cout << inventory.getCount() << std::endl;
	inventory.containsKey(2);
	inventory.containsValue(5);

	if (inventory.containsKey(1))
		std::cout << "Found" << std::endl;
	/*Dictionary<int, int> second;

	second.addItem(3, 5);

	second = inventory;*/
	////inventory.clear();
	//std::cout << second.getCount() << std::endl;
	//
	//inventory[1];
}