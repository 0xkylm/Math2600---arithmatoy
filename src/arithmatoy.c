#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

int VERBOSE = 0;

const char *get_all_digits() { return "0123456789abcdefghijklmnopqrstuvwxyz"; }
const size_t ALL_DIGIT_COUNT = 36;

void arithmatoy_free(char *number) { free(number); }

char *arithmatoy_add(unsigned int base, const char *lhs, const char *rhs) {
  if (VERBOSE) {
    fprintf(stderr, "add: entering function\n");
  }

  // Fill the function, the goal is to compute lhs + rhs
  // You should allocate a new char* large enough to store the result as a
  // string Implement the algorithm Return the result

  if (VERBOSE){
    fprintf(stderr,"lhs: %s, rhs: %s, base %d\n",lhs,rhs,base);
  }

  if (lhs == NULL || rhs == NULL){return NULL;}

  if (rhs == NULL){strdup(lhs);}
  if (lhs == NULL){strdup(rhs);}


  lhs = drop_leading_zeros(lhs);
  rhs = drop_leading_zeros(rhs);
  char *lhs_ = reverse(strdup(lhs));
  char *rhs_ = reverse(strdup(rhs));
  unsigned int lhs_len = strlen(lhs_);
  unsigned int rhs_len = strlen(rhs_);
  unsigned int Len = lhs_len;
  if (rhs_len > lhs_len) {Len = rhs_len;}
  char *res = (char *)malloc((Len + 2) * sizeof(char));
  if (res == NULL) {printf("Malloc error");exit(-1);}
  res[Len+1] = 0;
  res[Len+2] = 0;
  int retenu = 0;
  for (int i = 0; i < Len; ++i) {

      int lhsNb = 0;
      int rhsNb = 0;
      
    if (i < lhs_len){
      lhsNb = get_digit_value(lhs_[i]);
    }
    if (i < rhs_len){
      rhsNb = get_digit_value(rhs_[i]);
    }
    int sum = lhsNb + rhsNb + retenu;
    retenu = sum / base;

    res[i] = to_digit(sum % base);

  }

   if (retenu) res[Len++] = to_digit(retenu);
   res = reverse(res);
   res = (char *)drop_leading_zeros(res);
  return res;
}

char *arithmatoy_sub(unsigned int base, const char *lhs, const char *rhs) {
  if (VERBOSE) {
    fprintf(stderr, "sub: entering function\n");
  }

    if (VERBOSE){
    fprintf(stderr,"lhs: %s, rhs: %s, base %d\n",lhs,rhs,base);
  }

//  if (lhs == NULL && rhs == NULL){return NULL;}

  if (rhs == NULL){strdup(lhs);}
  if (lhs == NULL){strdup(rhs);}


  lhs = drop_leading_zeros(lhs);
  rhs = drop_leading_zeros(rhs);
  char *lhs_ = reverse(strdup(lhs));
  char *rhs_ = reverse(strdup(rhs));

  unsigned int lhs_len = strlen(lhs_);
  unsigned int rhs_len = strlen(rhs_);
  unsigned int Len = lhs_len;
  if (rhs_len > lhs_len) {Len = rhs_len;}
  char *res = (char *)malloc((Len + 2) * sizeof(char));

  if (res == NULL) {printf("Malloc error");exit(-1);}

  res[Len+1] = 0;
  res[Len+2] = 0;
  int retenu = 0;



  for (int i =0; i < Len; i++){
    int lhsNb = get_digit_value(lhs_[i]);
    int rhsNb = 0;
    if (i<rhs_len){
      rhsNb = get_digit_value(rhs_[i]);
    }
    int diff = lhsNb -rhsNb - retenu;
    if (diff < 0){
      diff += base;
      retenu = 1;
    }else {
      retenu = 0;
    }
    res[i] = to_digit(diff);
  }

  res = reverse(res);
  res = (char *)drop_leading_zeros(res);

  res[Len] = 0;
  return res;

  // Fill the function, the goal is to compute lhs - rhs (assuming lhs > rhs)
  // You should allocate a new char* large enough to store the result as a
  // string Implement the algorithm Return the result
}

char *arithmatoy_mul(unsigned int base, const char *lhs, const char *rhs) {
  if (VERBOSE) {
    fprintf(stderr, "mul: entering function\n");
  }

  // Fill the function, the goal is to compute lhs * rhs
  // You should allocate a new char* large enough to store the result as a
  // string Implement the algorithm Return the result
}

// Here are some utility functions that might be helpful to implement add, sub
// and mul:

unsigned int get_digit_value(char digit) {
  // Convert a digit from get_all_digits() to its integer value
  if (digit >= '0' && digit <= '9') {
    return digit - '0';
  }
  if (digit >= 'a' && digit <= 'z') {
    return 10 + (digit - 'a');
  }
  return -1;
}

char to_digit(unsigned int value) {
  // Convert an integer value to a digit from get_all_digits()
  if (value >= ALL_DIGIT_COUNT) {
    debug_abort("Invalid value for to_digit()");
    return 0;
  }
  return get_all_digits()[value];
}

char *reverse(char *str) {
  // Reverse a string in place, return the pointer for convenience
  // Might be helpful if you fill your char* buffer from left to right
  const size_t length = strlen(str);
  const size_t bound = length / 2;
  for (size_t i = 0; i < bound; ++i) {
    char tmp = str[i];
    const size_t mirror = length - i - 1;
    str[i] = str[mirror];
    str[mirror] = tmp;
  }
  return str;
}

const char *drop_leading_zeros(const char *number) {
  // If the number has leading zeros, return a pointer past these zeros
  // Might be helpful to avoid computing a result with leading zeros
  if (*number == '\0') {
    return number;
  }
  while (*number == '0') {
    ++number;
  }
  if (*number == '\0') {
    --number;
  }
  return number;
}

void debug_abort(const char *debug_msg) {
  // Print a message and exit
  fprintf(stderr, debug_msg);
  exit(EXIT_FAILURE);
}
