#pragma once
#ifndef SEAT_H
#define SEAT_H
#include "cocos2d.h"
#include"HexCell.h"
#include"./Chess/Chess.h"
#include"IObserver.h"
#include"EventType.h"
USING_NS_CC;

#define SEATS_NUM 8
#define SEAT_SCALE 0.45
#define STARTX 200
#define STARTY 180


class Seat :public cocos2d::Node,public Component,public IObserver {
public:
	Sprite* seatImage;//存放备战席棋格的图片

	Chess* chessInSeat=nullptr;//棋格上的棋子

	float width;

	int number;//第几个棋格


public:
	Seat(int num)
	static Seat* create();

	void turnToSelected();//选中

	void turnToNormal();
	// refactored with composite pattern
	virtual void init() override;
	virtual void update() override;
	virtual void draw() override;
	virtual SeatComponent();

	// refactored with observer pattern
	virtual void update(EventType* event, Vec2 position);
};

#endif
