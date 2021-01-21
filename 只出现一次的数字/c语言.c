/*解题思路：采用异或。数组之间相邻两个元素之间进行异或运算，就可以得到非重复数字*/

/*只用循环一次，所以该算法的时间复杂度为O(n)，另外，也没有申请额外的空间*/

int singleNumber(int* nums, int numsSize)
{
    int i=0;
    int result=0;
    for(i=0;i<numsSize;i++)
    {
        result=result^nums[i];
    }
    return result;
}
