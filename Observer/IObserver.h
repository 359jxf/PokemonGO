class IObserver {
public:
    virtual void update() = 0;  // ��״̬�仯ʱ���ø÷���
    virtual ~IObserver() = default;
};
