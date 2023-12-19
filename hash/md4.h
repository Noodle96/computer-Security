#ifndef MD4_H
#define MD4_H
#include<bits/stdc++.h>
using namespace std;
uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return ((x & y) | (~x & z));
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return ((x & y) | (x & z) | (y & z));
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return (x ^ y ^ z);
}

uint32_t leftRotate(uint32_t x, int n) {
    return ((x << n) | (x >> (32 - n)));
}

// Función principal para calcular el hash MD4
std::string calculateMD4(const std::string& input) {
    uint32_t messageLength = input.length() * 8; // Longitud del mensaje en bits
    const uint32_t initial_values[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476}; // Valores iniciales
    
    // Inicialización de variables
    uint32_t A = initial_values[0];
    uint32_t B = initial_values[1];
    uint32_t C = initial_values[2];
    uint32_t D = initial_values[3];
    
    // Padding del mensaje
    // ... (Implementar el padding según el estándar MD4)
    
    // Procesamiento por bloques de 512 bits
    // ... (Implementar el procesamiento por bloques según el estándar MD4)
    
    // Conversión del hash a una cadena hexadecimal
    std::ostringstream result;
    result << std::hex << std::setfill('0') << std::setw(8) << A
           << std::hex << std::setfill('0') << std::setw(8) << B
           << std::hex << std::setfill('0') << std::setw(8) << C
           << std::hex << std::setfill('0') << std::setw(8) << D;
    
    return result.str();
}

#endif // !MD4_H


