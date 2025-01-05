#include <iostream>
#include <string>

// refractored with prototype pattern
class Prototype {
public:
	virtual ~Prototype() {}
	virtual Prototype* clone() const = 0; // ¿ËÂ¡·½·¨
};
