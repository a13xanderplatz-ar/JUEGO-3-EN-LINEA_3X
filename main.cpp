// Hello World program 
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
// #include "misfunciones.hpp"




#include <iostream>
//#comandos macro
#ifdef _WIN32
    #include <windows.h>//solo para windows aunque lo comente o borre igual va funcionar
    #define CLEAR_COMMAND "cls"//comando para limpiar pantlla
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>//ayuda en el desenpeño de la pantalla 
    #include <termios.h>
    #define CLEAR_COMMAND "clear"//comando para limpiar pantalla
#endif



void caratula(){
	std::system(CLEAR_COMMAND);            // Comando para borrar todo el contenido de la pantalla
    std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo

    std::cout << "\x1B[200;90;106m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************************************************/" << std::endl; 
	std::cout << "\x1B[m";             // Resetear color a valor por defecto
	std::cout << "\x1B[31;1m                         Universidad Catolica San Pablo \x1B[m" << std::endl; 
	std::cout << "\x1B[33;1m              Escuela Profesional de Ciencia de la Computacion \x1B[m" << std::endl; 
	std::cout << "\x1B[22;1m                     Curso de Ciencia de la Computacion I \x1B[m" << std::endl; 
	std::cout << "\x1B[38;5;63m                 Estudiante -Jhon Alexander Flores Condori  \x1B[m" << std::endl; 
	std::cout << "\x1B[3;38;5;160m                          Arequipa 2024 - Semestre II \x1B[m" << std::endl; 
	std::cout << "\x1B[200;90;106m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************************************************/" << std::endl;
	std::cout << "\x1B[m";             // Resetear color a valor por defecto 
	std::cout << "\n !! JUEGO 3 EN LINEA  !! \n\n";//46 // aqui pongo nombre de mis proyectos 
}
// // Declaración de funciones
void imprimir_tablero(char celda1, char celda2, char celda3,
                      char celda4, char celda5, char celda6,
                      char celda7, char celda8, char celda9);
bool tablero_lleno(char celda1, char celda2, char celda3,
                   char celda4, char celda5, char celda6,
                   char celda7, char celda8, char celda9);
bool juego_ganado(const char celda1, const char celda2, const char celda3,
                  const char celda4, const char celda5, const char celda6,
                  const char celda7, const char celda8, const char celda9);
void movimiento_jugador(char &celda1, char &celda2, char &celda3,
                        char &celda4, char &celda5, char &celda6,
                        char &celda7, char &celda8, char &celda9, char jugador);
void movimiento_computadora(char &celda1, char &celda2, char &celda3,
                             char &celda4, char &celda5, char &celda6,
                             char &celda7, char &celda8, char &celda9, char computadora, int dificultad);
bool bloquear_jugada(char &celda1, char &celda2, char &celda3,
                     char &celda4, char &celda5, char &celda6,
                     char &celda7, char &celda8, char &celda9, char computadora);
bool jugar_ganar(char &celda1, char &celda2, char &celda3,
                 char &celda4, char &celda5, char &celda6,
                 char &celda7, char &celda8, char &celda9, char computadora);

