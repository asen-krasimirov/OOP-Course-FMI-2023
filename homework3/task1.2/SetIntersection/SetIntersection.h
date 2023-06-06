#include "../SetBase/SetBase.h"
#include "../SharedPointer/SharedPointer.hpp"

class SetIntersection : public SetBase {
public:
    explicit SetIntersection(const Vector<SharedPointer<SetBase>> &sets);

    bool addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetIntersection &setBase);

};
