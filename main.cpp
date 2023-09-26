#include <bits/stdc++.h>
using namespace std;
fstream fileIn, fileOut;

bool cmp(pair<long long, char> &pairA, pair<long long, char> &pairB){
	return pairA.first >= pairB.first;
}

string function01(string line){
	string ans;
	for(int e = 0 ; e < (int)line.size(); e++){
		/* si es -157 => viene un caracter especial*/
		if( line[e]-'`' == -157){
			e++;
			/* Si es -175 => es ñ */
			if(line[e]-'`' == -175) ans += "n";
			/* Si es -191 => es á */
			else if(line[e]-'`' == -191) ans += "á";
			/* Si es -183 => es é */
			else if(line[e]-'`' == -183) ans += "é";
			/* Si es -179 => es í */
			else if(line[e]-'`' == -179) ans += "í";
			/* Si es -173 => es ó */
			else if(line[e]-'`' == -173) ans += "ó";
			/* Si es -166 => es ú */
			else if(line[e]-'`' == -166) ans += "ú";
			/* Si es -223 => es Á */
			else if(line[e]-'`' == -223) ans += "Á";
			/* Si es -215 => es É */
			else if(line[e]-'`' == -215) ans += "É";
			/* Si es -211 => es Í */
			else if(line[e]-'`' == -211) ans += "Í";
			/* Si es -205 => es Ó */
			else if(line[e]-'`' == -205) ans += "Ó";
			/* Si es -198 => es Ú  */
			else if(line[e]-'`' == -198) ans += "Ú";
		}else{
			/* Cualquier otro caracter que no sea especial*/
			if(line[e] == 'j') ans += "i";
			else if(line[e] == 'h') ans+= "i";
			else if(line[e] == 'k') ans+= "l";
			else if(line[e] == 'u') ans+= "v";
			else if(line[e] == 'w') ans+= "v";
			else if(line[e] == 'y') ans+= "z";
			else{
				ans += line[e];
			}
		}
	}
	return ans;
}
string function02(string line){
	string ans;
	for(int e = 0 ; e < (int)line.size(); e++){
		/* si es -157 => viene un caracter especial*/
		if( line[e]-'`' == -157){
			e++;
			/* Si es -191 => es á */
			if(line[e]-'`' == -191) ans += "a";
			/* Si es -183 => es é */
			else if(line[e]-'`' == -183) ans += "e";
			/* Si es -179 => es í */
			else if(line[e]-'`' == -179) ans += "i";
			/* Si es -173 => es ó */
			else if(line[e]-'`' == -173) ans += "o";
			/* Si es -166 => es ú */
			else if(line[e]-'`' == -166) ans += "u";
			/* Si es -223 => es Á */
			else if(line[e]-'`' == -223) ans += "A";
			/* Si es -215 => es É */
			else if(line[e]-'`' == -215) ans += "E";
			/* Si es -211 => es Í */
			else if(line[e]-'`' == -211) ans += "I";
			/* Si es -205 => es Ó */
			else if(line[e]-'`' == -205) ans += "O";
			/* Si es -198 => es Ú  */
			else if(line[e]-'`' == -198) ans += "U";
		}else{
			/* Cualquier otro caracter */
			ans += line[e];
		}
	}
	return ans;
}

void function03(string &line){
	for(int e = 0 ; e < (int)line.size(); e++){
		if( (line[e] >= 65 && line[e] <= 90 ) || (line[e] >=97 && line[e] <=122) ){
			line[e] = toupper(line[e]);
		}
	}
}

string function04(string line){
	string ans;
	for(int e =0  ;e < (int)line.size() ; e++){
		if(line[e] == ' '){;}
		else{
			if(line[e]-'`' == -158){
				e++;
				if(line[e]-'`' == -191){;}
			}
			//para detectar el caracter  '¡'
			else if(line[e] == ',' || line[e] == '.'  ||
			 line[e] == '!' || line[e] == ';' || line[e] == '?' ||
			 line[e] == ','){;}
			else{
				ans += line[e];
			}
		}
	}
	return ans;
}

string function07(string line){
	std::stringstream ss;
	for(int e = 0 ; e < (int)line.size(); e++){
		if(line[e] != ' '){
			ss << std::hex << line[e]-0;
		}
	}
	return ss.str();
}

void preProcesamiento01(){
	fileIn.open("message.txt", ios::in);
	fileOut.open("salida01.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		fileOut << function01(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}

void preProcesamiento02(){
	fileIn.open("salida01.txt", ios::in);
	fileOut.open("salida02.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		fileOut << function02(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}

void preProcesamiento03(){
	fileIn.open("salida02.txt", ios::in);
	fileOut.open("salida03.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		function03(line);
		fileOut << line << endl;
	}
	fileIn.close();
	fileOut.close();
}

void preProcesamiento04(){
	fileIn.open("salida03.txt", ios::in);
	fileOut.open("HERALDOSNEGROS_pre.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		fileOut << function04(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}

void preProcesamiento05(){
	fileIn.open("HERALDOSNEGROS_pre.txt", ios::in);
	string line;
	map<char, long long> frecuencias;
	while(getline(fileIn,line)){
		for(int e = 0 ;e < (int)line.size() ; e++){
			frecuencias[line[e]]++;
		}
	}
	fileIn.close();
	//print frecuencias
	vector<pair<long long,char>> view_frecuencias;
	for(auto it = frecuencias.begin(); it != frecuencias.end() ; it++){
		view_frecuencias.push_back(make_pair(it->second, it->first));
		//cout << it->first << " : " << it->second << endl;
	}
	sort(view_frecuencias.begin(), view_frecuencias.end(), cmp);
	for(int e = 0 ; e < 5; e++){
		cout << view_frecuencias[e].first << " " << view_frecuencias[e].second << endl;
	}
}

void preProcesamiento07(){
	fileIn.open("HERALDOSNEGROS_pre.txt", ios::in);
	//fileIn.open("test.txt", ios::in);
	fileOut.open("HERALDOSNEGROS_unicode8.txt", ios::out);
	string line;
	fileOut << "0x";
	while(getline(fileIn,line)){
		fileOut << function07(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*
		1. Realizar las siguientes sustituciones: jxi, hxi,ñxn, kxl, uxv, wxv, yxz
	*/
	preProcesamiento01(); 

	/*
		2.- Eliminar tildes
	*/
	preProcesamiento02();

	/*
		3.- Convierta todas las letras a Mayusculas
	*/
	preProcesamiento03();

	/*
		4.- Elimine los espacios en blanco y los signos de puntuacion
	*/
	preProcesamiento04();

	/*
		5.- Calcule una tabla de frecuencias del archivo HERALDOSNEGROS_pre.txt
	*/
	preProcesamiento05();

	/*
		6.- procesar  HERALDOSNEGROS_pre.txt cambiando cada caracter a unicode-8
	*/
	preProcesamiento07();

	return 0;
}