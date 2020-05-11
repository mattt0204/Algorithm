#include "main.h"

int main(void) {

  unpacked_float A;
  unpacked_float B;
  unpacked_float result;

  // 파일 포인터
  FILE *fp_read = NULL;
  FILE *fp_write = NULL;

  unsigned int A_sign, A_exponent, A_mantissa;
  unsigned int B_sign, B_exponent, B_mantissa;
  // 파일 열기
  fp_read = fopen("input.dat", "r");
  if (fp_read == NULL) {
    printf("File open Fail\n");
  } else {
    while (!feof(fp_read)) {
      fscanf(fp_read, "%d, %d, %d, %d, %d, %d,\n", &A_sign, &A_exponent,
             &A_mantissa, &B_sign, &B_exponent, &B_mantissa);
      A.bfloat16.sign = A_sign;
      A.bfloat16.exponent = A_exponent;
      A.bfloat16.mantissa = A_mantissa;

      B.bfloat16.sign = B_sign;
      B.bfloat16.exponent = B_exponent;
      B.bfloat16.mantissa = B_mantissa;

      A.bfloat16.truncate_mantissa = 0;
      B.bfloat16.truncate_mantissa = 0;

      // result = bfloat16_mul(A,B);
      result = bfloat16_add(A, B);

      // printf("A\n");
      // print_bfloat16(A);
      // printf("B\n");
      // print_bfloat16(B);
      // printf("result\n");
      print_bfloat16(result);
    }
  }

  fclose(fp_read);

  return 0;
}
