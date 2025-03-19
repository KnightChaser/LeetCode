int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maximumWealth = 0;
    for (int customerIndex = 0; customerIndex < accountsSize; customerIndex++) {
        int currentCustomerWealth = 0;
        for (int wealthIndex = 0; wealthIndex < *accountsColSize; wealthIndex++) {
            currentCustomerWealth += accounts[customerIndex][wealthIndex];
        }
        if (currentCustomerWealth > maximumWealth) {
            maximumWealth = currentCustomerWealth;
        }
    }

    return maximumWealth;
}