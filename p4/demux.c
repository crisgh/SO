
/*
 *  leemos de la entrada estandar y lo repartimos en archivos
 * tamaño de bloque : primer parametro
 * 
 * cat fich | demux 500(n bytes) A B C D
 * lee de la entrada estandar los primeros 500 bytes van a A, los segundos 500 bytes a B ... 
 * y una vez que llegue al D, los siguientes 500 otra vez al A
 * los ficheros A,B,C, D tienen que ser ficheros comprimidos (gzip)
 * el ultimo bloque alomejor no llega a los 500, hasta que terminen los datos de la entrada.
 * 
 * no se pueden usar ficheros temporales
 * entrada estandar --> gzip(filtro) --> salida estandar
 * 
 * 
 * 1 - leer bien del fichero...mejor rellenar un buffer 
 * read : no me garantiza que me vaya a leer todo -- tenemos que leer todos los datos(n bytes)
 * mejor empezar con bloques pequeños que me garantice que leo bien.
 * 
 * 
 * 2- probamos .. me creo un fichero con 500 Aes..con 500 Bs..y asi como tamaños tenga y varias rondas , y comprobar que me las separa bien.
 * 
 * dd if=/dev/zero count=1 bs=500|sed s/./e/g >> fich genera un fichero que tiene todo el mismo caracter.
 * 
 * 
 * formas :
 *  pidde
 */
