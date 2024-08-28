В приведённом вами коде есть несколько ошибок и неточностей, которые требуют исправления. Вот переработанный и исправленный вариант вашего кода:

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

char *decode_morse(const char* morse_code) {

    int n = 1;

    char *symbol = calloc(20, sizeof(char)); // Исправлено выделение памяти

    char *ptr_symbol = symbol;

    int count = 0;

    while (morse_code[count] != '\\0') { // Исправлено условие проверки

        if (morse_code[count] == ' ') { // Исправлено: символ ' ' нужно обрабатывать иначе

            break; 

        }

        *ptr_symbol++ = morse_code[count];

        count++;

    }

    *ptr_symbol = '\\0'; // Завершаем строку

    return symbol;

}

void searching(const char *const morse[], const char *const ascii[], char *symbol) {

    for (int i = 0; i < 55; i++) { // Исправлено: нужно было изменить условие цикла

        if (strcmp(morse[i], symbol) == 0) {

            printf("Decoded symbol: %s\\n", ascii[i]);

            return; // Выходим из функции после нахождения

        }

    }

    printf("Symbol not found\\n");

}

int main() {

    const char *const morse[55] = {

        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",

        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 

        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", 

        "..---", "...--", "....-", ".....", "-....", "--...", "---..", 

        "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", 

        "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", 

        ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."

    };

    const char *const ascii[55] = {

        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 

        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", 

        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", 

        "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", 

        "_", "\\"", "$", "@", "SOS"

    };

    char morse_code[] = ".... . -.--   .--- ..- -.. ."; // Исходный код Морзе

    // Разделим строку по пробелам и будем обрабатывать каждую часть

    char *token = strtok(morse_code, " ");

    while (token != NULL) {

        searching(morse, ascii, decode_morse(token));

        token = strtok(NULL, " ");

    }

    return 0;

}

В этом исправленном коде:

Исправлено выделение памяти для массива символов: в calloc передан корректный размер элемента и количество элементов.

Исправлено использование условия в цикле для проверки конца строки (используется '\\0').

Добавлено завершение строки для декодированной строки.

Функция searching теперь принимает дополнительные параметры для массива ascii и корректно выполняет поиск символа. Если символ не найден, выдается соответствующее сообщение.

Внешнее разделение кода Морзе на токены выполнено с использованием strtok, чтобы обрабатывать каждую часть кода Морзе отдельно.

