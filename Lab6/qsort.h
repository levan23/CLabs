#define LEN 20

typedef struct product
{
    double price;
    char name[LEN];
} product;

float Add(float x, float y);
float Subtract(float x, float y);
float Multiply(float x, float y);
float Divide(float x, float y);
float Exponent(float x, int y);
int ComparFuncInt(const void *x, const void *y);
int ComparFuncFloat(const void *x, const void *y);
int ComparFuncStruct(const void *x, const void *y);
