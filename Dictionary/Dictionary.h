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
	/// 
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
	/// <param name="object">The item to look for</param>
	/// <returns></returns>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object">The value to look for</param>
	/// <returns></returns>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Tries to find the item that matches the given key
	/// </summary>
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

	const Dictionary<TKey, TValue>& operator= (const Dictionary<TKey, TValue>& other);

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
	delete m_items;
	m_count = 0;
}


template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	for (int i = 0; i < getCount(); i++)
		delete m_items;

	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{

	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == object)
		{
			std::cout << "Item Key found" << std::endl;
			return true;
		}
		else
			return false;
	}

}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemValue == object)
		{
			std::cout << "Item Value found" << std::endl;
			return true;
		}
		else
			return false;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == key)
		{
			value = m_items[i].itemValue;
			return true;
		}
		else
			return false;
	}
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	if (containsKey(key))
		return;

	Item* tempItemArray = new Item[getCount() + 1];

	for (int i = 0; i < getCount(); i++)
	{
		tempItemArray[i] = m_items[i];
	}
	
	tempItemArray[getCount()].itemKey = key;
	tempItemArray[getCount()].itemValue = value;
	delete m_items;
	m_items = tempItemArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	if (getCount() <= 0)
		return false;

	bool itemRemoved = false;

	Item* tempItem = new Item[getCount() - 1];
	int j = 0;
	
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempItem[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	//delete m_items;
	m_items = tempItem;
	m_count--;
	return itemRemoved;

}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	if (getCount() <= 0)
		return false;

	bool itemRemoved = false;

	Item* tempItemArray = new Item[m_count - 1];
	int j = 0;
	
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key && m_items[i].itemValue != value)
		{
			tempItemArray[j].itemKey = m_items[i].itemKey;
			tempItemArray[j].itemValue = m_items[i].itemValue;
			j++;
		}
		else
			itemRemoved = true;
	}

	delete m_items;
	m_items = tempItemArray;
	m_count--;
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
	//Delete the items in the list you want to copy
	delete m_items;

	Item* tempItemArray = other.m_items;

	for (int i = 0; i < other.getCount(); i++)
	{
		tempItemArray[i].itemKey = other.m_items[i].itemKey;
		tempItemArray[i].itemValue = other.m_items[i].itemValue;
	}

	m_count = other.getCount();

	return *this;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	Item* itemValueToFind = m_items;

	for (int i = 0; i < getCount(); i++)
	{
		if (itemValueToFind->itemKey == key)
			tryGetValue(key, itemValueToFind->itemValue);
	}

	std::cout << itemValueToFind->itemValue << std::endl;
	return itemValueToFind->itemValue;
}

