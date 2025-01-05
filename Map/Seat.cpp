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
        // �����쳣ʱ�Ĵ����߼�
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

        preSeats->removeChessOfSeat(seat); // �ӱ�սϯ�Ƴ�
        myPlayer->removeChess(selectedChess);
    }
}

void Seat::handelMouseMove(Vec2 position) {
    if (selectedChess && selectedChess->isDragging) {
        // �������Ƿ��ƶ�����һ����Ч�ı�սϯ
        Seat* seat = preSeats->mouseInWhichSeat(mousePosition);
        if (seat && !seat->chessInSeat) {
            // ������ʾ����λ
            seat->highlight(); // ������ʾ�Ĳ���
        }

        // ��������λ��
        selectedChess->setPosition(position);
    }
}

void Seat::handleMouseUp(Vec2 position) {
    if (selectedChess && selectedChess->isDragging) {
        selectedChess->isDragging = false;

        // ������ſ�ʱ�Ƿ��ڱ�սϯ��
        Seat* seat = preSeats->mouseInWhichSeat(mousePosition);
        if (seat && !seat->chessInSeat) {
            // �������ӵ���λ
            preSeats->addChessToSeat(selectedChess, seat);
            myPlayer->addChess(selectedChess);
            CCLOG("Chess placed on seat.");
        }
        else {
            // �����Чλ�ã����ӻص�ԭλ
            selectedChess->setPosition(selectedChess->originalPosition);
        }
    }
}