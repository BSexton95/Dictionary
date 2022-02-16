#include "Dictionary.h"
#include <iostream>

void print(Dictionary<int, const char*> dictionary)
{
	for (int i = 1; i <= dictionary.getCount(); i++)
	{
		std::cout << dictionary[i] << std::endl;
	}
}
void main()
{
	//Dictionary<int, int> inventory;

	//inventory.addItem(1, 4);
	//inventory.addItem(2, 5);
	//inventory.addItem(3, 6);
	////inventory.remove(1);
	//inventory.remove(2);
	////inventory.clear();
	//int value;
	//inventory.remove(2, value);
	//if (value == NULL)
	//	std::cout << "Error" << std::endl;
	//else
	//	std::cout << value << std::endl;
	//std::cout << inventory.getCount() << std::endl;
	/*int value;
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
	
	inventory[1];*/

	Dictionary<int, const char*>* inventory =  new Dictionary<int, const char*>();
	
	inventory->addItem(2, "Two");
	inventory->addItem(1, "One");
	inventory->addItem(3, "Three");
	inventory->addItem(4, "Four");
	const char* test;
	//inventory.remove(2);
	if (inventory->containsKey(5))
		std::cout << "Yay" << std::endl;
	Dictionary<int, const char*> inventory2 = *inventory;
	delete inventory;
	
	
	print(inventory2);


}