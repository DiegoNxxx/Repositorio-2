#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

void drawMenu(sf::RenderWindow &window) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error cargando la fuente" << std::endl;
        return;
    }

    sf::Text title("Menu de Opciones", font, 30);
    title.setFillColor(sf::Color::Black);
    title.setPosition(100, 50);
    window.draw(title);

    std::vector<std::string> options = {
        "1. Ingresar datos",
        "2. Ordenar usando BubbleSort",
        "3. Buscar elemento usando BinarySearch",
        "4. Salir"
    };

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text optionText(options[i], font, 24);
        optionText.setFillColor(sf::Color::Blue);
        optionText.setPosition(100, 100 + i * 40);
        window.draw(optionText);
    }

    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Menu en Ventana Nueva");
    int opcion;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    std::cout << "Seleccionaste la opcion 1: Ingresar datos" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    std::cout << "Seleccionaste la opcion 2: Ordenar usando BubbleSort" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Num3) {
                    std::cout << "Seleccionaste la opcion 3: Buscar elemento usando BinarySearch" << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Num4) {
                    std::cout << "Saliendo del programa." << std::endl;
                    window.close();
                }
            }
        }

        drawMenu(window);
    }

    return 0;
}
