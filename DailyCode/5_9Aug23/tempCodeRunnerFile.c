void printED(char arrow[][20], int i, int j) {

        if (arrow[i][j] == 'I') {
            printED(arrow, i, j - 1);
            printf("Insert %c: %s -> %s\n", y[j - 1], x, y);
        } else if (arrow[i][j] == 'D') {
            printED(arrow, i - 1, j);
            printf("Delete %c: %s -> %s\n", x[i - 1], x, y);
        } else if (arrow[i][j] == 'S') {
            printED(arrow, i - 1, j - 1);
            printf("Replace %c by %c: %s -> %s\n", x[i - 1], y[j - 1], x, y);
        } else if (arrow[i][j] == 'N') {
            printED(arrow, i - 1, j - 1);
        }
        if (i == 0 || j == 0) {
        return;
    } 
    
}