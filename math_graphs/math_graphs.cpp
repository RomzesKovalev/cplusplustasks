#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath>

void drawGraphX(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float y = xMin; y <= xMax; y += 0.1f) {
        float x = func(y);
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;


        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

void drawGraphY(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;


        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}
int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "prolozhenie");

    sf::CircleShape userPoint(5);
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }



    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);
    xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(750, 300);
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);
    yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 550);
    yAxis[1].color = sf::Color::White;

    std::string zone;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    float mathX = (mousePos.x - 400) / 50.0f;
                    float mathY = -(mousePos.y - 300) / 50.0f;

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    if ((mathX == 0)) {
                        zone = "Granica!";
                    }
                    else if (mathY == (abs(mathX) - 3)) {
                        zone = "Granica!";
                    }
                    else if ((mathX > 0) && (mathY > abs(mathX) - 3)) {
                        zone = "1";
                    }
                    else if ((mathX < 0) && (mathY < abs(mathX) - 3)) {
                        zone = "2";
                    }
                    else if ((mathY > abs(mathX) - 3) && (mathX < 0)) {
                        zone = "3";
                    }
                    else if ((mathY < abs(mathX) - 3) && (mathX > 0)) {
                        zone = "4";
                    }

                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ")\nZone:" + zone);

                }
            }
        }

        window.clear();
        window.draw(xAxis);
        window.draw(yAxis);
        window.draw(coordinatesText);

        drawGraphY(window, [](float x) {return abs(x) - 5; }, -15, 15, 30, 30, sf::Color::Green);
        drawGraphX(window, [](float y) {return 0; }, -15, 15, 30, 30, sf::Color::Blue);


        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}