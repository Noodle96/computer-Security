#include "md4.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"

int main() {
    std::string message;
    int choice;

    std::cout << "Ingrese el mensaje: ";
    std::getline(std::cin, message);

    // Solicitar al usuario el tipo de HMAC a calcular
    cout << "Elija el tipo de HMAC a calcular:\n";
    cout << "1. MD4 HMAC\n";
    cout << "2. MD5 HMAC\n";
    cout << "3. SHA-1 HMAC\n";
    cout << "4. SHA-256 HMAC\n";
    cout << "Ingrese su eleccion (1-3): ";
    cin >> choice;

    string hmacResult;
    
    // Calcular el HMAC según la elección del usuario
    switch (choice) {
        case 1:
            hmacResult = calculateMD4(message);
            break;
        case 2:
            hmacResult = GetMD5String(message);
            break;
        case 3:
            hmacResult = calculateSHA1HMAC(message);
            break;
        case 4:
            hmacResult = calculateSHA256HMAC(message);
            break;
        default:
            std::cout << "Opción no válida.\n";
            return 1;
    }

    std::cout << "El HMAC calculado es: " << hmacResult << std::endl;

    return 0;
}
