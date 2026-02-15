// Error: User requested exclusion of long long (Constraint for this test suite)
// If compiler supports C99 it might pass, but we treat it as unwanted.
typedef long long int LL; 
int main(void) { return 0; }