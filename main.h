#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(int *pos, char *str_to_print);
int print_number(int *pos, long int number);
int num_to_char(int num);
int print_binary(int *pos, int number);
int print_char(int *pos, int char_to_print);
unsigned long int exponent_num(unsigned int base, unsigned long int times);
int print_unsigned(int *pos, long int n);
char *get_binary_negative(long int n);
int print_octal(int *pos, long int n);
#endif
