#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string-helpers.h"
#include "utils.h"

/*
   Given two character pointers 'src' and 'dest', this function copies from
   'src' to 'dest' and changes every uppercase character to
   lowercase.
   The resulting string in 'dest' is null terminated.
*/
void lower_strcpy(char* restrict dest, char* restrict src) {
  for (size_t i = 0; i < strlen(src); i++) {
    dest[i] = src[i] | 0x20;
  }
  dest[strlen(src)] = '\0';
}

/*
   Given a character pointer 'str', this function first checks to see if
   the first character is an escaped character. If it is not, it returns -1.
   If it is an escaped character, it returns the character which is escaped.
*/
int replace_escape_in_character(char* str) {
  if (str[0] != '\\') {
    return -1;
  }
  switch (str[1]) {
    case ('n'):
      return '\n';
    case ('t'):
      return '\t';
    case ('0'):
      return '\0';
    case ('\\'):
      return '\\';
    case ('\''):
      return '\'';
    default:
      return -1;
  }
}

/*
   Given a character pointer 'str', this function first checks to see if
   the first character is an escaped character. If it is not, it returns -1.
   If it is an escaped character, it returns the character which is escaped.

   Note: The escape characters valid in strings and characters differ, hence
   the two separate functions. Please see the lexing grammar for details.
*/
int replace_escape_in_string(char* str) {
  if (str[0] != '\\') {
    return -1;
  }
  switch (str[1]) {
    case ('n'):
      return '\n';
    case ('t'):
      return '\t';
    case ('0'):
      return '\0';
    case ('\\'):
      return '\\';
    case ('\"'):
      return '"';
    default:
      return -1;
  }
}

/*
   Given a single character 'c', this function returns 1 if the character is
   an English alphabet character (upper or lowercase). Otherwise, the
   function returns 0.
*/
int is_alpha(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}

/*
   Given a single character 'c', the function returns 1 if the character is a
   (white)space character according to our grammar. If it is not a
   (white)space character, the function returns 0.
*/
int is_space(char c) {
    if ((c == ' ') || (c == '\n')) {
        return 1;
    }
  return 0;
}

/*
   Given a single character 'c', the function returns 1 if the charcter is a
   digit according to our grammar. If it is not, the function returns 0.
*/
int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

/*
   Given a single character 'c', this function returns 1 if the character is
   a component of an identifier (letter, digit, or underscore). Otherwise,
   the functionstrings returns 0.
*/
int is_identifier_component(char c) {
    if (is_alpha(c) || is_digit(c) || c == '_') {
        return 1;
    }
    return 0;
}

/*
   Given a character pointer 'str', this function returns 1 if the string
   is a valid identifier. Consider using the function above! If it is not
   a valid identifier, the function returns 0.
*/
int is_valid_identifier(char* str) {
  /* YOUR CODE HERE */
    int n = 0;
    if (str[0] == '_') {
       return 0;
    }
    while (n < strlen (str)) {
        if (!is_identifier_component(str[n])) {
           return 0;
        }
        n++;
    }
    if (str[n] != '\0') {
       return 0;
    }
    return 1;
}

/*
   Given a list of character pointers 'strings' and the length of the list
   'count', this function returns a newly allocated character pointer
   containing all characters in 'strings' concatenated together.
   The returned character pointer should be null terminated.
*/
char* str_concat(char** strings, size_t count) {
    int len = 1;
    int n = 0;
    while (n < count) {
        len += strlen(strings[n]);
        n++;
    }
    char concat[len];
    int index = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < strlen (strings[i]); j++) {
            concat[index] = strings[i][j];
            index++;
        }
    }
    concat[index] = '\0';
    char* p = concat;
    return p;
}
