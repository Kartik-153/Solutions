class Solution:
    def LCS(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        dp = [[""] * (m + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1]
                else:
                    dp[i][j] = (
                        dp[i - 1][j]
                        if len(dp[i - 1][j]) > len(dp[i][j - 1])
                        else dp[i][j - 1]
                    )

        return dp[n][m]

    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        lcs = self.LCS(str1, str2)
        i, j = 0, 0
        result = []

        for c in lcs:
            while i < len(str1) and str1[i] != c:
                result.append(str1[i])
                i += 1
            while j < len(str2) and str2[j] != c:
                result.append(str2[j])
                j += 1

            result.append(c)
            i += 1
            j += 1

        result.append(str1[i:])
        result.append(str2[j:])

        return "".join(result)
