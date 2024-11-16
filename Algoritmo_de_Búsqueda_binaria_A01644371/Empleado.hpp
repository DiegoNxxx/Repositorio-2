#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <iostream>
#include <string>
#include <vector>

struct Empleado {
    std::string nombre;
    int edad;
    std::string hobbies;
    std::string Lenguaje;

    // Operador menor para poder usar std::sort y std::binary_search
    bool operator<(const Empleado& other) const {
        return nombre < other.nombre;
    }
};

// Declaración de la función para buscar empleado
void buscarEmpleado(const std::vector<Empleado>& empleados, const std::string& nombre);

#endif 