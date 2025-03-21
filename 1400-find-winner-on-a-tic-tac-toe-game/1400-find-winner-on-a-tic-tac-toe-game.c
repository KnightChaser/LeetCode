char* checkTictactoeWinner(char** map) {
    // Check who wins the game
    // - check rows
    for (int row = 0; row < 3; row++) {
        if (map[row][0] == map[row][1] && map[row][1] == map[row][2] &&
            map[row][0] != ' ') {
            return (map[row][0] == 'X') ? "A" : "B";
        }
    }

    // - check columns
    for (int col = 0; col < 3; col++) {
        if (map[0][col] == map[1][col] && map[1][col] == map[2][col] &&
            map[0][col] != ' ') {
            return (map[0][col] == 'X') ? "A" : "B";
        }
    }

    // - check diagonals (left(up) to right(down) and right(up) to left(down))
    if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] != ' ') {
        return (map[0][0] == 'X') ? "A" : "B";
    }
    if (map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][2] != ' ') {
        return (map[0][2] == 'X') ? "A" : "B";
    }

    // At this point, no one wins the game or the game is not finished
    int turnCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If there is a mark from either player A or B, increment the turn count
            if (map[i][j] != ' ') {
                turnCount++;
            }
        }
    }
    return (turnCount == 9) ? "Draw" : "Pending";
}

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    // Initialize the map for tic-tac-toe (3 * 3)
    char** map = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        map[i] = (char*)malloc(sizeof(char) * 3);
        memset(map[i], ' ', sizeof(char) * 3);
    }

    // Player A and B play the game
    for (int i = 0; i < movesSize; i++) {
        // Since A and B alternate,
        // we can use i % 2 to determine the player
        int x = moves[i][0];
        int y = moves[i][1];
        map[x][y] = (i % 2 == 0) ? 'X' : 'O';
    }

    // Check who wins the game
    return checkTictactoeWinner(map);
}

