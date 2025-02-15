class Solution {
public:
    bool canPartition(const string &numStr, int target, int index = 0, int currentSum = 0) {
    if (index == numStr.size()) {
        return currentSum == target;
    }
    
    for (int i = index; i < numStr.size(); ++i) {
        int part = stoi(numStr.substr(index, i - index + 1));
        if (canPartition(numStr, target, i + 1, currentSum + part)) {
            return true;
        }
    }
    
    return false;
}
    int punishmentNumber(int n) {
        int totalSum = 0;
    
    for (int i = 1; i <= n; ++i) {
        string squareStr = to_string(i * i);
        if (canPartition(squareStr, i)) {
            totalSum += i * i;
        }
    }
    
    return totalSum;
    }
};