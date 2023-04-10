//Второе решение через второстепенное подключение background осей координат с классом
#include <SFML/Graphics.hpp>

const int W = 900;
const int H = 512;

class Graph {
public:
    Graph() : window(sf::VideoMode(W, H), "Graphics") {
        x0 = W / 2;
        y0 = H / 2;

        point.setRadius(2.f);
        point.setFillColor(sf::Color::Blue);

        o1 = -10;
        o2 = 10;
        c = 200;
        mass = ((o1) * (-1) + o2) * c + 1;
        sc = 30;

        t.loadFromFile("img/1.png");
        pic.setTexture(t);

        anim = 0;
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            if (anim < mass) {
                anim += 10;
            }

            window.clear(sf::Color::White);
            window.draw(pic);

            for (int i = 0; i < anim; i++) {
                float x = o1 + i / c;
                float y = 5*x*x + x + 1;
                float x1 = x0 + x * sc;
                float y1 = y0 - y * sc;

                point.setPosition(x1 - 1, y1 - 1);
                window.draw(point);
            }
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    int x0, y0, o1, o2, sc, anim;
    float c;
    int mass;
    sf::CircleShape point;
    sf::Texture t;
    sf::Sprite pic;
};

int main() {
    Graph graph;
    graph.run();

    return 0;
}