#ifndef MAPBEACH_H
#define MAPBEACH_H
#include <string>
#include "Player.h"
#include"MapBase.h"

class MapBeach :public MapBase
{
public:
    std::string m_MapName="鹰翔海滩";
    MapBeach(std::string name);
};

class MapEagleBeach : public MapBeach
{
private:
    int  m_py;                              //鹰翔海滩只有y值，当前y值
    bool m_beachEventDone;                  //当前小区域事件是否完成
    void getTileDesc() override;            //我需要每一个小地图有一个环境描写
    void drawMiniMap();                     //在当前大地图绘制小地图（鹰翔海滩）
};


#endif