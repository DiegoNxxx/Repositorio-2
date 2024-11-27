#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "BinarySearch.h"
#include "BinarySearchWindow.h"
using namespace std;

// Declaracion de funciones
int binarySearch(vector<int> vec, int target);


int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Menu con Barra de Entrada");
    std::string inputText = "";  // Variable para almacenar el texto ingresado



        // no importa xd
    sf::RectangleShape enterButton(sf::Vector2f(100, 40));
    enterButton.setFillColor(sf::Color(0, 255, 0));  // Verde brillante para el botón
    enterButton.setPosition((window.getSize().x - enterButton.getSize().x) / 2, 320);

    // Fuente para el texto del botón
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Diego/Documents/SFML-2.6.2/fonts/Arimo-VariableFont_wght.ttf")) {
        std::cerr << "Error cargando la fuente" << std::endl;
        return -1;
    }
    sf::Text buttonText("Enter", font, 20);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(
        enterButton.getPosition().x + (enterButton.getSize().x - buttonText.getLocalBounds().width) / 2,
        enterButton.getPosition().y + (enterButton.getSize().y - buttonText.getLocalBounds().height) / 2
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Manejar la escritura en la barra de texto
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && !inputText.empty()) { // Backspace
                    inputText.pop_back();
                }
                else if (event.text.unicode < 128) {  // Caracteres alfabéticos
                    inputText += static_cast<char>(event.text.unicode);
                }
            }

            // Ejecutar la opción cuando se presiona "Enter"
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Return) {
                    if (inputText == "1") {
                        std::cout << "Seleccionaste la opcion 1: Ingresar datos" << std::endl;
                    }
                else if (inputText == "2") {
                std::cout << "Seleccionaste la opcion 2: BinarySearch" << std::endl;
                    binarySearchWindow();  // Llamada a la función en la nueva ventana
                inputText.clear();  
         }
                    else if (inputText == "3") {
                        std::cout << "Seleccionaste la opcion 3: Bubble Sort" << std::endl;
                    }
                    else if (inputText == "4") {
                        std::cout << "Seleccionaste la opcion 4: Selection Sort " << std::endl;
                    }
                    else if (inputText == "5") {
                        std::cout << "Seleccionaste la opcion 5: Insertion Sort" << std::endl;
                    }
                        else if (inputText == "6") {
                        std::cout << "Seleccionaste la opcion 6: Merge Sort" << std::endl;
                    }  
                      else if (inputText == "7") {
                        std::cout << "Seleccionaste la opcion 7: Quick Sort" << std::endl;
                    }    
                        else if (inputText == "8") {
                        std::cout << "Seleccionaste la opcion 8: Linked List" << std::endl;
                    } 
                    else if (inputText == "9") {
                        std::cout << "Seleccionaste la opcion 9: Stacks" << std::endl;
                    }      
                    else if (inputText == "10") {
                        std::cout << "Seleccionaste la opcion 10: Queue" << std::endl;
                    } 
                    else if (inputText == "11") {
                        std::cout << "Seleccionaste la opcion 11: AVL" << std::endl;
                    }          
                    else if (inputText == "12") {
                        std::cout << "Seleccionaste la opcion 12: Dijkstra" << std::endl;
                    }             
                    else if (inputText == "13") {
                        std::cout << "Seleccionaste la opcion 13: Matrices Adyac." << std::endl;
                    }
                    else if (inputText == "14") {
                        std::cout << "Seleccionaste la opcion 14: BFS" << std::endl;
                    }                    
                    else if (inputText == "15") {
                        std::cout << "Seleccionaste la opcion 15: DFS" << std::endl;
                    }                    
                    else if (inputText == "16") {
                        std::cout << "Seleccionaste la opcion 16: LP" << std::endl;
                    }                    
                    else if (inputText == "17") {
                        std::cout << "Seleccionaste la opcion 17: LQ" << std::endl;
                    }                    
                    else if (inputText == "18") {
                        std::cout << "Seleccionaste la opcion 18: BST" << std::endl;
                    }                                 
                    else if (inputText == "19") {
                        std::cout << "Saliendo del programa." << std::endl;
                        window.close();
                    } else {
                        std::cout << "Opción no válida. Por favor, escribe un número entre 1 y 4." << std::endl;
                    }
                    inputText.clear();  // Limpiar la barra de entrada después de ejecutar la opción
                }
            }
        }

        drawMenu(window, inputText);  // Dibujar el menú con la barra de entrada
    }

    return 0;
}
