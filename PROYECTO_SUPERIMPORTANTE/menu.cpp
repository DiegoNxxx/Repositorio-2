#include "Menu.h"
#include <iostream>
#include <vector>

void drawMenu(sf::RenderWindow &window, const std::string& inputText) {
    window.clear(sf::Color::White);

    // Usar la fuente predeterminada proporcionada por SFML (sansation)
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Diego/Documents/SFML-2.6.2/fonts/Arimo-VariableFont_wght.ttf")) {
        std::cerr << "Error cargando la fuente predeterminada" << std::endl;
        return;
    }

    // Título centrado
    sf::Text title("Menu de Opciones", font, 30);
    title.setFillColor(sf::Color::Black);

    // Centrar el título horizontalmente
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition((window.getSize().x - titleBounds.width) / 2, 50);
    window.draw(title);

    std::vector<std::string> options = {
        "1. Ingresar datos", "2. Binary Search", "3. Bubble Sort", "4. Selection Sort",
        "5. Insertion Sort", "6. Merge Sort", "7. Quick Sort", "8. Linked List",
        "9. Stacks", "10. Queue", "11. AVL", "12. Dijkstra",
        "13. Matrices Adyac.", "14. BFS", "15. DFS", "16. LP y LQ", "17. BST", "20 Salir"
    };

    // Número de opciones por columna
    size_t totalOptions = options.size();
    size_t midPoint = totalOptions / 2; // Dividir las opciones en dos partes

    // Ajustes para las columnas
    float columnX1 = 50; // Posición X de la primera columna
    float columnX2 = window.getSize().x / 2 + 50; // Posición X de la segunda columna
    float optionY = 100; // Posición inicial para las opciones
    float verticalSpacing = 30; // Espaciado entre las opciones

    // Dibujar las opciones en dos columnas
    for (size_t i = 0; i < midPoint; ++i) {
        sf::Text optionText(options[i], font, 15);
        optionText.setFillColor(sf::Color::Blue);

        // Centrar cada opción horizontalmente en la primera columna
        optionText.setPosition(columnX1, optionY);
        window.draw(optionText);
        optionY += verticalSpacing; // Ajustar la posición vertical de la siguiente opción
    }

    optionY = 100; // Reiniciar la posición vertical para la segunda columna
    for (size_t i = midPoint; i < totalOptions; ++i) {
        sf::Text optionText(options[i], font, 15);
        optionText.setFillColor(sf::Color::Blue);

        // Centrar cada opción horizontalmente en la segunda columna
        optionText.setPosition(columnX2, optionY);
        window.draw(optionText);
        optionY += verticalSpacing; // Ajustar la posición vertical de la siguiente opción
    }

    // Dibujar la barra de entrada
    sf::RectangleShape inputBox(sf::Vector2f(300, 40));
    inputBox.setFillColor(sf::Color(240, 240, 240));
    inputBox.setPosition((window.getSize().x - inputBox.getSize().x) / 2, optionY);
    window.draw(inputBox);

    // Mostrar el texto ingresado en la barra
    sf::Text inputTextDisplay(inputText, font, 20);
    inputTextDisplay.setFillColor(sf::Color::Black);
    inputTextDisplay.setPosition(inputBox.getPosition().x + 5, inputBox.getPosition().y + 5);
    window.draw(inputTextDisplay);

    window.display();
}
