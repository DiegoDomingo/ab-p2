#
# AUTORES:     Diego Domingo Ralla (818637)
#              Simón Alonso Gutiérrez (821038)
# ASIGNATURA:  Algoritmia Básica
# FECHA:       19 abril 2023
# FICHERO:     ejecutar.sh
# DESCRIPCIÓN: Script de ejecución que automatiza la compilación y ejecución del
#              programa con un casos de prueba
#

#!/bin/bash

# Compilación del fuente
g++ -std=c++11 pinball.cc -o pinball

# Ejecución del programa
./pinball pruebas.txt resultados.txt

# Limpieza de ejecutables
rm pinball
