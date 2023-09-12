#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int p;
    p = fork();
    if (p == 0){
        printf("FILHO\n");
    }
    else {
        printf("PAI\n");
    }
}