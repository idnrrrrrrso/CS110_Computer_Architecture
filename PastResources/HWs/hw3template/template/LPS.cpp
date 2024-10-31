/*
输入一个字符串s，返回最长回文串的长度
使用动态规划
dp[i][j]: 从字符i到字符j是否是回文。包括ij（存储类型为bool, 初始值if i=j, true, else false)
dp[i][j] = true ,if s[i]=s[j] and dp[i+1][j-1] = true

*/
