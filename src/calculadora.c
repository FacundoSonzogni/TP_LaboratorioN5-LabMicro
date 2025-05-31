/*********************************************************************************************************************
Copyright (c) 2025, Facundo Sonzogni <facundosonzogni1@gmail.com>
Copyright (c) 2025, Laboratorio de Microprocesadores, Universidad Nacional de Tucumán

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

/** @file calculadora.c
 ** @brief Código fuente del Módulo de gestión de la Calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculadora.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

//! Estructura de datos que representa a una operación
typedef struct operacion_s* operacion_t;

//! Estructura de datos que representa a una operación
struct operacion_s {
    char operador;                   //!< Simbolo del operador utilizado para representar la operación
    calculadora_funciones_t funcion; //!< Funcion que se realiza al realizar la operación
    operacion_t siguiente_operacion; //!< Puntero a la siguiente operación
};

//! Estructura que representa al objeto calculadora
struct calculadora_s {
    operacion_t operacion; //!< Puntero a la operación actual
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Función que permite buscar una operación en función de su operador
 * 
 * @param calculadora Puntero a la estructura con los datos de la calculadora
 * @param operador Operador que representa a la operación que se desea buscar
 * @return operacion_t Puntero a la estructura encontrada o NULL si la operación no existe
 */
static operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

static operacion_t BuscarOperacion(calculadora_t self, char operador){
    operacion_t operacion_actual = self->operacion;

    while(operacion_actual != NULL){
        if(operacion_actual->operador == operador){
            return operacion_actual;
        }

        operacion_actual = operacion_actual->siguiente_operacion;
    }

    return NULL;
}

/* === Public function definitions ================================================================================= */

calculadora_t CalculadoraCrear(void) {
    calculadora_t self = malloc(sizeof(struct calculadora_s));

    if(self != NULL){
        self->operacion = NULL;
    }

    return self;
}

int CalculadoraAgregarOperacion(calculadora_t calculadora, char operador, calculadora_funciones_t funcion) {
    operacion_t operacion_buscada = BuscarOperacion(calculadora, operador);

    if((calculadora == NULL) || (funcion == NULL) || (operacion_buscada != NULL)){
        return 0;
    }

    operacion_t operacion_agregada = malloc(sizeof(struct operacion_s));
    if(operacion_agregada != NULL){
        operacion_agregada->operador = operador;
        operacion_agregada->funcion = funcion;
        operacion_agregada->siguiente_operacion = calculadora->operacion;
        calculadora->operacion = operacion_agregada;

        return 1;
    }

    return 0;
}


int CalculadoraCalcular(calculadora_t calculadora, const char * expresion) {
    int op1 = 0;
    int op2 = 0;
    char operador = 0;
    int resultado = 0;

    if((calculadora == NULL) || (expresion == NULL)){
        return 0;
    }

    for(int i=0; i < (int)strlen(expresion); i++){
        if(isdigit(expresion[i]) == 0){
            operador = expresion[i];
            op1 = atoi(expresion);
            op2 = atoi(expresion + 1 + i);
            break;
        }
    }

    operacion_t operacion = BuscarOperacion(calculadora, operador);

    if(operacion !=NULL){
        resultado = operacion->funcion(op1,op2);

        return resultado;
    }

    return 0;

}
/* === End of documentation ======================================================================================== */