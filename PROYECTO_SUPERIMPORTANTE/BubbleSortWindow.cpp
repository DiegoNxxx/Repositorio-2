#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include "BinarySearchWindow.h"
#include "BinarySearch.h"

using namespace std;

int binarySearch(vector<int> vec, int target);  // Asegúrate de tener la función binarySearch definida en tu proyecto

void binarySearchWindow() {
    sf::RenderWindow window(sf::VideoMode(500, 300), "Binary Search");
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Diego/Documents/SFML-2.6.2/fonts/Arimo-VariableFont_wght.ttf")) {
        cerr << "Error cargando la fuente" << endl;
        return;
    }

    sf::Text instructionText("Ingresa los elementos del vector (separados por espacio):", font, 18);
    instructionText.setPosition(10, 20);

    sf::Text inputDisplay("", font, 18);
    inputDisplay.setPosition(10, 60);

    string inputText = "";
    bool vectorEntered = false;
    vector<int> vec;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && !inputText.empty()) {  // Backspace
                    inputText.pop_back();
                } else if (event.text.unicode < 128) {
                    inputText += static_cast<char>(event.text.unicode);
                }
            }
     if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                // Captura del vector
                if (!vectorEntered) {
                    istringstream iss(inputText);
                    int num;
                    while (iss >> num) vec.push_back(num);
                    vectorEntered = true;
                    inputText = "";
                    instructionText.setString("Ingresa el valor a buscar:");
                } 
                // Captura del valor objetivo
                else {
                    int target = stoi(inputText);
                    int result = binarySearch(vec, target);
                    string resultMessage = (result != -1) ? "Elemento encontrado en el indice: " + to_string(result)
                                                          : "Elemento no encontrado";
                    instructionText.setString(resultMessage);
                }
            }
        }

        window.clear();
        window.draw(instructionText);
        inputDisplay.setString(inputText);
        window.draw(inputDisplay);
        window.display();
    }
}