import os 
abc = 'abcdefghijklmnñopqrstuvwxyzáéíóú '
def cifrar(cadena, clave):
	cadena_cifrar = ''
	i = 0
	for letra in cadena:
		suma = abc.find(letra) + abc.find(clave[i % len(clave)])
		modulo = int(suma) % len(abc)
		cadena_cifrar = cadena_cifrar + str(abc[modulo])
		i+=1
	texto_cifrado = "includes/texto_cifrado.txt"
	archivo = open(texto_cifrado,'w+')
	archivo.write(cadena_cifrar)
	return "Se ha encriptado su texto en la siguiente ruta: /includes/texto_cifrado.txt"
def descifrar (cadena,clave):
	cadena_cifrar = ''
	i = 0
	for letra in cadena:
		suma = abc.find(letra) - abc.find(clave[i % len(clave)])
		modulo = int(suma) % len(abc)
		cadena_cifrar = cadena_cifrar + str(abc[modulo])
		i+=1
	# os.remove('includes/texto_cifrado.txt')
	texto_descifrado = "includes/texto_descifrado.txt"
	archivo = open(texto_descifrado,'w+')
	archivo.write(cadena_cifrar)
	return "Se ha descencriptado su texto en la siguiente ruta: /includes/texto_decifrado.txt"

def main():
	while  True:
		print ("|--------------|")
		print ("|  1 Cifrar    |")
		print ("|  2 Descifrar |")
		print ("|  3 Salir     |")
		print ("|--------------|")
		opt = int(input("Ingrese opcion: "))
		if (opt == 1):
			# cadena = input('Texto a cifrar: ').lower()
			#fcadena = cadena.replace(' ','')
			print("se cifrara el texto que esta en msg.txt")
			msg = "includes/msg.txt"
			archivo = open(msg,'r+')
			cadena = archivo.read()
			# print(cadena)
			clave = input ('Clave: ').lower()
			print (cifrar(cadena.lower(),clave))
		if (opt == 2):
			# cadena = input('Texto a Descifrar: ').lower()
			print("se descifrara el texto que esta en texto_cifrado.txt")
			msg = "includes/texto_cifrado.txt"
			archivo = open(msg,'r+')
			cadena = archivo.read()
			#fcadena = cadena.replace(' ','')
			clave = input ('Clave: ').lower()
			print (descifrar(cadena,clave))
		if (opt == 3):
			break
	
if __name__ == '__main__':
	main()