int main() {
	
	caratula();
    char celda1 = '1', celda2 = '2', celda3 = '3';
    char celda4 = '4', celda5 = '5', celda6 = '6';
    char celda7 = '7', celda8 = '8', celda9 = '9';

    char jugador = 'X';
    char computadora = 'O';
    char nombre_jugador[50];
	std::cout << "\x1B[200;90;106m";
	std::cout <<"\x1B[38;5;63m   Bienvenido al juego de Tres en Raya  \x1B[m" << std::endl;
	
    std::cout << "Jugador, ingrese su nombre: ";
    std::cin >> nombre_jugador;

    bool juego_ganado_flag = false;
    bool tablero_lleno_flag = false;
    int turno = 0;
    int dificultad;

	
	std::cout << "Seleccione la dificultad:" << std::endl;
	std::cout << "\x1B[3;38;5;160m      1: Facil \x1B[m" << std::endl;
	std::cout << "\x1B[3;38;5;160m      2: Medio \x1B[m" << std::endl;
	std::cout << "\x1B[3;38;5;160m      3: Dificil \x1B[m" << std::endl;
	// std::cout << "1: Facil" << std::endl;
	// std::cout << "2: Medio" << std::endl;
	// std::cout << "3: Dificil" << std::endl;
	std::cout << "Ingrese su opcion: ";
	std::cin >> dificultad;


    std::srand(std::time(nullptr));

    while (!juego_ganado_flag && !tablero_lleno_flag) {
        imprimir_tablero(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

        if (turno % 2 == 0) {
			std::cout << "\x1B[38;5;226m   es tu turno (X).. \x1B[m" << std::endl;
            //std::cout << nombre_jugador << ", es tu turno (X)." << std::endl;
            movimiento_jugador(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, jugador);
        } else {
			std::cout << "\x1B[38;5;226m   Es el turno de COMPUTIN (O). \x1B[m" << std::endl;
            std::cout << "Es el turno de COMPUTIN (O)." << std::endl;
            movimiento_computadora(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora, dificultad);
        }

        juego_ganado_flag = juego_ganado(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);
        tablero_lleno_flag = tablero_lleno(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

        turno++;//se incrementa en cada iteracion y depende de eso el turno del jugador si es par y termina cuando las casillas esten llenas 
    }

    imprimir_tablero(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

    if (juego_ganado_flag) {
        if (turno % 2 == 0) {
			std::cout << "\x1B[38;5;208m   COMPUTIN ha ganado. Mejor suerte la proxima vez  \x1B[m" << std::endl;
            //std::cout << "COMPUTIN ha ganado. Mejor suerte la proxima vez." << std::endl;
        } else {
			
            std::cout << "Felicidades " << nombre_jugador << ", has ganado." << std::endl;
        }
    } else if (tablero_lleno_flag) {
		
		std::cout << "\x1B[38;5;208m   El juego ha terminado en empate.  \x1B[m" << std::endl;
        //std::cout << "El juego ha terminado en empate." << std::endl;
    }

    return 0;
}

void imprimir_tablero(char celda1, char celda2, char celda3,
                      char celda4, char celda5, char celda6,
                      char celda7, char celda8, char celda9) {
    std::cout << "    A  | B  | C  " << std::endl;

    // Imprimir la primera fila con colores
    std::cout << " 1  \x1B[38;5;226m" << celda1 << "\x1B[m  | "
              << "\x1B[38;5;226m" << celda2 << "\x1B[m  | "
              << "\x1B[38;5;226m" << celda3 << "\x1B[m" << std::endl;
    std::cout << "   ____|____|____" << std::endl;

    // Imprimir la segunda fila con colores
    std::cout << " 2  \x1B[38;5;63m" << celda4 << "\x1B[m  | "
              << "\x1B[38;5;63m" << celda5 << "\x1B[m  | "
              << "\x1B[38;5;63m" << celda6 << "\x1B[m" << std::endl;
    std::cout << "   ____|____|____" << std::endl;

    // Imprimir la tercera fila con colores
    std::cout << " 3  \x1B[38;5;208m" << celda7 << "\x1B[m  | "
              << "\x1B[38;5;208m" << celda8 << "\x1B[m  | "
              << "\x1B[38;5;208m" << celda9 << "\x1B[m" << std::endl;
    std::cout << "       |    |    " << std::endl;
}

bool tablero_lleno(char celda1, char celda2, char celda3,
                   char celda4, char celda5, char celda6,
                   char celda7, char celda8, char celda9) {
    return celda1 != '1' && celda2 != '2' && celda3 != '3' &&
           celda4 != '4' && celda5 != '5' && celda6 != '6' &&
           celda7 != '7' && celda8 != '8' && celda9 != '9';
}

bool juego_ganado(const char celda1, const char celda2, const char celda3,
                  const char celda4, const char celda5, const char celda6,
                  const char celda7, const char celda8, const char celda9) {
    return (celda1 == celda2 && celda2 == celda3) || // horizontal
           (celda4 == celda5 && celda5 == celda6) ||
           (celda7 == celda8 && celda8 == celda9) ||
           (celda1 == celda4 && celda4 == celda7) || // vertical
           (celda2 == celda5 && celda5 == celda8) ||
           (celda3 == celda6 && celda6 == celda9) ||
           (celda1 == celda5 && celda5 == celda9) || // diagonal
           (celda3 == celda5 && celda5 == celda7);
}

void movimiento_jugador(char &celda1, char &celda2, char &celda3,
                        char &celda4, char &celda5, char &celda6,
                        char &celda7, char &celda8, char &celda9, char jugador) {
    char fila;
    char columna;

    while (true) {
		std::cout << "\x1B[38;5;208m   Ingrese la fila (1, 2, 3):  \x1B[m" << std::endl;
        //std::cout << "Ingrese la fila (1, 2, 3): ";
        std::cin >> fila;
		std::cout << "\x1B[38;5;208m   Ingrese la columna (A, B, C):  \x1B[m" << std::endl;
        //std::cout << "Ingrese la columna (A, B, C): ";
        std::cin >> columna;
		
		

         // Validar la entrada
        if ((fila == 'A' || fila == 'a') && (columna >= 1 && columna <= 3)) {
            if (columna == 1 && celda1 == '1') { celda1 = jugador; return; }
            if (columna == 2 && celda2 == '2') { celda2 = jugador; return; }
            if (columna == 3 && celda3 == '3') { celda3 = jugador; return; }
        } else if ((fila == 'B' || fila == 'b') && (columna >= 1 && columna <= 3)) {
            if (columna == 1 && celda4 == '4') { celda4 = jugador; return; }
            if (columna == 2 && celda5 == '5') { celda5 = jugador; return; }
            if (columna == 3 && celda6 == '6') { celda6 = jugador; return; }
        } else if ((fila == 'C' || fila == 'c') && (columna >= 1 && columna <= 3)) {
            if (columna == 1 && celda7 == '7') { celda7 = jugador; return; }
            if (columna == 2 && celda8 == '8') { celda8 = jugador; return; }
            if (columna == 3 && celda9 == '9') { celda9 = jugador; return; }
        }

        // Asignar el valor al tablero según la fila y columna
        if (fila == '1') {
            if (columna == 'A' && celda1 == '1') { celda1 = jugador; return; }
            if (columna == 'B' && celda2 == '2') { celda2 = jugador; return; }
            if (columna == 'C' && celda3 == '3') { celda3 = jugador; return; }
        } else if (fila == '2') {
            if (columna == 'A' && celda4 == '4') { celda4 = jugador; return; }
            if (columna == 'B' && celda5 == '5') { celda5 = jugador; return; }
            if (columna == 'C' && celda6 == '6') { celda6 = jugador; return; }
        } else if (fila == '3') {
            if (columna == 'A' && celda7 == '7') { celda7 = jugador; return; }
            if (columna == 'B' && celda8 == '8') { celda8 = jugador; return; }
            if (columna == 'C' && celda9 == '9') { celda9 = jugador; return; }
        }
		std::cout << "\x1B[3;38;5;160m      Esa celda ya esta ocupada Intentelo de nuevo  \x1B[m" << std::endl;
        //std::cout << "Esa celda ya esta ocupada Intentelo de nuevo." << std::endl;
		continue;
    }
}

void movimiento_computadora(char &celda1, char &celda2, char &celda3,
                             char &celda4, char &celda5, char &celda6,
                             char &celda7, char &celda8, char &celda9, char computadora, int dificultad) {
    if (dificultad == 1) {
        // Fácil: movimiento aleatorio
        while (true) {
            int movimiento = std::rand() % 9 + 1; // Generar un movimiento entre 1 y 9
            if (movimiento == 1 && celda1 == '1') { celda1 = computadora; break; }
            if (movimiento == 2 && celda2 == '2') { celda2 = computadora; break; }
            if (movimiento == 3 && celda3 == '3') { celda3 = computadora; break; }
            if (movimiento == 4 && celda4 == '4') { celda4 = computadora; break; }
            if (movimiento == 5 && celda5 == '5') { celda5 = computadora; break; }
            if (movimiento == 6 && celda6 == '6') { celda6 = computadora; break; }
            if (movimiento == 7 && celda7 == '7') { celda7 = computadora; break; }
            if (movimiento == 8 && celda8 == '8') { celda8 = computadora; break; }
            if (movimiento == 9 && celda9 == '9') { celda9 = computadora; break; }
        }
    } else if (dificultad == 2) {
        // Medio: intentar bloquear
        if (!bloquear_jugada(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora)) {
            // Si no se bloqueó, hacer un movimiento aleatorio
            movimiento_computadora(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora, 1);
        }
    } else if (dificultad == 3) {
        // Difícil: intentar ganar primero
        if (!jugar_ganar(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora)) {
            // Si no ganó, intentar bloquear
            if (!bloquear_jugada(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora)) {
                // Si no se bloqueó, hacer un movimiento aleatorio
                movimiento_computadora(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, computadora, 1);
            }
        }
    }
}

bool bloquear_jugada(char &celda1, char &celda2, char &celda3,
                     char &celda4, char &celda5, char &celda6,//se agrega el paranetro de la computadora 'O'
                     char &celda7, char &celda8, char &celda9, char computadora) {
    char oponente = (computadora == 'O') ? 'X' : 'O';

    // Comprueba cada combinación de líneas ganadoras
    if (celda1 == oponente && celda2 == oponente && celda3 == '3') { celda3 = computadora; return true; }
    if (celda1 == oponente && celda3 == oponente && celda2 == '2') { celda2 = computadora; return true; }
    if (celda2 == oponente && celda3 == oponente && celda1 == '1') { celda1 = computadora; return true; }
    
    if (celda4 == oponente && celda5 == oponente && celda6 == '6') { celda6 = computadora; return true; }
    if (celda4 == oponente && celda6 == oponente && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == oponente && celda6 == oponente && celda4 == '4') { celda4 = computadora; return true; }
    
    if (celda7 == oponente && celda8 == oponente && celda9 == '9') { celda9 = computadora; return true; }
    if (celda7 == oponente && celda9 == oponente && celda8 == '8') { celda8 = computadora; return true; }
    if (celda8 == oponente && celda9 == oponente && celda7 == '7') { celda7 = computadora; return true; }

    if (celda1 == oponente && celda4 == oponente && celda7 == '7') { celda7 = computadora; return true; }
    if (celda1 == oponente && celda7 == oponente && celda4 == '4') { celda4 = computadora; return true; }
    if (celda4 == oponente && celda7 == oponente && celda1 == '1') { celda1 = computadora; return true; }
    
    if (celda2 == oponente && celda5 == oponente && celda8 == '8') { celda8 = computadora; return true; }
    if (celda2 == oponente && celda8 == oponente && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == oponente && celda8 == oponente && celda2 == '2') { celda2 = computadora; return true; }
    
    if (celda3 == oponente && celda6 == oponente && celda9 == '9') { celda9 = computadora; return true; }
    if (celda3 == oponente && celda9 == oponente && celda6 == '6') { celda6 = computadora; return true; }
    if (celda6 == oponente && celda9 == oponente && celda3 == '3') { celda3 = computadora; return true; }

    if (celda1 == oponente && celda5 == oponente && celda9 == '9') { celda9 = computadora; return true; }
    if (celda1 == oponente && celda9 == oponente && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == oponente && celda9 == oponente && celda1 == '1') { celda1 = computadora; return true; }

    if (celda3 == oponente && celda5 == oponente && celda7 == '7') { celda7 = computadora; return true; }
    if (celda3 == oponente && celda7 == oponente && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == oponente && celda7 == oponente && celda3 == '3') { celda3 = computadora; return true; }

    return false; // No se bloqueó
}

bool jugar_ganar(char &celda1, char &celda2, char &celda3,//a función verifique si la computadora puede ganar en su próximo movimiento.
                 char &celda4, char &celda5, char &celda6,
                 char &celda7, char &celda8, char &celda9, char computadora) {
    // Comprueba cada combinación de líneas ganadoras
    if (celda1 == computadora && celda2 == computadora && celda3 == '3') { celda3 = computadora; return true; }
    if (celda1 == computadora && celda3 == computadora && celda2 == '2') { celda2 = computadora; return true; }
    if (celda2 == computadora && celda3 == computadora && celda1 == '1') { celda1 = computadora; return true; }
    
    if (celda4 == computadora && celda5 == computadora && celda6 == '6') { celda6 = computadora; return true; }
    if (celda4 == computadora && celda6 == computadora && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == computadora && celda6 == computadora && celda4 == '4') { celda4 = computadora; return true; }
    
    if (celda7 == computadora && celda8 == computadora && celda9 == '9') { celda9 = computadora; return true; }
    if (celda7 == computadora && celda9 == computadora && celda8 == '8') { celda8 = computadora; return true; }
    if (celda8 == computadora && celda9 == computadora && celda7 == '7') { celda7 = computadora; return true; }

    if (celda1 == computadora && celda4 == computadora && celda7 == '7') { celda7 = computadora; return true; }
    if (celda1 == computadora && celda7 == computadora && celda4 == '4') { celda4 = computadora; return true; }
    if (celda4 == computadora && celda7 == computadora && celda1 == '1') { celda1 = computadora; return true; }
    
    if (celda2 == computadora && celda5 == computadora && celda8 == '8') { celda8 = computadora; return true; }
    if (celda2 == computadora && celda8 == computadora && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == computadora && celda8 == computadora && celda2 == '2') { celda2 = computadora; return true; }
    
    if (celda3 == computadora && celda6 == computadora && celda9 == '9') { celda9 = computadora; return true; }
    if (celda3 == computadora && celda9 == computadora && celda6 == '6') { celda6 = computadora; return true; }
    if (celda6 == computadora && celda9 == computadora && celda3 == '3') { celda3 = computadora; return true; }

    if (celda1 == computadora && celda5 == computadora && celda9 == '9') { celda9 = computadora; return true; }
    if (celda1 == computadora && celda9 == computadora && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == computadora && celda9 == computadora && celda1 == '1') { celda1 = computadora; return true; }

    if (celda3 == computadora && celda5 == computadora && celda7 == '7') { celda7 = computadora; return true; }
    if (celda3 == computadora && celda7 == computadora && celda5 == '5') { celda5 = computadora; return true; }
    if (celda5 == computadora && celda7 == computadora && celda3 == '3') { celda3 = computadora; return true; }

    return false; // No se puede ganar
}
