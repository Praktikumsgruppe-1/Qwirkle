#ifndef TURN_CONVERT_H
#define TURN_CONVERT_H
#include "turn.h"

class turn_convert
{
public:
    turn_convert();
    static void toJSON(Turn );
    static void fromJSON (Turn );

    friend class Turn;
};

#endif // TURN_CONVERT_H
