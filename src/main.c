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

/** @file main.c
 ** @brief Código fuente del Programa principal
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculadora.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/**
 * @brief Función propia del programa principal para realizar un suma de 2 enteros
 *
 * @param op1 Primer operando de la suma
 * @param op2 Segundo operando de la suma
 * @return int Resultado de la suma
 */
int OperacionSuma(int op1, int op2) {
    return op1 + op2;
}

/**
 * @brief Función propia del programa principal para realizar una resta de 2 enteros
 *
 * @param op1 Primer operando de la resta (minuendo)
 * @param op2 Segundo operando de la resta (sustraendo)
 * @return int Resultado de la resta
 */
int OperacionResta(int op1, int op2) {
    return op1 - op2;
}

/**
 * @brief Función propia del programa principal para realizar un producto de 2 enteros
 *
 * @param op1 Primer factor de la multiplicación
 * @param op2 Segundo factor de la multiplicación
 * @return int Resultado de la multiplicación
 */
int OperacionMultiplicacion(int op1, int op2) {
    return op1 * op2;
}

/**
 * @brief Función propia del programa principal para realizar una división entera entre 2 enteros Op1/Op2
 *
 * @param op1 Primer operando de la división entera (dividendo)
 * @param op2 Segundo operando de la división entera (divisor)
 * @return int Resultado de la división entera (si el divisor es 0, dará un mensaje de error y devolverá 0)
 */
int OperacionDivisionEntera(int op1, int op2) {
    if (op2 != 0) {
        return op1 / op2;
    }

    printf("ERROR: La division por 0 NO esta permitida \n");
    return 0;
}

int main() {
    const char suma[] = "45+13";
    const char resta[] = "8-10";
    const char producto[] = "15x6";
    const char division[] = "15/3";

    calculadora_t calculadora = CalculadoraCrear();

    CalculadoraAgregarOperacion(calculadora, '+', OperacionSuma);
    CalculadoraAgregarOperacion(calculadora, '-', OperacionResta);
    CalculadoraAgregarOperacion(calculadora, 'x', OperacionMultiplicacion);
    CalculadoraAgregarOperacion(calculadora, '/', OperacionDivisionEntera);

    printf("%s = %i\n", suma, CalculadoraCalcular(calculadora, suma));
    printf("%s = %i\n", resta, CalculadoraCalcular(calculadora, resta));
    printf("%s = %i\n", producto, CalculadoraCalcular(calculadora, producto));
    printf("%s = %i\n", division, CalculadoraCalcular(calculadora, division));

    return 0;
}

/* === Private function definitions ================================================================================ */

/* === Public function definitions ================================================================================= */

/* === End of documentation ======================================================================================== */