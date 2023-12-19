#ifndef SHA1_H
#define SHA1_H

#include<bits/stdc++.h>
#include <openssl/sha.h>
#include <iomanip>
using namespace std;

// Función que calcula el HMAC utilizando SHA-1
std::string calculateSHA1HMAC(const std::string& message) {
    // Clave (clave secreta para el HMAC, en este ejemplo está vacía)
    const std::string key = "";

    // Longitud del bloque para la clave y el bloque del mensaje
    const int blockSize = 64;

    // Valor del relleno externo del bloque para la clave
    const char ipad = 0x36;
    const char opad = 0x5c;

    // Hash de la clave y mensaje
    unsigned char keyHash[SHA_DIGEST_LENGTH];
    unsigned char messageHash[SHA_DIGEST_LENGTH];

    // Preparar la clave para el HMAC
    unsigned char modifiedKey[blockSize];
    std::fill_n(modifiedKey, blockSize, 0);

    if (key.length() > blockSize) {
        // Si la clave es más larga que el bloque, aplicar hash a la clave
        SHA1(reinterpret_cast<const unsigned char*>(key.c_str()), key.length(), keyHash);
        std::copy(std::begin(keyHash), std::end(keyHash), modifiedKey);
    } else {
        // Si la clave es más corta que el bloque, copiar la clave y rellenar el resto con 0
        std::copy(key.begin(), key.end(), modifiedKey);
    }

    // Aplicar XOR con el relleno externo para la clave
    for (int i = 0; i < blockSize; ++i) {
        modifiedKey[i] ^= ipad;
    }

    // Concatenar clave modificada con el mensaje
    std::string concatKeyMessage(reinterpret_cast<char*>(modifiedKey), blockSize);
    concatKeyMessage += message;

    // Calcular hash del resultado anterior
    SHA1(reinterpret_cast<const unsigned char*>(concatKeyMessage.c_str()), concatKeyMessage.length(), messageHash);

    // Aplicar XOR con el relleno externo para el resultado del hash
    for (int i = 0; i < blockSize; ++i) {
        modifiedKey[i] ^= (ipad ^ opad);
    }

    // Concatenar clave modificada con el resultado del hash anterior
    std::string finalHash(reinterpret_cast<char*>(modifiedKey), blockSize);
    finalHash += reinterpret_cast<const char*>(messageHash);

    // Calcular el hash final
    unsigned char finalResult[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char*>(finalHash.c_str()), finalHash.length(), finalResult);

    // Convertir el resultado a una cadena hexadecimal
    std::stringstream ss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(finalResult[i]);
    }

    return ss.str();
}

#endif // !SHA1_H