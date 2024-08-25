#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *decode_morse(const char* morse_code) {
    
    int n = 1;
    char *symbol = calloc(10, 20);
    char *ptr_symbol = symbol;
    
    int count = 0;
    while(morse_code[count] != '\0') {
        
        if (morse_code[count] == ' ') break;
        *ptr_symbol++ = morse_code[count];
        count++;
    }
    
    return symbol;

}
void searching(const char *const morse[], char *symbol) {
    for (int i = 0; i < 3; i++) {
      printf("%s\n", morse[i]);
    }
}


int main() {
const char *const morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *const ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};
char morse_code[] = ".... . -.--   .--- ..- -.. .";

searching(morse, decode_morse(morse_code));



return 0; 
}





