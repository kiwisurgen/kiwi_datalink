// File: datalink.cpp
#include "utilities/SystemClock.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

// Function to format TimePoint to a readable string
std::string formatTime(const SystemClock::TimePoint& timePoint) {
    auto timeT = SystemClock::Clock::to_time_t(timePoint);
    std::string timeStr = std::ctime(&timeT);
    timeStr.pop_back();  // Remove trailing newline from ctime
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
    sf::RenderWindow window(sf::VideoMode(370, 100), "Datalink Simulation");
    window.setVerticalSyncEnabled(false);
    sf::Font font = loadSystemFont();
    sf::Text timeText;
    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(10, 20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        SystemClock::TimePoint currentTime = SystemClock::now();
        timeText.setString("Current time:\n" + formatTime(currentTime));
        window.clear(sf::Color::Black);
        window.draw(timeText);
        window.display();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
