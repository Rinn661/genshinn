#ifndef GAME_H
#define GAME_H

#include<iostream>
#include"Player.h"
#include"MapBase.h"

class Game {
public:
	Game();
	~Game();
	void showTitle();			//展示标题
	void showMenu();			//游戏选择菜单
	void inputPlayerName();		//输入玩家名
	void showStory();			//前置剧情
	void run();					//运行
	void changeMap(int id);		//切换地图
	void gameLoop();			//游戏循环
	int  getMapid();			//获取地图id
private:
	Player m_player;			//玩家实例
	int m_currentMapid=1;		//当前大地图id
	MapBase* m_pCurrentMap;		//地图基类指针
};


#endif

