#ifndef MAPBASE_H
#define MAPBASE_H
#include <string>
#include "Player.h"

class MapBase
{
public:
    static void getMapName(int Mapid);                     //根据ID打印地图名
    virtual void getTileDesc(){std::cout << "未知地块";}   //环境描写等细节
};

#endif
