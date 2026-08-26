#include"Game.h"
#include<iostream>
#include <cstdlib>		// system()
#include <conio.h>		// _getch() windows按任意键


void Game::showTitle()	//标题UI
{

		std::cout << "\033[36m==================================================================================================================================================";
		std::cout << R"(
  捕　　　　　捕　捕　　　　风风风风风风风风　　　　　　　的　　　的　　　　　　异异异异异异异异异　　　　　　乡　　　　　　    　　人
　捕　　捕捕捕捕捕捕捕　　　风　　　　　　风　　　　　　的　　　　的　　　　　　异　　　　　　　异　　　　　乡　　　　　　　　    　人
捕捕捕　　　　捕　　　　　　风　　　　风　风　　　　的的的的的　　的的的的　　　异异异异异异异异异　　　　乡　　　　乡　　　　　　　人
　捕　　捕捕捕捕捕捕捕　　　风　风　　风　风　　　　的　　　的　的　　　的　　　异　　　　　　　　异　　乡乡乡乡乡乡　　　　　　　　人
　捕　　捕　　捕　　捕　　　风　　风　风　风　　　　的　　　的　的　　　的　　　异异异异异异异异异异　　　　　乡　　　　　　　　　人　人
　捕捕　捕捕捕捕捕捕捕　　　风　　　风　　风　　　　的　　　的　　的　　的　　　　异　　　　　异　　　　　　乡　　　　　　　　　　人　人
捕捕　　捕　　捕　　捕　　　风　　　风　　风　　　　的的的的的　　　的　的　　　　异　　　　　异　　　　　乡　　　　　乡　　　　人　　　人
　捕　　捕捕捕捕捕捕捕　　　风　　风　风　风　风　　的　　　的　　　的　的　　异异异异异异异异异异异　　乡乡乡乡乡乡乡　　　　　人　　　人
　捕　　捕　　捕　　捕　　　风　风　　风　风　风　　的　　　的　　　　　的　　　　异　　　　　异　　　　　　　　　乡　　　　　人　　　　　人
　捕　　捕　　捕　　捕　　风　　　　　风　风　风　　的　　　的　　　　　的　　　　异　　　　　异　　　　　　　乡乡　　　　　人　　　　　　　人
捕捕　　捕　　捕　捕捕　　风　　　　　　　　风　　　的的的的的　　　的的的　　　异　　　　　　异　　　　乡乡乡　　　　　　人　　　　　　　　　人
)" << std::endl;
		std::cout << "==================================================================================================================================================\n\n\n" << std::endl;
		std::cout << "按任意键继续...\033[0m" << std::endl;
		(void)_getch();			 // Windows 等待按键
		system("cls");		     // 清屏，进入菜单
	
}

void Game::inputPlayerName()	 //输入名字
{
	system("cls");
	std::string tempName;
	std::cout << "\033[35m=========================================================================\n";
		std::cout << "请输入旅行者的名字：";
	std::cin >> tempName;
	m_player.setName(tempName);
	std::cout << "=========================================================================";
	std::cout << "\n 您好！尊敬的"<< m_player.getName() <<",欢迎游玩这款游戏！！\n\n按任意键继续...\033[0m";
	(void)_getch();
	system("cls");

}

void Game::showMenu() {
	int select = 0;
	while (true)
	{
		system("cls");
		std::cout << "\033[34m=====主菜单=====\n";
		std::cout << "1.开始游戏\n";
		std::cout << "2.继续游戏 \n";
		std::cout << "3.结束游戏 \n";
		std::cout << "请输入选项:\033[0m";
		std::cin >> select;
		if (select == 1)
		{
			std::cout << "\033[34m\n>>开始新游戏\n\033[0m";
			(void)_getch();
			system("cls");
			inputPlayerName();
			showStory();
			break;
		}
		else if (select == 2)
		{
			std::cout << "\n>>读取存档，继续游戏\n";
			break;
		}
		else if (select == 3)
		{
			std::cout << "\n>>退出游戏\n";
			std::exit(0); 
		}
		else
		{
			std::cout << "\n未识别到有效指令";
			std::cin.ignore();
			std::cin.get();
		}
	}
	gameLoop();
}
void Game::showStory()
{
	system("cls");
	std::cout << "\033[34m================================================================================================================================" << std::endl;
	std::cout << "一觉醒来，你发现睁开眼却发现自己看到的不是熟悉的天花板，而是一处傍水的沙地，作为资深的原皮，你立刻明白了这里是鹰翔海滩,以及这" << std::endl;
	std::cout << "意味着什么——没错，你来到了提瓦特大陆，只可惜你并没有向导，不过，凭借着你对提瓦特大陆的了解，想必能够活出更加精彩的人生吧？不" << std::endl;
	std::cout << "论这到底是梦还是真正的穿越，总之，先决定你的第一个行动吧！！！" << std::endl;
	std::cout << "\033=================================================================================================================================" << std::endl;
	std::cout << "\n按任意键继续...\033[0m";
	(void)_getch();
	system("cls");
	std::cout << "\033[34m\n序章:听从风的指引\n\033[0m";
	(void)_getch();
	system("cls");
}

void Game::run(){

    showTitle();  
    showMenu();  
}

void Game::gameLoop()
{
	
		int op;
		while (true)		  // 死循环
		{
			system("cls");
					          //  待机界面（当前场景）
			std::cout << "\033[36m===== 鹰翔海滩 =====\033[0m\n";
			std::cout << "海风扑面而来，海浪拍打着岸边的礁石。\n";
			std::cout << "你身处陌生的提瓦特大陆，接下来要做什么？\n\n";

			std::cout << "1. 四处探索 \n";
			std::cout << "2. 查看角色状态 \n";
			std::cout << "3. 打开背包 \n";
			std::cout << "4. 保存游戏 \n";
			std::cout << "5. 返回主菜单 \n";
			std::cout << "6. 退出游戏 \n";
			std::cout << "请输入你的行动：";

			std::cin >> op;

			if (op == 1)
			{
				std::cout << "\n 你开始四处探索海滩...";
				(void)_getch();
			}
			else if (op == 2)
			{
				std::cout << "\n【角色状态界面】";
				std::cout << "\n====角色状态====" << std::endl;
				std::cout << "名字：" << m_player.getName() << std::endl;
				std::cout << "等级：" << m_player.getLV() << std::endl;
				std::cout << "血量：" << m_player.getNHP()<<"/"<<m_player.getMHP() << std::endl;
				std::cout << "体力：" << m_player.getTP() << std::endl;
				std::cout << "元素充能：" << m_player.getENERGY() << std::endl;

				(void)_getch();
			}
			else if (op == 3)
			{
				std::cout << "\n【背包界面】";
				(void)_getch();
			}
			else if (op == 4)
			{
				std::cout << "\n 游戏已保存！";
				(void)_getch();
			}
			else if (op == 5)
			{
				break;
			}
			else if (op == 6)
			{
				return ;
				break;
			}
			else
			{
				std::cout << "\n 无效输入！";
				std::cin.ignore();
				std::cin.get();
			}
		}
}
