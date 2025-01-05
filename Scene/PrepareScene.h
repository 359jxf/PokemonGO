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
    // ����ʱ���
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

    //��ӡ��ʾ
    void createText(const std::string& textContent);
    void updateText(float dt);

    // ���������ľ�̬����
    static cocos2d::Scene* createScene();

    // ��ʼ�������ķ���
    virtual bool init();
    virtual 
    //���˰�ť
    void initBack();

    void initPlayer();

    //��ӱ���ͼƬ
    void initBackground();

    // �������
    void initGridMap();

    //������սϯ
    void initPreparationSeats();

    //����ССӢ��
    void initLittleHero();

    //������������
    void initChessExp();

    //�����̵�
    void initStore();

    //����ʱ�������
    void initPrepareLabel();

    void putChessOnGrids();

    void putChessOnSeats();

    //�����Ǽ��������Ϣ�ĺ���
    //������������
    void enableMouseListener();

    //������������
    void disableMouseListener();

    //�˲���Ϊ׼�������µ�ר�ú���
    //����������
    void prepareSceneOnMouseDown(Event* event);
    void prepareSceneOnMouseMove(Event* event);
    void prepareSceneOnMouseUp(Event* event);

    //����קchess���prepareScene�����������
    void chessOnMouseDown(Vec2 mousePosition);
    void chessOnMouseMove(Vec2 mousePosition);
    void chessOnMouseUp(Vec2 mousePosition);

    //�������һ���ϳ�
    void checkAndMerge(Chess* chess);
    Chess* upgradeChess(int Id, int star);

    //����ս������
    void goToFightScene(float dt);
    CREATE_FUNC(PrepareScene);

    //�ص��ϸ�����
    void menuPlayCallback(Ref* pSender);
    
    //����ʱ
    void updateCountdownLabel(float dt);

};

#endif // __PREPARE_SCENE_H__
