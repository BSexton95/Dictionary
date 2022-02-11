#pragma once




template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
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
	bool tryGetValue(const TKey key, const TValue& value) const;

	/// <summary>
	/// Creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	addItem(const TKey& key, const TValue& value);

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

	const operator= (const Dictionary<TKey, Tvalue> other);

private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item<TKey, TValue>* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{

}
