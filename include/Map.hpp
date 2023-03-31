#ifndef Map_hpp
#define Map_hpp

#include <string>

class Map {

public:
    Map(std::string tID, int ms, int ts);
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
    void addTile(int srcX, int srcY, int x, int y);

private:
    std::string texID = "";
    int mapScale = 1;
    int tileSize = 32;
    int scaledSize = 32;
};

#endif