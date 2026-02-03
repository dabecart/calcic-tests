/* Error: Invalid type argument of -> (have 'float *') */
void test() {
    float f = 1.0f;
    float *p = &f;
    p->x = 2; 
}