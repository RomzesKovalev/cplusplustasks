#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(500, 500), "graph_exe");
    RectangleShape cell(Vector2f(50, 50));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cell.setPosition(i * 50, j * 50);
            if ((i + j) % 2 == 1) {
                cell.setFillColor(Color::Green);
            }
            else {
                cell.setFillColor(Color::White);
            }
            window.draw(cell);
        }
    }
    window.display();

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}