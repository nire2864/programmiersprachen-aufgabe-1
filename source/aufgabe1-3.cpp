#include <iostream>

int main() {
    
    bool check = true;
    int i = 39;
    while (check) {
        i++;
        check = false;
        for(int mod = 1; mod < 21; ++mod) {
            int rechnung = i % mod;
            if (rechnung != 0) {
                check = true;
                break;
            }
        }
    }
    std::cout << i << " ist die kleinst mögliche Zahl, die durch die Zahlen 1 bis 20 teilbar ist. \n";
    return 0;
}