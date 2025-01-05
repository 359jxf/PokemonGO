#include "IObserver.h"
class CountdownLabel : public IObserver {
private:
	float remainingTime;
	Label* countdownLabel;
	DrawNode* countdownLine;
	const float PREPARE_TIME = 10.0f;
public:
	CountdownLabel();
	void init();
	void update() override;

};