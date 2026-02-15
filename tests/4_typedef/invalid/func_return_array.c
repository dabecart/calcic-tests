// Error: function cannot return array type
typedef int arr[5];
typedef arr func(void); 
int main(void) { return 0; }