/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.



Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1


Constraints:

0 <= x, y <= 2^31 - 1
 */
/*
 * @lc app=leetcode.cn id=461 lang=c
 *
 * [461] 汉明距离
 */
// @lc code=start
int hammingDistance(int x, int y)
{
    int a = x ^ y;
    int t = 1, n = 0;
    for (int i = 0; i < 31; i++)
    {
        if (a & t == 1)
            n += 1;
        a >>= 1;
    }
    return n;
}
// @lc code=end