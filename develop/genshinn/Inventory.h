#ifndef INVENTORY_H
#define INVENTORY_H
#include"Item.h"
#include<cstddef>
#include<vector>

//================物品堆叠====================
struct ItemStack {
	Item item;
	int quantity{1};
};

//================背包系统====================
class Inventory {
private:
	std::size_t m_capacity;
	std::vector<ItemStack> m_items;

public:
	explicit Inventory(std::size_t capacity = 20);

	bool addItem(const Item& item, int quantity = 1);
	bool removeItem(int itemId, int quantity = 1);
	bool discardItem(int itemId, int quantity = 1);

	const ItemStack* findItem(int itemId) const;
	int quantityOf(int itemId) const;
	bool isFull() const;
	std::size_t getUsedSlots() const;
	std::size_t getCapacity() const;
	const std::vector<ItemStack>& items() const;
};

#endif
