#include <stdio.h>

void towerOfHanoiMoves(int n, char source, char destination, char auxiliary, int* total_moves) {
    if (n == 1) {
        (*total_moves)++;
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    towerOfHanoiMoves(n - 1, source, auxiliary, destination, total_moves);
    
    (*total_moves)++;
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    towerOfHanoiMoves(n - 1, auxiliary, destination, source, total_moves);
}

int main() {
    int n;
    scanf("%d", &n);
    int total_moves = 0;
    
    towerOfHanoiMoves(n, 'A', 'C', 'B', &total_moves);
    
    printf("Total number of times the disk is moved: %d\n", total_moves);

    return 0;
}

