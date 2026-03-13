int ret_1(void) { return 1; }
int main(void) {
    void *vp = (void*)ret_1;
    vp();
    return 0;
}
