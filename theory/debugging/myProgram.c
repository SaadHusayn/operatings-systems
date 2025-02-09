#include <stdio.h>

int main() {
    int i = 0;
    int x=9;
    while (i < 5) {
        if(x<8) i++;
        // Missing increment of 'i'
    }
    return 0;
}
