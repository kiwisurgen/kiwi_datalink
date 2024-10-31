// File: Position.h

#pragma once

class Position {
    public:
        Position(double latitude, double longitude, double altitude) {
            this->latitude = latitude;
            this->longitude = longitude;
            this->altitude = altitude;
        }

        double getLatitude() {
            return latitude;
        }

        double getLongitude(){
            return longitude;
        }

        double getAltitude(){
            return altitude;
        }
    
    private:
        double latitude;
        double longitude;
        double altitude;
};