// PrepareScene.h

#ifndef __PREPARE_SCENE_H__
#define __PREPARE_SCENE_H__

#include "cocos2d.h"
#include "GridMap.h"
#include "PlayerManager.h"
#include "Chess.h"
// #include "ChessFactory.h"
#include "PrototypeRegistry.h"
#include "PreparationSeats.h"
#include "Store.h"
#include "LittleHero.h"
#include "FightScene.h"
#include "./Refactor/CompositeComponent.cpp"
#include "CompositeComponent.h"
#include "ISubject.h"
#include "IObserver.h"
#include "CountdownLabel.h"
USING_NS_CC;
class PrepareScene : public cocos2d::Scene,public ISubject
{
public:
    /*Player* myPlayer;
    Player* enemyPlayer;
    Sprite* backgroundImg;
    GridMap* gridMap;
    Chess* selectedChess;
    EventListenerMouse* prepareSceneMouseListener;
    PreparationSeats* preSeats;
    Store* store;
    LittleHero* littleHero;
    LittleHero* littleHeroEnemy;*/ // refactoring with composite pattern
    Vector<Component*> sceneComponents; // refactored with composite pattern
    Vector<IObserver*> observers; // refactored with observer pattern
    float remainingTime = 10.0f; // refactored with observer pattern
    // 倒计时相关
    /*DrawNode* countdownLine;
    Label* countdownLabel;
    float remainingTime;*/ // refactored with Observer pattern
public:
    
    float elapsedTime = 0.0f;
    Label* fadingText;
    void  update(); // refactored with composite pattern
    void draw();  // refactored with composite pattern

    void addObserver(IObserver* observer) override;

    void removeObserver(IObserver* observer) override;

    void notifyObservers(EventType event,Vec2 position) override;

    //打印提示
    void createText(const std::string& textContent);
    void updateText(float dt);

    // 创建场景的静态方法
    static cocos2d::Scene* createScene();

    // 初始化场景的方法
    virtual bool init();
    virtual 
    //回退按钮
    void initBack();

    void initPlayer();

    //添加背景图片
    void initBackground();

    // 创建棋格
    void initGridMap();

    //创建备战席
    void initPreparationSeats();

    //创建小小英雄
    void initLittleHero();

    //创建棋子样例
    void initChessExp();

    //创建商店
    void initStore();

    //创建时间进度条
    void initPrepareLabel();

    void putChessOnGrids();

    void putChessOnSeats();

    //以下是监听鼠标信息的函数
    //启用鼠标监听器
    void enableMouseListener();

    //禁用鼠标监听器
    void disableMouseListener();

    //此部分为准备场景下的专用函数
    //鼠标监听函数
    void prepareSceneOnMouseDown(Event* event);
    void prepareSceneOnMouseMove(Event* event);
    void prepareSceneOnMouseUp(Event* event);

    //对拖拽chess类的prepareScene监听函数拆分
    void chessOnMouseDown(Vec2 mousePosition);
    void chessOnMouseMove(Vec2 mousePosition);
    void chessOnMouseUp(Vec2 mousePosition);

    //检查三合一并合成
    void checkAndMerge(Chess* chess);
    Chess* upgradeChess(int Id, int star);

    //进入战斗场景
    void goToFightScene(float dt);
    CREATE_FUNC(PrepareScene);

    //回到上个界面
    void menuPlayCallback(Ref* pSender);
    
    //倒计时
    void updateCountdownLabel(float dt);

};

#endif // __PREPARE_SCENE_H__
