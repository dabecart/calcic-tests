// Exit code: 0
// Using tagless enums in switch statements and arithmetic.
typedef enum {
    STATE_START = 0,
    STATE_RUN = 10,
    STATE_STOP = 20
} State;

int main(void) {
    State s = STATE_RUN;
    int res = 0;

    switch(s) {
        case STATE_START: res = 1; break;
        case STATE_RUN:   res = 2; break;
        case STATE_STOP:  res = 3; break;
        default: res = 4;
    }

    if (res != 2) return 1;

    /* Enum arithmetic */
    if ((s + 10) != STATE_STOP) return 2;

    return 0;
}
