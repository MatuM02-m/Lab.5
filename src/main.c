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

/** @file main.c
 ** @brief Código fuente del módulo principal
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculadora.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int main(void) {
    static const char suma[] = "6+5";
    static const char resta[] = "5-2";
    static const char multiplicacion[] = "3*4";
    static const char division[] = "7/2";

    calculator_t calculadora = CalculatorCreate();
    CalculatorAddOperation(calculadora, '+', OperationAdd);
    CalculatorAddOperation(calculadora, '-', OperationSubtract);
    CalculatorAddOperation(calculadora, '*', OperationMultiply);
    CalculatorAddOperation(calculadora, '/', OperationDivide);

    printf("\nSuma: %s = %d\n", suma, CalculatorCalculate(calculadora, suma));
    printf("\nResta: %s = %d\n", resta, CalculatorCalculate(calculadora, resta));
    printf("\nMultiplicación: %s = %d\n", multiplicacion, CalculatorCalculate(calculadora, multiplicacion));
    printf("\nDivisión: %s = %d\n\n", division, CalculatorCalculate(calculadora, division));

    return 0;
}

/* === End of documentation ======================================================================================== */
