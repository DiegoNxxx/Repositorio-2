// Diego Núñez García A016447371
#include <iostream>  
#include "Empleado.hpp"
#include <algorithm> // Para std::sort


int main() {
    std::vector<Empleado> empleados = {
        // ... (tu lista de empleados)
    };

    std::sort(empleados.begin(), empleados.end()); // Asegurar que el vector esté ordenado

    std::string nombre;
    std::cout << "Ingrese el nombre del empleado que desea buscar: ";
    std::getline(std::cin, nombre);

    buscarEmpleado(empleados, nombre);

    return 0;
}
