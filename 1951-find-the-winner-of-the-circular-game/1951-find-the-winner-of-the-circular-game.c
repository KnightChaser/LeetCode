// Refer to Josephus problem
int josephus0(int n, int k) {
    // Base case: if there's only one person left,
    //            they are the winner
    if (n == 1) {
        return 0;
    }
    return (josephus0(n - 1, k) + k) % n;
}

// public 1âbased API
int findTheWinner(int n, int k) {
    // +1 to convert from 0-based to 1-based index
    return josephus0(n, k) + 1;
}
