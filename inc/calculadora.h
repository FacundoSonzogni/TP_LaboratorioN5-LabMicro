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

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** @file calculadoraa.h
 ** @brief Declaraciones del Módulo de Calculadora
 **
 ** @addtogroup Calculadora Modulo de Gestion de la Calculadora
 ** @{
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

//! Estructura que representa al objeto calculadora creada
typedef struct calculadora_s * calculadora_t;

//! Estructura de datos con las funciones que puede realizar la calculadora
typedef int (*calculadora_funciones_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Función que permite crear una calculadora
 * 
 * @return calculadora_t Puntero a la estructura con los datos de la calculadora creada
 */
calculadora_t CalculadoraCrear(void);

/**
 * @brief Función que permite agregar una operación
 * 
 * @param calculadora Puntero a la estructura con los datos de la calculadora
 * @param operador Simbolo que representa al operador con el que se realiza la operación que se agrega
 * @param funcion Puntero a la función que describe como se realiza la operación que se agrega
 * @return int 1 si pudo agregar la operación y 0 si NO pudo agregar la operación
 */
int CalculadoraAgregarOperacion(calculadora_t calculadora, char operador, calculadora_funciones_t funcion);

/**
 * @brief Función que permite realizar una operación
 * 
 * @param calculadora Puntero a la estructura con los datos de la calculadora
 * @param expresion Expresión que representa la operación que se quiere realizar
 * @return int Resultado de la operación
 */
int CalculadoraCalcular(calculadora_t calculadora, const char * expresion);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif
//! @}

#endif /* CALCULADORA_H */