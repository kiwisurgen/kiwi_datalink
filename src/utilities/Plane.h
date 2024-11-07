// File: Plane.h

#include <SFML/Graphics.hpp>
#include "Position.h"
#include <iostream>

#pragma once

class Airplane {
    public:
        Airplane(float latitude = 50.0f, float longitude = 50.0f, float altitude = 50.0f) : position(latitude, longitude, altitude) {
            if (!texture.loadFromFile("resources/airplane.png")) {
                std::cerr << "Could not load plane sprite.\n";
                exit(0);
            }
            sprite.setTexture(texture);
            sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

            sprite.setTexture(texture);
            sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

            float spriteWidth = 50.0f;
            float spriteHeight = 50.0f;

            sprite.setScale(
                spriteWidth / texture.getSize().x,
                spriteHeight / texture.getSize().y
            );
        }

        void setPosition(float x, float y, float z) {
            position.latitude = x;
            position.longitude = y;
            position.altitude = z;
            setSpritePosition();
        }

        void setAngle(float angle) {
            sprite.setRotation(angle);
        }

        float getLatitude() {
            return position.latitude;
        }

        float getLongitude() {
            return position.longitude;
        }

        float getAltitude() {
            return position.altitude;
        }

        sf::Sprite sprite;
        sf::Texture texture;
        Position position;
    
    private:
        void setSpritePosition() {
            sprite.setPosition(position.latitude, position.longitude);
        }
};
