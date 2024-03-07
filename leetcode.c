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
int hammingWeight(uint32_t n) {
    int count=0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 8 * sizeof(uint32_t); i++) {
        ans = (ans << 1) + (n & 1);
        n = n >> 1;
    }
    return ans;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **a = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        a[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
    }

    a[0][0] = 1;

    for (int i = 1; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }

    *returnSize = numRows;

    return a;
}
int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int time=0;
    if(timeSeriesSize==1)
    {
        time=duration;
    }
    else
    {
        for(int i=0;i<timeSeriesSize-1;i++)
        {
            if(timeSeries[i+1]-timeSeries[i]+1<=duration)
            {
                time+=timeSeries[i+1]-timeSeries[i];
            }
            else
            {
                time+=duration;
            }
            if(i+1==timeSeriesSize-1)
            {
                time+=duration;
            }
        }
    }
    return time;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (NULL != head && head->val == val) {
        head = head->next;
    }
    if (NULL == head) {
        return head;
    }
    struct ListNode* q=head;
    while(q->next!=NULL)
    {
        if(q->next->val==val)
        {
            q->next=q->next->next;
        }
        else
        {
            q=q->next;
        }
    }
    return head;
}
typedef struct LinkedList{
    int val;
    struct LinkedList*next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList*head=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next=NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList*p=obj->next;
    int i=0;
    while(p!=NULL)
    {
        i++;
        if(i==index)
        {
            return p->val;
        }
        else
        {
            p=p->next;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList*newhead=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newhead->val=val;
    newhead->next=obj->next;
    obj->next=newhead;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList*newtail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newtail->val=val;
    MyLinkedList*p=obj;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newtail;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
}

void myLinkedListFree(MyLinkedList* obj) {
    
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/