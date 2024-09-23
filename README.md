# JUEGO-3-EN-LINEA_3X
Tres en Raya es un clásico juego de estrategia donde dos jugadores, un humano y una computadora, se enfrentan en un tablero de 3x3. El objetivo es ser el primero en colocar tres de sus símbolos en línea, ya sea de forma horizontal, vertical o diagonal.

Características Interfaz Simple: El juego presenta un tablero claro y fácil de leer. Opción de Dificultad: El jugador puede seleccionar entre tres niveles de dificultad: Fácil, Medio y Difícil. Movimiento Aleatorio: En el nivel Fácil, la computadora realiza movimientos aleatorios. Estrategias Avanzadas: En los niveles Medio y Difícil, la computadora intenta bloquear jugadas del jugador y buscar ganar cuando sea posible. Empate: Si todas las celdas están llenas y ningún jugador ha ganado, el juego terminará en empate. Cómo Jugar Inicia el juego y elige tu nivel de dificultad. Ingresa tu nombre. Alterna turnos con la computadora, eligiendo celdas en el tablero. El juego terminará cuando un jugador gane o el tablero esté lleno.
1. Declaración de funciones
El código comienza con la declaración de varias funciones que gestionan diferentes aspectos del juego:

imprimir_tablero: Muestra el estado actual del tablero.
tablero_lleno: Comprueba si el tablero está completo (sin celdas vacías).
juego_ganado: Verifica si alguno de los jugadores ha ganado.
movimiento_jugador: Maneja la entrada del jugador.
movimiento_computadora: Decide el movimiento de la computadora según la dificultad.
bloquear_jugada: Intenta bloquear al jugador si está a punto de ganar.
jugar_ganar: Verifica si la computadora puede ganar en su siguiente movimiento.
2. Función main
En main, se inicializan las celdas del tablero y se definen los caracteres para el jugador ('X') y la computadora ('O'). También se solicita el nombre del jugador y la dificultad del juego.

3. Bucle del juego
El juego se desarrolla en un bucle while que continúa hasta que uno de los jugadores gane o el tablero esté lleno. Dentro del bucle:

Se imprime el tablero.
Se alterna el turno entre el jugador y la computadora.
Se actualizan las banderas de juego ganado y tablero lleno.
Se incrementa el turno.
4. Finalización del juego
Una vez que el bucle termina, se imprime el resultado final, ya sea que el jugador o la computadora ganaron o que hubo un empate. Luego, se pregunta si el jugador quiere jugar de nuevo, reiniciando el juego si la respuesta es afirmativa.

5. Funciones auxiliares
Las funciones auxiliares hacen el trabajo pesado:

imprimir_tablero: Muestra el tablero de forma estilizada con colores.
tablero_lleno: Verifica si todas las celdas están ocupadas.
juego_ganado: Comprueba todas las combinaciones posibles para ver si hay un ganador (filas, columnas y diagonales).
movimiento_jugador: Permite que el jugador elija una celda para marcar su movimiento, asegurándose de que la celda esté vacía.
movimiento_computadora: La lógica de la computadora varía según la dificultad (fácil, medio, difícil) y puede realizar movimientos aleatorios, bloquear al jugador o intentar ganar.
6. Lógica de dificultad
Dificultad 1 (Fácil): La computadora juega de manera aleatoria.
Dificultad 2 (Media): La computadora intenta bloquear al jugador si está a punto de ganar.
Dificultad 3 (Difícil): La computadora primero intenta ganar; si no puede, intenta bloquear al jugador.
7. Validación de entrada
El código incluye validaciones para asegurarse de que los movimientos del jugador son válidos y de que las celdas elegidas están disponibles.

Resumen
Este código implementa un juego de Tres en Raya interactivo con diferentes niveles de dificultad y una buena estructura modular. Si necesitas profundizar en alguna parte específica o tienes más preguntas sobre el código, ¡hazmelo saber!
