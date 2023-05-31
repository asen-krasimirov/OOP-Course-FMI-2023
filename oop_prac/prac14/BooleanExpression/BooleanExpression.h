#pragma once

#include "../BooleanInterpretation/BooleanInterpretation.h"

class BooleanExpression {
private:
    bool _variables[VARIABLES_COUNT];
    unsigned _variablesCount;

public:
    virtual BooleanExpression *clone() const = 0;
    virtual ~BooleanExpression() = default;

    virtual bool evaluate(const BooleanInterpretation &interpretation) const = 0;

};
