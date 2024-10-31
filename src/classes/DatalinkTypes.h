// File: DatalinkTypes.h

#include "utilities/Position.h"
#include "utilities/SystemClock.h"

#pragma once

class Datalink {
    public:
        enum class RocketState {
            IDLE,
            ARMED,
            LAUNCH,
            DESCENT,
            LANDED
        };

        
};