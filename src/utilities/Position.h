// File: Position.h

#pragma once

class Position {
    public:
        Position(float latitude, float longitude, float altitude) {
            this->latitude = latitude;
            this->longitude = longitude;
            this->altitude = altitude;
        }

        float latitude;
        float longitude;
        float altitude;
};
