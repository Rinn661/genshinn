#include<iostream>
#include"Player.h"


Player::Player()	 // 构造函数
{
	name = "";       // 名字留空
	LV = 1;          // 初始等级1
	NHP = 100.0f;    // 初始血量100
	MHP = 100.0f;	 // 初始血上限100
	TP = 80.0f;      // 体力
	ENERGY = 0.0f;   // 元素充能初始0
}

void Player::setName(std::string n){name = n;}
std::string Player::getName(){return name;}
int Player::getLV(){return LV;}
float Player::getNHP(){return NHP;}
float Player::getMHP(){return MHP; }
float Player::getTP(){return TP;}
float Player::getENERGY(){return ENERGY;}

void Player::setLV(int lv){LV = lv;}
void Player::setNHP(float nhp){NHP = nhp;}
void Player::setMHP(float mhp){NHP = mhp;}
void Player::setTP(float tp){TP = tp;}
void Player::setENERGY(float e){ENERGY = e;}
