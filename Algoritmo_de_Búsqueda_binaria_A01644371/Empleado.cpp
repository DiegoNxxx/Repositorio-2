#include "Empleado.hpp"
#include <algorithm> // Para std::sort y std::lower_bound

// Función para buscar un empleado por nombre usando búsqueda binaria
void buscarEmpleado(const std::vector<Empleado>& empleados, const std::string& nombre) {
    Empleado key;           // Crear una clave de búsqueda
    key.nombre = nombre;    // Asignar el nombre de la clave al nombre proporcionado por el usuario

    // Realiza la búsqueda binaria en el vector de empleados
    // lower_bound busca la primera posición donde la clave podría estar
    auto it = std::lower_bound(empleados.begin(), empleados.end(), key);

    // Verifica si la clave fue encontrada en el vector
    // it != empleados.end() asegura que no se haya alcanzado el final del vector
    // it->nombre == nombre confirma que el nombre coincide exactamente
    if (it != empleados.end() && it->nombre == nombre) {
        std::cout << "Empleado encontrado:\n";
        std::cout << "Nombre: " << it->nombre << "\n";            // Imprime el nombre del empleado
        std::cout << "Edad: " << it->edad << "\n";                // Imprime la edad del empleado
        std::cout << "Hobbies: " << it->hobbies << "\n";          // Imprime los hobbies del empleado
        std::cout << "Lenguaje: " << it->Lenguaje << "\n";  // Imprime el Lenguaje del empleado
    } else {
        std::cout << "Empleado no encontrado.\n";  // Si el empleado no se encuentra, muestra un mensaje
    }
}