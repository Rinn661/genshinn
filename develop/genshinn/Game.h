#ifndef GAME_H
#define GAME_H

#include<iostream>
#include"Player.h"

class Game {
public:
	void showTitle();			//展示标题
	void showMenu();			//游戏选择菜单
	void inputPlayerName();		//输入玩家名
	void showStory();			//前置剧情
	void run();					//运行
	void gameLoop();			//游戏循环
private:
	Player m_player;			//玩家实例
};


#endif

