#pragma once
#include <iostream>

template<typename TKey, typename TValue>
class Dictionary
{
public:
	/// <summary>
	/// Constructor for Dictionary
	/// </summary>
	Dictionary<TKey, TValue>() {};

	/// <summary>
	/// Constructor sets a item array equal to another
	/// </summary>
	/// <param name="other"></param>
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);

	/// <summary>
	/// Deconstructor for Dictionary
	/// </summary>
	~Dictionary<TKey, TValue>();

	/// <summary>
	/// Deletes all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks to see if an item that has the given key is in the dictionary
	/// </summary>
	/// <param name="object">The item key to find</param>
	/// <returns>True if the key is found</returns>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object">The item value to find</param>
	/// <returns>True if item value is found</returns>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Tries to find the item that matches the given key
	/// </summary>
	/// <param name="key">The item key to which the value should be returned</param>
	/// <param name="value">The value found</param>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// Creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// removes the item that has the given key
	/// </summary>
	/// <param name="key">The key of the item to remove</param>
	/// <returns>If the key was removed or not</returns>
	bool remove(const TKey key);

	/// <summary>
	/// Removes the item that has the given key and gives back the value of the item that was removed
	/// </summary>
	/// <param name="key">The key of the item to be removed</param>
	/// <param name="value">The value of the item to be removed</param>
	/// <returns>If the item was removed</returns>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Gets the number of items in the dictionary
	/// </summary>
	/// <returns></returns>
	int getCount() const;

	/// <summary>
	/// Copies an item array over to another.
	/// </summary>
	/// <param name="other">The list to copy over</param>
	/// <returns></returns>
	const Dictionary<TKey, TValue>& operator= (const Dictionary<TKey, TValue>& other);

	/// <param name="key">The key that is attached to the item that you want to find the value of</param>
	/// <returns>An item value that has the key</returns>
	TValue operator[](const TKey key);

private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	clear();
}


template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//Iterates through the item array
	for (int i = 0; i < getCount(); i++)
	{
		//If the item key is equal to the key to be found...
		if (m_items[i].itemKey == object)
		{
			return true;
		}
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//Iterate through the item array
	for (int i = 0; i < getCount(); i++)
	{
		//If the value of the item is equal to the value to be found...
		if (m_items[i].itemValue == object)
		{
			return true;
		}
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//Iterate through the item array
	for (int i = 0; i < getCount(); i++)
	{
		//If the items key is equal to the key you want to find the value of...
		if (m_items[i].itemKey == key)
		{
			//...set value equal to the value of the item that matched the key amd return true
			value = m_items[i].itemValue;
			return true;
		}
	}

	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	//If the item array already has the key to be added...
	if (containsKey(key))
		//...exit the function
		return;

	//Create a temperary array that is one greater than the original
	Item* tempItemArray = new Item[getCount() + 1];

	//Iterate through the original item array
	for (int i = 0; i < getCount(); i++)
	{
		//Copy all items from original array to the temprary array
		tempItemArray[i] = m_items[i];
	}
	
	//If item is first in the array set the key and value to be at index 0
	tempItemArray[getCount()].itemKey = key;
	tempItemArray[getCount()].itemValue = value;

	//delete the original items array
	delete m_items;
	//Set the original items array to be the temprary item array
	m_items = tempItemArray;
	//Incremeant the count
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//If the array is empty...
	if (getCount() <= 0)
		//...return false and exit function
		return false;

	//boolean that keeps track if item has been removed set to false
	bool itemRemoved = false;

	//Create a temperary item array that is one less than the original
	Item* tempItemArray = new Item[getCount() - 1];
	//Create variable to access temperary array  index
	int j = 0;
	
	//Iterate through the origianl item array 
	for (int i = 0; i < getCount(); i++)
	{
		//If the items key is not equal to the items key to be removed...
		if (m_items[i].itemKey != key)
		{
			//...copy the item into the temperary array
			tempItemArray[j] = m_items[i];
			//Increment tempItemArrays index
			j++;
		}
		//Otherwise the item was found and not copyed into the temperary array
		else
		{
			//Set the item removeved boolean to true
			itemRemoved = true;
		}
	}

	//Delete the original item array
	delete m_items;
	//Set the items array to be the temperary item array
	m_items = tempItemArray;
	//Decrement the count
	m_count--;
	//Return if the item removed was true or false
	return itemRemoved;

}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//If the item array is empty...
	if (getCount() <= 0)
	{
		//Set the value to be null
		value = NULL;
		//...return false and exit the function
		return false;
	}

	//Boolean that keeps track if the item has been removed or not
	bool itemRemoved = false;

	//Create a temperary item array that is one less than the original
	Item* tempItemArray = new Item[getCount() - 1];
	//Create variable to access temperary array  index
	int j = 0;
	
	//Iterate through the origianl item array 
	for (int i = 0; i < getCount(); i++)
	{
		//If the items key and items value are not equal to the key or value...
		if (m_items[i].itemKey != key && m_items[i].itemValue != value)
		{
			//...Copy the item into the temperary array
			tempItemArray[j] = m_items[i];
			//Increment the index of the temperary array
			j++;
		}
		//Otherwise the item to be removed was found and not copyed to the temprary array
		else
		{
			//Value is set the be the item to be removed value.
			value = m_items[i].itemValue;
			//Item removed is set to true
			itemRemoved = true;
		}
	}

	//Delete the original item array
	delete m_items;
	//Set the item array to be the temperary item array
	m_items = tempItemArray;
	//Decrement the count
	m_count--;
	//return if the item was removed or not
	return itemRemoved;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue>& other)
{
	//Clear function is called to clear out the items you no longer want
	clear();

	//Create a temperary item array that is equal to the item array you want to copy
	Item* tempItemArray = other.m_items;

	//Iterate through the array that is being copyed
	for (int i = 0; i < other.getCount(); i++)
	{
		//Copy all items to the temprary array
		tempItemArray[i].itemKey = other.m_items[i].itemKey;
		tempItemArray[i].itemValue = other.m_items[i].itemValue;
	}

	//Set the count to be the the list that is being copyed count
	m_count = other.getCount();

	//Return the items array
	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	//Create a variable that is an items value
	TValue value;

	//If the key is in the items array...
	if (tryGetValue(key, value))
	{
		//return the value
		return value;
	}
	//Otherwise return TValue
	else
		return TValue();
	
	
}

