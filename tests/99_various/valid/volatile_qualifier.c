// Exit code: 0

// This test is not automatic: it will surely compile, but you have to manually check the generated
// assembly code to verify that volatile related instructions do not get trimmed from the final 
// program. 
volatile int externalV = 0;

int nonVolatileVariable() {
    // This all will be reduced to return 30;
    int x = 10;
    x = 20;
    x = 30;
    return x;
}

int volatileVariable() {
    // Writings to x should not be optimized.
    volatile int x = 10;
    x = 20;
    x = 30;

    {
        // Even readings through x.
        int y = x;
        // Not optimized.
        x = y;

        // Operations done on z will be removed, but his initialization shall remain in the final 
        // program as we're reading from a volatile variable.
        int z = x;
        // These are dead stores, so they will be removed.
        z = 10;
        z = 20;
        y = z;
    }

    // Even this one, shouldn't be optimized.
    x = x;

    // Test if the value gets copy propagated.
    {
        x = 35;
        // This shouldn't be converted into x = 70 through constant folding.
        int y = x;
        int z = y;
        x = y + z;
    } 

    // Now do something similar but with a global volatile variable.
    // z is a dead store, but its initialization must be kept, as it uses an external variable.
    int z = externalV;
    // This next will be deleted.
    z += 3;

    // Each instruction must be kept.
    externalV = 10;
    externalV = 20;
    externalV++;

    return 0;
}

int main() {
    return 0;
}
