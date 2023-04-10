#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;

const int W = 600;
const int H = 1200;

class Graph {
private:
    RenderWindow window;
    CircleShape point;
    RectangleShape OsX;
    RectangleShape OsY;
    RectangleShape line[80];
    RectangleShape arrow[4];
    int x0;
    int y0;
    float c;
    int sc;
    int o1;
    int o2;
    int anim;


public:
    Graph() : 
    window(VideoMode(W, H), "Graphics"), 
    x0(W/2), 
    y0(H/2), 
    c(200), 
    sc(30), 
    o1(-10), 
    o2(10), 
    anim(0) 
    {
        point.setFillColor(Color::White);
        point.setRadius(2.f);

        OsX.setFillColor(Color::Blue);
        OsX.setSize(Vector2f(W, 1));
        OsX.setPosition(0, y0);

        OsY.setFillColor(Color::Blue);
        OsY.setSize(Vector2f(1, H));
        OsY.setPosition(x0, 0);

        for (int i = 0; i < 80; i++) {
            line[i].setSize(Vector2f(1, 10));
            line[i].setFillColor(Color::White);
            if (i < 40) {
                if (i < 20)
                    line[i].setPosition(x0 - (i + 1) * sc, y0 - 5);
                else
                    line[i].setPosition(x0 + (i - 20) * sc, y0 - 5);
            }
            else {
                line[i].setRotation(90);
                if (i < 60)
                    line[i].setPosition(x0 + 5, y0 + (i - 60) * sc);
                else
                    line[i].setPosition(x0 + 5, y0 + (i - 59) * sc);
            }
        }

        for (int i = 0; i < 4; i++) {
            arrow[i].setSize(Vector2f(1, 20));
            arrow[i].setFillColor(Color::White);
            if (i < 2)
                arrow[i].setPosition(x0, 0);
            else
                arrow[i].setPosition(W, y0);
        }

        arrow[0].setRotation(20);
        arrow[1].setRotation(-20);
        arrow[2].setRotation(70);
        arrow[3].setRotation(-250);
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (anim < ((o1 * -1) + o2) * c + 1)
                anim += 5;

            window.clear(Color::Black);
            window.draw(OsX);
            window.draw(OsY);
            for (int i = 0; i < 4; i++)
                window.draw(arrow[i]);
            for (int i = 0; i < 80; i++)
                window.draw(line[i]);
            for (int i = 0; i < anim; i++) {
                float x = o1 + i / c;
                
                
                float y = 5*x*x + x + 1;


                float x1 = x0 + x * sc;
                float y1 = y0 - y * sc;
                point.setPosition(x1, y1);
                window.draw(point);
            }
            window.display();
        }
    }


};

int main() {
    Graph graph;
    graph.run();
    return 0;
}