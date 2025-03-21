struct Robot {
    int x;
    int y;
    char direction;
};

bool isRobotBounded(char* instructions) {
    struct Robot robot = {
        .x = 0,
        .y = 0,
        .direction = 'N'
    };

    // Iterate over the instructions
    for (int i = 0; i < strlen(instructions); i++) {
        char c = instructions[i];
        if (c == 'G') {
            // Go forward (while maintaining direction)
            if (robot.direction == 'N') {
                robot.y++;
            } else if (robot.direction == 'E') {
                robot.x++;
            } else if (robot.direction == 'S') {
                robot.y--;
            } else if (robot.direction == 'W') {
                robot.x--;
            }
        } else if (c == 'L') {
            // Turn 90 degrees to the left (anti-clockwise)
            if (robot.direction == 'N') {
                robot.direction = 'W';
            } else if (robot.direction == 'E') {
                robot.direction = 'N';
            } else if (robot.direction == 'S') {
                robot.direction = 'E';
            } else if (robot.direction == 'W') {
                robot.direction = 'S';
            }
        } else if (c == 'R') {
            // Turn 90 degrees to the right (clockwise)
            if (robot.direction == 'N') {
                robot.direction = 'E';
            } else if (robot.direction == 'E') {
                robot.direction = 'S';
            } else if (robot.direction == 'S') {
                robot.direction = 'W';
            } else if (robot.direction == 'W') {
                robot.direction = 'N';
            }
        }
        printf("Processing instruction: %c -->", c);
        printf("Robot position: (%d, %d), Direction: %c\n", robot.x, robot.y, robot.direction);
    }

    // Now check if the robot is back at the starting point
    // And, also to check the robot's trajectory so far is forming a circle.
    if ((robot.x == 0 && robot.y == 0) || (robot.direction != 'N')) {
        return true;
    } else {
        return false;
    }
}
