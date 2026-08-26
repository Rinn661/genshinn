#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<iostream>
class Player {
private:
	std::string name;		//玩家名
	int LV;					//等级
	float NHP;				//当前血量
	float MHP;				//最大血量
	float TP;				//体力
	float ENERGY;			//元素充能
//================属性区====================
public:
	Player();
	void setName(std::string n);
	std::string getName();

//==========================================
	int getLV();			
	float getNHP();
	float getMHP();
	float getTP();
	float getENERGY();
//==========================================
	void setLV(int lv);
	void setNHP(float nhp);
	void setMHP(float mhp);
	void setTP(float tp);
	void setENERGY(float e);
//==========================================
};




#endif 

