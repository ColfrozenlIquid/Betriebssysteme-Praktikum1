#include <iostream>
#include <sys/resource.h>

#define INT_ARRAY_SIZE 100000
#define RECURSIVE_ITERATIONS 100000

int* funcMem();
void funcRec(int depth);

int main() {
    int* int_array = funcMem();
    funcRec(RECURSIVE_ITERATIONS);
    return 0;
}

int* funcMem() {
    int* int_array = new int[INT_ARRAY_SIZE];
    int count = 0;
    for (int i = 0; i < INT_ARRAY_SIZE; i++) {
        int_array[i] = count;
        count++;
    }
    return int_array;
}

void funcRec(int depth) {
    if (depth == 0) {
        std::cout << "Done after " << RECURSIVE_ITERATIONS << " iterations." << std::endl;
    }
    else {
        funcRec(depth - 1);
    }
}

void getSystemInfo() {
    rusage* usage;
    getrusage(RUSAGE_SELF, usage);
    std::cout << "user cpu time used: " << usage->ru_utime << std::endl;
}