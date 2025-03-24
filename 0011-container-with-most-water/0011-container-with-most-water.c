int maxArea(int *height, int heightSize) {
    int maximumCapacity = 0;

    int startIndex = 0;
    int endIndex = heightSize - 1;
    while (startIndex < endIndex) {
        int width = endIndex - startIndex;
        int currentHeight = height[startIndex] < height[endIndex]
                                ? height[startIndex]
                                : height[endIndex];
        if (width * currentHeight > maximumCapacity) {
            // If the current area is larger than the maximum capacity, update
            // the maximum capacity
            maximumCapacity = width * currentHeight;
        }

        // Update the start and end index
        // Drain the water from the lower side
        if (height[startIndex] < height[endIndex]) {
            startIndex++;
        } else {
            endIndex--;
        }
    }

    return maximumCapacity;
}
