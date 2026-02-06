// Exit code: 0
#include <limits.h>

enum TestBound {
    MAX_VAL = INT_MAX,
    MIN_VAL = INT_MIN,
    OVERFLOW_VAL = INT_MAX + 1, // This should trigger a compiler warning
    UNDERFLOW_VAL = INT_MIN - 1
};

int main() {
    int maxVal = INT_MAX;
    int minVal = INT_MIN;
    int maxValOff = INT_MAX + 1;
    int minValOff = INT_MIN - 1;

    if(MAX_VAL != maxVal) return 1;
    if(MIN_VAL != minVal) return 2;
    if(OVERFLOW_VAL != maxValOff) return 3;
    if(UNDERFLOW_VAL != (int) minValOff) return 4;

    return 0;
}