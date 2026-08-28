#include "MapBeach.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>


MapBeach::MapBeach(std::string name) : m_MapName(name) {}

void MapEagleBeach::getTileDesc() {
    if (m_py == 0) std::cout <<" 海浪拍打着岸边礁石，你苏醒在这里。";
    if (m_py == 1)std::cout<<"向北走，滩上散落贝壳。";
    if (m_py == 2) std::cout << "再向北走视野开阔，可以眺望整片海滩，远方似乎有城镇。";
}

void MapEagleBeach::drawMiniMap()
{
    std::cout << "\n-----鹰翔海滩-----\n";
    std::cout << (m_py == 2 ? "■ " : "□ ") << "\n";
    std::cout << (m_py == 1 ? "■ " : "□ ") << "\n";
    std::cout << (m_py == 0 ? "■ " : "□ ") << "\n";
    std::cout << "------------------\n";
    std::cout << "■ =你的位置\n";
}