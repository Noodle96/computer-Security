#include <bits/stdc++.h>
using namespace std;
fstream fileIn, fileOut;
fstream file;

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

void preProcesamiento02(){
	fileIn.open("includes/msg.txt", ios::in);
	fileOut.open("includes/msg_limpio.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		fileOut << function02(line) << endl;
	}
	fileIn.close();
	fileOut.close();
}


void preProcesamiento03(){
	fileIn.open("includes/msg_limpio.txt", ios::in);
	fileOut.open("includes/msg_final.txt", ios::out);
	string line; 
	while(getline(fileIn,line)){
		function03(line);
		fileOut << line << endl;
	}
	fileIn.close();
	fileOut.close();
}

void printFrecuencias(){
	file.open("includes/msg_final.txt");
	string line;
	map<char, int> map;
	while(getline(file,line)){
		for(int e = 0 ;e < line.size() ; e++){
			map[line[e]]++;
		}
	}
	file.close();
	cout << "print freciencias" << endl;
	for(auto it = map.begin() ;it != map.end() ; it++){
		cout << it->first << " " << it->second <<endl;
	}cout <<endl;
}

int main(){
	/*
		antes de ello eliminamos las tildes
	*/
	preProcesamiento02();

	/*
		3.- Convierta todas las letras a Mayusculas
	*/
	preProcesamiento03();

	/*
		Mostrar las frecuenncias del archivo msg.txt
	*/
	printFrecuencias();
	return 0;
}