#ifndef ITEM_H
#define ITEM_H
#include<string>

//================物品类型====================
enum class ItemType {
	Consumable,		//消耗品
	Weapon,			//武器
	Armor,			//防具
	Quest			//任务物品
};

//================装备位置====================
enum class EquipmentSlot {
	None,			//不可装备
	Weapon,			//武器
	Armor			//护甲
};

//================属性加成====================
struct StatBonus {
	float attack{0.0f};		//攻击力加成
	float defense{0.0f};		//防御力加成
};

//================物品数据====================
struct Item {
	int id{0};
	std::string name;
	ItemType type{ItemType::Consumable};
	EquipmentSlot slot{EquipmentSlot::None};
	std::string description;
	bool stackable{true};
	float healAmount{0.0f};
	StatBonus bonus;
};

#endif
