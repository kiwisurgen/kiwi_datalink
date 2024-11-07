// File: datalink.cpp
#include "utilities/SystemClock.h"
#include "utilities/Position.h"
#include "utilities/Plane.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cmath>

std::string formatTime(const SystemClock::TimePoint& timePoint) {
    auto timeT = SystemClock::Clock::to_time_t(timePoint);
    std::string timeStr = std::ctime(&timeT);
    timeStr.pop_back();
    return timeStr;
}

sf::Font loadSystemFont() {
    sf::Font font;
    
    #ifdef _WIN32
    if (!font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf")) {
        std::cerr << "Could not load Arial font on Windows.\n";
    }
    #elif __APPLE__
    if (!font.loadFromFile("/System/Library/Fonts/SFNS.ttf")) {
        std::cerr << "Could not load SFNS font on macOS.\n";
    }
    #else
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Could not load DejaVuSans font on Linux.\n";
    }
    #endif
    
    return font;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Datalink Simulation");
    window.setVerticalSyncEnabled(true);

    sf::Font font = loadSystemFont();
    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(18);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(10, 10);

    sf::Text positionText;
    positionText.setFont(font);
    positionText.setCharacterSize(18);
    positionText.setFillColor(sf::Color::White);
    positionText.setPosition(10, 60);

    float radius = 125.0f;
    float centerX = 250.0f;
    float centerY = 250.0f;
    float speed = 1.0f;
    float angle = 0.0f;

    Airplane plane;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        SystemClock::TimePoint currentTime = SystemClock::now();
        timeText.setString("Current time:\n" + formatTime(currentTime));

        angle += speed * 0.016f;
        if (angle > 2 * M_PI) angle -= 2 * M_PI;

        float x = centerX + radius * std::cos(angle);
        float y = centerY + radius * std::sin(angle);
        plane.setPosition(x, y, 0.0f);

        float rotationAngle = std::atan2(y - centerY, x - centerX) * 180 / M_PI;

        plane.setAngle(rotationAngle+180);

        positionText.setString("Latitude: " + std::to_string(plane.getLatitude()) +
                               "\nLongitude: " + std::to_string(plane.getLongitude()));

        window.clear(sf::Color::Black);
        window.draw(timeText);
        window.draw(positionText);
        window.draw(plane.sprite);
        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
