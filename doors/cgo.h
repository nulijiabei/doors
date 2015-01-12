#include <string>

using namespace std;

extern "C" inline void input(void *, int) { /* CGO */ }

extern "C" inline void * output() { /* CGO */ }
