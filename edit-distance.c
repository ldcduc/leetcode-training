/* Problem url: https://leetcode.com/problems/edit-distance
 * Code by: ldcduc
 * */
int min(int first, int second) {
    return (first < second) ? first : second;
}
int minDistance(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);

    int ** dp = malloc((len1 + 1) * sizeof(int *));
    for (int i=0; i<=len1; ++i) {
        dp[i] = malloc((len2 + 1) * sizeof(int));
    }

    dp[0][0] = 0;
    for (int i=1; i<=len1; ++i) {
        dp[i][0] = i;
    }
    for (int j=1; j<=len2; ++j) {
        dp[0][j] = j;
    }
    for (int i=1; i<=len1; ++i) {
        for (int j=1; j<=len2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    int result = dp[len1][len2];
    for (int i=0; i<=len1; ++i) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
