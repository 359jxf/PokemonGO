//Refactored with Plugin Pattern
// ChessPlugin/ChessPlugin.h
USING_NS_CC;

class ChessPlugin {
    public:
        virtual ~ChessPlugin() = default;
        virtual std::string getName() const = 0; // ��ȡ��������
        virtual int getId() const = 0; // ��ȡ���� ID
        virtual Chess* createChess() const = 0; // ��������
};