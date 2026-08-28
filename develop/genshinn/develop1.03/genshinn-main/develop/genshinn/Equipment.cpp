#include"Equipment.h"
#include<utility>


bool Equipment::isValidEquipment(const Item& item) const
{
	if(item.type == ItemType::Weapon && item.slot == EquipmentSlot::Weapon){
		return true;
	}

	if(item.type == ItemType::Armor && item.slot == EquipmentSlot::Armor){
		return true;
	}

	return false;
}

bool Equipment::equip(Inventory& inventory, int itemId)
{
	const ItemStack* stack = inventory.findItem(itemId);
	if(stack == nullptr || !isValidEquipment(stack->item)){
		return false;
	}

	const Item newItem = stack->item;
	Inventory updatedInventory = inventory;
	std::map<EquipmentSlot, Item> updatedEquipment = m_equippedItems;

	if(!updatedInventory.removeItem(newItem.id)){
		return false;
	}

	auto oldItem = updatedEquipment.find(newItem.slot);
	if(oldItem != updatedEquipment.end()){
		if(!updatedInventory.addItem(oldItem->second)){
			return false;
		}
		oldItem->second = newItem;
	}
	else{
		updatedEquipment.emplace(newItem.slot, newItem);
	}

	inventory = std::move(updatedInventory);
	m_equippedItems = std::move(updatedEquipment);
	return true;
}

bool Equipment::unequip(Inventory& inventory, EquipmentSlot slot)
{
	auto item = m_equippedItems.find(slot);
	if(item == m_equippedItems.end()){
		return false;
	}

	Inventory updatedInventory = inventory;
	if(!updatedInventory.addItem(item->second)){
		return false;
	}

	std::map<EquipmentSlot, Item> updatedEquipment = m_equippedItems;
	updatedEquipment.erase(slot);

	inventory = std::move(updatedInventory);
	m_equippedItems = std::move(updatedEquipment);
	return true;
}

const Item* Equipment::getEquippedItem(EquipmentSlot slot) const
{
	auto item = m_equippedItems.find(slot);
	if(item == m_equippedItems.end()){return nullptr;}
	return &(item->second);
}

bool Equipment::hasEquipped(EquipmentSlot slot) const
{
	return getEquippedItem(slot) != nullptr;
}

StatBonus Equipment::totalBonus() const
{
	StatBonus total;
	for(const auto& entry : m_equippedItems){
		total.attack += entry.second.bonus.attack;
		total.defense += entry.second.bonus.defense;
	}
	return total;
}

const std::map<EquipmentSlot, Item>& Equipment::equippedItems() const
{
	return m_equippedItems;
}
