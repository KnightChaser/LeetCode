int largestAltitude(int *gain, int gainSize) {
    // Initialize the highest altitude to the first altitude
    int heighestAltitude = gain[0];

    for (int i = 1; i < gainSize; i++) {
        gain[i] += gain[i - 1];
        if (gain[i] > heighestAltitude) {
            // If the current altitude is higher than the highest altitude,
            // update the highest altitude
            heighestAltitude = gain[i];
        }
    }

    // At least the altitude is 0
    return heighestAltitude > 0 ? heighestAltitude : 0;
}
