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

/** @file calculadora.c
 ** @brief Código fuente del módulo para la gestión de una calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculadora.h"
#include <stdlib.h>
#include <string.h>

/* === Macros definitions ========================================================================================== */

#ifndef OPERATIONS_MAX
#define OPERATIONS_MAX 10
#endif

/* === Private data type declarations ============================================================================== */

//! Tipo de dato para las operaciones
typedef struct operation_s * operation_t;

struct operation_s {
    char             operator;
    operation_func_t function;
    operation_t      next;
};

struct calculator_s {
    operation_t operations;
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Función para encontrar una operación en la calculadora por su operador.
 *
 * @param calculator Puntero a la calculadora
 * @param operator Cadena de caracteres que representa la operación a buscar
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
static operation_t OperationFind(calculator_t calculator, char operator);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

static operation_t OperationFind(calculator_t self, char operator) {
    operation_t current = self->operations;
    while (current != NULL) {
        if (current->operator == operator) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* === Public function definitions ============================================================================== */

/** @brief Ver calculadora.h para más detalles. */
calculator_t CalculatorCreate(void) {
    calculator_t self = malloc(sizeof(struct calculator_s));
    if (self != NULL) {
        self->operations = NULL;
    }
    return self;
}

/** @brief Ver calculadora.h para más detalles. */
bool CalculatorAddOperation(calculator_t self, char operator, operation_func_t function) {
    if (!self || !function || OperationFind(self, operator)) {
        return false;
    }

    operation_t new_operation = malloc(sizeof(struct operation_s));

    if (new_operation) {
        new_operation->operator = operator;
        new_operation->function = function;
        new_operation->next = self->operations;
        self->operations = new_operation;
        return true;
    }
    return false;
}

/** @brief Ver calculadora.h para más detalles. */
int CalculatorCalculate(calculator_t self, const char * expression) {
    int a = 0, b = 0;
    char operator = 0;
    int result = 0;

    if (!self || !expression) {
        return 0;
    }

    for (size_t i = 0; i < strlen(expression); i++) {
        if ((expression[i] < '0') || (expression[i] > '9')) {
            operator = expression[i];
            a = atoi(expression);
            b = atoi(expression + i + 1);
            break;
        }
    }

    operation_t operation = OperationFind(self, operator);
    if (operation) {
        result = operation->function(a, b);
    }
    return result;
}

/** @brief Ver calculadora.h para más detalles. */
int OperationAdd(int a, int b) {
    return a + b;
}

/** @brief Ver calculadora.h para más detalles. */
int OperationSubtract(int a, int b) {
    return a - b;
}

/** @brief Ver calculadora.h para más detalles. */
int OperationMultiply(int a, int b) {
    return a * b;
}

/** @brief Ver calculadora.h para más detalles. */
int OperationDivide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}

/* === End of documentation ======================================================================================== */
