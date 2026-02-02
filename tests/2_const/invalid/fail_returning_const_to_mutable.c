const int* get_internal_buffer();

void hack() {
    int *my_ptr = get_internal_buffer(); /* ERROR: Assignment discards 'const' qualifier */
}