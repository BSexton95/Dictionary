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

	Dictionary<int, const char*> inventory =  Dictionary<int, const char*>();
	
	//Testing addItem Function
	std::cout << "Testing addItem Function:" << std::endl;
	inventory.addItem(2, "Two");
	inventory.addItem(1, "One");
	inventory.addItem(3, "Three");
	inventory.addItem(4, "Four");
	print(inventory);
	std::cout << "" << std::endl;

	//Testing the remove Function
	std::cout << "Testing the remove Function: " << std::endl;
	inventory.remove(3);
	inventory.remove(4);
	print(inventory);
	std::cout << "" << std::endl;

	//Testing the remove that returns a value Funciton
	std::cout << "Testing the remove function that returns a value: " << std::endl;
	const char* value;
	inventory.remove(2, value);
	std::cout << "The value returned: " << value << std::endl;
	std::cout << " " << std::endl;

	//Testing the getCount Function
	std::cout << "Testing the getCount Funciton: " << std::endl;
	std::cout << inventory.getCount() << std::endl;
	std::cout << "" << std::endl;

	//Testing the containsKey Function and containsValue Function
	std::cout << "Testing the containsKey and the containsValue Function: " << std::endl;
	if (inventory.containsKey(1))
		std::cout << "Yay" << std::endl;
	std::cout << " " << std::endl;

	if (inventory.containsValue("One"))
		std::cout << "Yay" << std::endl;
	std::cout << "" << std::endl;

	//Testing the equal operator
	std::cout << "Testing the equals operator: " << std::endl;
	Dictionary<int, const char*> inventory2 = inventory;
	//delete inventory;
	
	
	print(inventory2);


}