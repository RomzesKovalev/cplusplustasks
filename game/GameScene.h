#pragma once
#include "TmxLevel.h"
using namespace std;


struct GameView;

struct GameScene
{
    TmxLevel level;
    TmxObject player;
    vector<TmxObject> enemies;
    vector<TmxObject> coins;
    vector<TmxObject> block;
    sf::Vector2f startPosition;
};

GameScene *NewGameScene();
void UpdateGameScene(void *pData, GameView &view, float deltaSec);
void DrawGameScene(void *pData, GameView &view);
void DestroyGameScene(GameScene *&pScene);
