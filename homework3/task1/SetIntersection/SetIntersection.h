#include "../SetBase/SetBase.h"
#include "../UniquePointer/UniquePointer.hpp"

class SetIntersection : public SetBase {
public:
    SetIntersection(const Vector<UniquePointer<SetBase>> &sets);

    void addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetIntersection &setBase);

};
