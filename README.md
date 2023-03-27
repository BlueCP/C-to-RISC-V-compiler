# C to RISC-V compiler

This repository contains the source code for a C to RISC-V compiler, written in C++. It complies with a partial subset of the C99 standard, with a summary of supported features included below. It uses Flex and Bison as the lexer and parser, respectively.

Supported features:
- Basic language constructs, such as conditional statements and loops.
- A range of types including `void`, `char`, `int`, `float`, `double`, and `unsigned`.
- Variable scope.
- Stack frames, allowing for recursive functions.
- Arrays.
- Floating point operations.
- Enums.