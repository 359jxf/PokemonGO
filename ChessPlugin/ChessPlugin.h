//Refactored with Plugin Pattern
// ChessPlugin/ChessPlugin.h
USING_NS_CC;

class ChessPlugin {
    public:
        virtual ~ChessPlugin() = default;
        virtual std::string getName() const = 0; // 获取棋子名称
        virtual int getId() const = 0; // 获取棋子 ID
        virtual Chess* createChess() const = 0; // 创建棋子
};