#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include"Inventory.h"
#include<map>

//================装备系统====================
class Equipment {
private:
	std::map<EquipmentSlot, Item> m_equippedItems;

	bool isValidEquipment(const Item& item) const;

public:
	bool equip(Inventory& inventory, int itemId);
	bool unequip(Inventory& inventory, EquipmentSlot slot);

	const Item* getEquippedItem(EquipmentSlot slot) const;
	bool hasEquipped(EquipmentSlot slot) const;
	StatBonus totalBonus() const;
	const std::map<EquipmentSlot, Item>& equippedItems() const;
};

#endif
