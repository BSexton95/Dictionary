#include "Dictionary.h"
#include <iostream>

void main()
{
	Dictionary<int, int> inventory;

	inventory.addItem(1, 4);
	inventory.addItem(2, 5);
	inventory.addItem(3, 6);
	inventory.remove(1);
	inventory.remove(2);
	int value;
	inventory.remove(3, value);
	inventory[1];
	std::cout << "Item value removed: " << value << std::endl;
	std::cout << inventory.getCount() << std::endl;
	inventory.containsKey(2);
	inventory.containsValue(5);

	if (inventory.containsKey(1))
		std::cout << "Found" << std::endl;
	Dictionary<int, int> second;

	second.addItem(4, 9);

	second = inventory;
	inventory.clear();
	std::cout << second.getCount() << std::endl;
	
	inventory[1];
}