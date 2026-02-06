/* Error: Invalid type argument of -> (have 'float *') */
int main() {
    float f = 1.0f;
    float *p = &f;
    p->x = 2; 
    return 0;
}