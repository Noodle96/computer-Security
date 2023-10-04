// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;
// int main() {
//     string test = "áéíóúÁÉÍÓÚ" ;
//     string test2 = "¡a";
//     string after;
//     int cont =0 ;
//     for(auto e = 0  ;e < test2.size() ; e++){
//         // if( (test[e]-'`') == -157 ){
//         //     cout << "inside -157" << endl;
//         //     e++;
//         //     if(test[e]-'`' == -175){
//         //         cout << "inside -175" << endl;
//         //         after += "n";
//         //     }
//         // }
//         // else after += test[e];
//         cout << test2[e] - '`' << endl;
//     }
//     // cout << after << endl;
//     return 0;
// }


#include <iostream>
using namespace std;
int main() {
    int decimalNumber = 255; // Replace with your decimal number

    // Use std::hex to set the output to hexadecimal
    std::cout << "Decimal: " << decimalNumber << std::endl;
    std::cout << "Hexadecimal: " << std::hex << decimalNumber << std::endl;
    string ans ;
    for(int e = 65 ; e <=90 ; e++){
        cout << std::hex <<  char(e) << endl;
    }

    return 0;
}