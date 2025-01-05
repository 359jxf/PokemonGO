#include <Seat.h>
USING_NS_CC;


Seat* Seat::create()
{
    try {
        Seat* seat = new Seat();
        if (seat && seat->init()) {
            seat->autorelease();
            return seat;
        }
        CC_SAFE_DELETE(seat);
    }
    catch (const std::exception& e) {
        // 捕获到异常时的处理逻辑
        CCLOG("Exception caught: %s", e.what());
    }
}

bool Seat::init()
{
    if (!Node::init()) {
        throw std::runtime_error("Seat initialization failed: Node initialization failed");
    }

    seatImage = Sprite::create("seatImage.png");
    seatImage->setScale(SEAT_SCALE);
    this->addChild(seatImage);

    this->turnToNormal();
    width = seatImage->getContentSize().width * SEAT_SCALE;
    return true;
}

void Seat::update()
{
}

void Seat::draw()
{
}

Seat::SeatComponent()
{
}

void Seat::turnToSelected()
{
    if (this == nullptr)
        return;
    seatImage->setOpacity(150);
}

void Seat::turnToNormal()
{
    if (this == nullptr)
        return;
    if (!this->chessInSeat)
        if (seatImage)
            seatImage->setOpacity(80);
}
// refactored with observer pattern
void Seat::update(EventType* event, Vec2 position) {
    switch (event) {
    case EventType::MouseDown:
        this->handleMouseDown(position);
        break;
    case EventType::MouseMove:
        handleMouseMove(position)
            break;
    case EventType::MouseUp:
        handleMouseUp(position);
        break;
    default:
        break;
    }
}

void Seat::handelMouseDown(Vec2 position) {
    Seat* seat = preSeats->mouseInWhichSeat(position);
    if (seat && seat->chessInSeat) {
        selectedChess = seat->chessInSeat;
        selectedChess->isDragging = true;

        preSeats->removeChessOfSeat(seat); // 从备战席移除
        myPlayer->removeChess(selectedChess);
    }
}

void Seat::handelMouseMove(Vec2 position) {
    if (selectedChess && selectedChess->isDragging) {
        // 检查鼠标是否移动到了一个有效的备战席
        Seat* seat = preSeats->mouseInWhichSeat(mousePosition);
        if (seat && !seat->chessInSeat) {
            // 高亮显示该座位
            seat->highlight(); // 高亮显示的操作
        }

        // 更新棋子位置
        selectedChess->setPosition(position);
    }
}

void Seat::handleMouseUp(Vec2 position) {
    if (selectedChess && selectedChess->isDragging) {
        selectedChess->isDragging = false;

        // 检查鼠标放开时是否在备战席上
        Seat* seat = preSeats->mouseInWhichSeat(mousePosition);
        if (seat && !seat->chessInSeat) {
            // 放置棋子到座位
            preSeats->addChessToSeat(selectedChess, seat);
            myPlayer->addChess(selectedChess);
            CCLOG("Chess placed on seat.");
        }
        else {
            // 如果无效位置，棋子回到原位
            selectedChess->setPosition(selectedChess->originalPosition);
        }
    }
}