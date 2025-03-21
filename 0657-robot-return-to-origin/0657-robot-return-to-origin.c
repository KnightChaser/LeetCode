struct XYCoordinate {
    int x;
    int y;
};

bool judgeCircle(char* moves) {
    struct XYCoordinate robotPosition = {0, 0};

    // Move the robot according to the moves
    for (int i = 0; moves[i] != '\0'; i++) {
        switch (moves[i]) {
            case 'U':
                robotPosition.y++;
                break;
            case 'D':
                robotPosition.y--;
                break;
            case 'L':
                robotPosition.x--;
                break;
            case 'R':
                robotPosition.x++;
                break;
            default:
                break;
        }
    }

    // If the robot is back to the origin, return true
    if (robotPosition.x == 0 && robotPosition.y == 0) {
        return true;
    } else {
        return false;
    }
}
