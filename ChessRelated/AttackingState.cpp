// Refactored with State Pattern
#include "AttackingState.h"
#include "Chess.h"
#include "GridMap.h"
#include "IdleState.h"
#include "DeadState.h"
#define ATTACK_MOVE 5

void AttackingState::enterState() {
    //CCLOG("Chess entered Attacking State");
}

void AttackingState::update(GridMap* gridMap) {
    if (!chess->isAnimationPlaying)//ֻ���ڷǲ��Ŷ���ʱ����
    {
        //��������
        this->action(gridMap);
    }
    return;
}

void AttackingState::exitState() {
    //CCLOG("Chess exited Attacking State");
}

void AttackingState::action(GridMap* gridMap) {
    //�Ȼ�ù�������
    Vector<HexCell*>enemyChessAround;
    bool findEnemy = chess->isEnemyInAttackRange(gridMap, enemyChessAround);
    int enemyChess = enemyChessAround.size();//enemyChessAround���ǻ�������еĹ�����Χ�ڵĵз�����
    //��һ��Vector�洢���еĵз������Ǳ��ں���Ⱥ�幥��
    //Ϊ��˵������������
    if (enemyChess == 0)
    {
        chess->changeState(new IdleState(chess));
        return;
    }
    Chess* attackObject = enemyChessAround.at(0)->chessInGrid;

    //��ǰ���ͷż���
    if (chess->enable_skill) {
        chess->useSkill();
    }

    //�ص�������Ŀ������˺�
    auto callback = CallFunc::create([=]() {
        // ������ɺ�Ļص�,��Ŀ��ʵ������˺�
        if (attackObject) {
            attackObject->getHurt(ATK);
            if (attackObject->health <= 0)
                attackObject->changeState(new DeadState(attackObject));
        }
        //����,�ż���ʱ����
        if (!chess->enable_skill)
        {
            chess->currentBlueBar += 5;
            float percentage_blue = 100.0 * chess->currentBlueBar / chess->blueBar;
            if (currentBlueBar > chess->blueBar)
            {
                chess->enable_skill = true;
                percentage_blue = 100.0f;
            }
            bluebar->setPercentage(percentage_blue);
        }

        chess->isAnimationPlaying = false;
        chess->changeState(new IdleState()); // ������״̬
        });
    //�ص�������Ŀ������˺�

    //��ս����
    if (chess->isMelee == 1) {
        //���ŶԹ�������,�����Ƕ�һ��,Զ��Ŀ����Ҫ�޸�
        Vec2 position = attackObject->getPosition() - chess->getPosition();
        position = Vec2(position.x / ATTACK_MOVE, position.y / ATTACK_MOVE);

        float attackDuration = 1.0f / (10 * chess->attackSpeed);
        auto moveBackAction = MoveBy::create(attackDuration, position);
        auto moveBackReverseAction = moveBackAction->reverse();  // �ƻ�ԭʼλ��
        auto sequence1 = Sequence::create(moveBackAction, moveBackReverseAction, callback, nullptr);
        chess->runAction(sequence1);
    }
    //Զ�̹�������������
    else {
        auto bullet = Sprite::create();
        bullet->setTexture("SliderNode_Normal.png");
        chess->getParent()->addChild(bullet);
        bullet->setPosition(chess->getPosition());
        bullet->setScale(0.5);
        bullet->setZOrder(2);
        Vec2 position = attackObject->getPosition() - chess->getPosition();
        float attackDuration = 1.0f / (10 * chess->attackSpeed);
        auto moveBackAction = MoveBy::create(attackDuration, position);
        auto fadeOut = FadeOut::create(0.0001f);
        auto sequence2 = Sequence::create(moveBackAction, fadeOut, callback, nullptr);
        bullet->runAction(sequence2);
    }
    chess->isAnimationPlaying = true;
}