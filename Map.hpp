#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"

struct Wall {
    float left_upper_x, left_upper_y, right_lower_x, right_lower_y;
    sf::Color color = sf::Color::White;

    Wall(float x1, float y1, float x2, float y2): left_upper_x(x1), left_upper_y(y1), right_lower_x(x2), right_lower_y(y2) {};
    
    void setColor(const sf::Color &new_color);
};

class Map {
    protected:
        std::vector<Wall> walls;
    public:
        Map() = default;

        std::vector<Wall> getWalls();

        void addWall(const Wall &wall);

        void drawWall(sf::RenderWindow &current_window, const Wall &wall);

        void render(sf::RenderWindow &current_window, const RenderMode &render_mode);

        std::vector<segment_t> calculateAllSurfacesCoordinates();
};

#endif