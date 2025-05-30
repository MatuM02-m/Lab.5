/*********************************************************************************************************************
Copyright (c) 2025, Matías Milenkovitch <matiasmilenko02@gmail.com>

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

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/** @file calculadora.h
 ** @brief Declaraciones del módulo para la gestión de una calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdbool.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

//! Tipo de dato para el objeto calculadora
typedef struct calculator_s * calculator_t;

//!Tipo de dato para las funciones de operación
typedef int (*operation_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

calculator_t CalculatorCreate(void);

bool CalculatorAddOperation(calculator_t calculator, char operator, operation_func_t function);

int CalculatorCalculate( calculator_t, const char * expression);

int OperationAdd(int a, int b);

int OperationSubtract(int a, int b);

int OperationMultiply(int a, int b);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* PLANTILLA_H_ */
