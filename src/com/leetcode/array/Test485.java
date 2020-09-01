package com.leetcode.array;

import jdk.management.resource.internal.inst.SocketOutputStreamRMHooks;
import org.junit.Test;

import java.util.Arrays;

/**
 * Description:
 *给定一个二进制数组， 计算其中最大连续1的个数。
 *
 * 示例 1:
 *
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 *
 * 注意：
 *     输入的数组只包含 0 和1。
 *     输入数组的长度是正整数，且不超过 10,000。
 * @author abliger
 * @date 2020/9/1
 */
public class Test485 {
}
class Solution1 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count=0;
        int cache=0;
        for(int num:nums){
            ++cache;
            if (num==0){cache=0;}
            if(count<=cache){
                count=cache;
            }
            
            
        }
        return count;
    }
}
class Solution2 {
    public int findMaxConsecutiveOnes(int[] nums) {
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<nums.length;i++){
            sb.append(nums[i]);
        }
        String[] split = sb.toString().split("0");
        int count=0;
        for (String s : split) {
            if (s.length()>count){
                count=s.length();
            }
        }
        return count;
    }
}