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
int mySqrt(int x) {
    long long i=1;
    while(i*i<=x){
        i++;
    }
    return i-1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    digits[digitsSize-1]+=1;
    for(int i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]==10)
        {
            digits[i]%=10;
            if(i>0)
            digits[i-1]+=1;
        }
    }
    int *n;
    if(digits[0]==0)
    {
        n=(int*)malloc((digitsSize+1)*sizeof(int));
        n[0]=1;
        for(int i=0;i<digitsSize;i++)
        {
            n[i+1]=digits[i];
        }
        *returnSize=digitsSize+1;
    }
    else
    {
        n=(int*)malloc(digitsSize*sizeof(int));
        for(int i=0;i<digitsSize;i++)
        {
            n[i]=digits[i];
        }
        *returnSize=digitsSize;
    }
    return n;
}
int climbStairs(int n) {
    int a1=1,a2=2,a3=1;
    if(n==2)
    {
        a3=2;
    }
    for(int i=2;i<n;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    return a3;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int a=0;
    for(int i=m;i<nums1Size;i++)
    {
        nums1[i]=nums2[a];
        a++;
    }
    for(int i=0;i<nums1Size-1;i++)
    {
        int count=1;
        for(int j=0;j<nums1Size-1;j++)
        {
            if(nums1[j]>nums1[j+1])
            {
                int temp=nums1[j];
                nums1[j]=nums1[j+1];
                nums1[j+1]=temp;
                count=0;
            }
        }
        if(count==1)
        {
            break;
        }
    }
}
int majorityElement(int* nums, int numsSize) {
    int i;
    for(i=0;i<numsSize-1;i++)
    {
        int count=0;
        for(int j=0;j<numsSize-1-i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
                count=1;
            }    
        }
        if(count==0)
        {
            break;
        }
    }
    return nums[numsSize/2];
}
int titleToNumber(char* columnTitle) {
    int a=0;
    for(int i=0;i<strlen(columnTitle);i++)
    {
        a+=(columnTitle[i]-64)*pow(26,strlen(columnTitle)-i-1);
    }
    return a;
}