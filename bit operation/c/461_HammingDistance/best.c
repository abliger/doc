/*
 * @Author: abliger
 * @Date: 2022-06-16 23:36:20
 * @LastEditTime: 2022-06-16 23:37:33
 * @Description:
 */
int hammingDistance(int x, int y)
{
    int n = 0, a = x ^ y;
    for (int i = 0; i < 31; i++)
    {
        n += (a >> i) & 1;
    }
    return n;
}