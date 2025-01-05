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
    if (!chess->isAnimationPlaying)//只有在非播放动画时调用
    {
        //攻击动作
        this->action(gridMap);
    }
    return;
}

void AttackingState::exitState() {
    //CCLOG("Chess exited Attacking State");
}

void AttackingState::action(GridMap* gridMap) {
    //先获得攻击对象
    Vector<HexCell*>enemyChessAround;
    bool findEnemy = chess->isEnemyInAttackRange(gridMap, enemyChessAround);
    int enemyChess = enemyChessAround.size();//enemyChessAround这是获得了所有的攻击范围内的敌方棋子
    //用一个Vector存储所有的敌方棋子是便于后续群体攻击
    //为空说明对面死完了
    if (enemyChess == 0)
    {
        chess->changeState(new IdleState(chess));
        return;
    }
    Chess* attackObject = enemyChessAround.at(0)->chessInGrid;

    //当前能释放技能
    if (chess->enable_skill) {
        chess->useSkill();
    }

    //回调函数对目标产生伤害
    auto callback = CallFunc::create([=]() {
        // 动画完成后的回调,对目标实际造成伤害
        if (attackObject) {
            attackObject->getHurt(ATK);
            if (attackObject->health <= 0)
                attackObject->changeState(new DeadState(attackObject));
        }
        //蓝条,放技能时不变
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
        chess->changeState(new IdleState()); // 或其他状态
        });
    //回调函数对目标产生伤害

    //近战攻击
    if (chess->isMelee == 1) {
        //播放对攻击对象,设想是顶一下,远程目标需要修改
        Vec2 position = attackObject->getPosition() - chess->getPosition();
        position = Vec2(position.x / ATTACK_MOVE, position.y / ATTACK_MOVE);

        float attackDuration = 1.0f / (10 * chess->attackSpeed);
        auto moveBackAction = MoveBy::create(attackDuration, position);
        auto moveBackReverseAction = moveBackAction->reverse();  // 移回原始位置
        auto sequence1 = Sequence::create(moveBackAction, moveBackReverseAction, callback, nullptr);
        chess->runAction(sequence1);
    }
    //远程攻击，发射星星
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