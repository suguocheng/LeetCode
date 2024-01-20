int removeElement(int* nums, int numsSize, int val)
{
    int slow=0;
    for(int fast=0;fast<numsSize;fast++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;
        }
    }
    return slow;
}
int searchInsert(int* nums, int numsSize, int target) {
    int first=0,last=numsSize-1,middle=0;
    while(first<=last)
    {
        middle=(first+last)/2;
        if(nums[middle]>target)
        {
            last=middle-1;
        }
        else if(nums[middle]<target)
        {
            first=middle+1;
        }
        else
        {
            return middle;
        }
    }
    return first;
}
int removeElement(int* nums, int numsSize, int val)
{
    int slow=0;
    for(int fast=0;fast<numsSize;fast++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;
        }
    }
    return slow;
}
int lengthOfLastWord(char* s) {
    int n=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]!=' ')
        {
            n++;
        }
        else if(s[i]==' '&&n>0)
        {
            return n;
        }
    }
    return n;
}