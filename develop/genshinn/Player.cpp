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
std::string Player::getName() const{return name;}
int Player::getLV() const{return LV;}
float Player::getNHP() const{return NHP;}
float Player::getMHP() const{return MHP;}
float Player::getTP() const{return TP;}
float Player::getENERGY() const{return ENERGY;}

void Player::setLV(int lv){LV = lv < 1 ? 1 : lv;}

void Player::setNHP(float nhp)
{
	if(nhp < 0.0f){NHP = 0.0f;}
	else if(nhp > MHP){NHP = MHP;}
	else{NHP = nhp;}
}

void Player::setMHP(float mhp)
{
	MHP = mhp < 1.0f ? 1.0f : mhp;
	if(NHP > MHP){NHP = MHP;}
}

void Player::setTP(float tp){TP = tp < 0.0f ? 0.0f : tp;}

void Player::setENERGY(float e)
{
	if(e < 0.0f){ENERGY = 0.0f;}
	else if(e > 100.0f){ENERGY = 100.0f;}
	else{ENERGY = e;}
}
