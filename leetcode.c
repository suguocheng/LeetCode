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

typedef struct LinkedList{//ok
    int val;
    struct LinkedList*next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {//ok
    MyLinkedList*head=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next=NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {//ok
    MyLinkedList*p=obj->next;
    int i=0;
    while(p!=NULL)
    {
        if(i==index)
        {
            return p->val;
        }
        else
        {
            p=p->next;
        }
        i++;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {//ok
    MyLinkedList*newhead=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newhead->val=val;
    newhead->next=obj->next;
    obj->next=newhead;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {//ok
    MyLinkedList*newtail=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newtail->val=val;
    MyLinkedList*p=obj;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    newtail->next=NULL;
    p->next=newtail;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int i=0;
    MyLinkedList*p=obj->next;
    if(index==0)
    {
        myLinkedListAddAtHead(obj,val);
        return;
    }
    while(p!=NULL)
    {
        if(i+1==index&&p->next!=NULL)
        {
            MyLinkedList*newnode=(MyLinkedList*)malloc(sizeof(MyLinkedList));
            newnode->val=val;
            newnode->next=p->next;
            p->next=newnode;
            return;
        }
        else
        {
            p=p->next;
        }
        i++;
    }
    if(i==index)
    {
        myLinkedListAddAtTail(obj,val);
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList*p=obj->next;
    int i=0;
    if(index==0)
    {
        p=obj;
        MyLinkedList*tmp=p->next;
        p->next=p->next->next;
        free(tmp);
        return;
    }
    while(p!=NULL)
    {
        if(i+1==index&&p->next!=NULL)
        {
            MyLinkedList*tmp=p->next;
            p->next=p->next->next;
            free(tmp);
            return;
        }
        else
        {
            p=p->next;
        }
        i++;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj!=NULL)
    {
        MyLinkedList*tmp=obj;
        obj=obj->next;
        free(tmp);
    }
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p=head;
    if(p==NULL)
    {
        return p;
    }
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next=NULL;
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=p->val;
    newhead->next=node;
    node->next=NULL;
    p=p->next;
    while(p!=NULL)
    {
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=p->val;
        node->next=newhead->next;
        newhead->next=node;
        p=p->next;
    }
    newhead=newhead->next;
    return newhead;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL)
    {
        return head;
    }
    struct ListNode* newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next=head;
    struct ListNode* left=newhead;
    struct ListNode* right=newhead->next;
    while(right->next)
    {
        left->next=right->next;
        right->next=right->next->next;
        left->next->next=right;
        left=right;
        if(right->next)
        right=right->next;
    }
    return newhead->next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
    int count=0;
    struct ListNode* p=head;
    while(p)
    {
        count++;
        p=p->next;
    }
    p=head;
    if(count-n==0)
    {
        struct ListNode* tem=head;
        head=head->next;
        free(tem);
    }
    else
    {
        for(int i=1;i<count-n;i++)
        {
            p=p->next;
        }
        struct ListNode* temp=p->next;
        p->next=p->next->next;
        free(temp);
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1=headA;
    struct ListNode *p2=headB;
    while(p1)
    {
        p2=headB;
        while(p2)
        {
            if(p1==p2)
            {
                return p2;
            }
            p2=p2->next;
            // if(p2==NULL&&p1->next!=NULL)
            // {
            //     p2=headB;
            // }
        }
        p1=p1->next;
    }
    return NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL)
    {
        return 0;
    }
    struct ListNode *slow=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fast=(struct ListNode *)malloc(sizeof(struct ListNode));
    slow->next=head;
    fast->next=head;
    while(slow!=fast)
    {
        slow=slow->next;
        if(fast->next!=NULL)
        {
            fast=fast->next->next;
        }
        if(fast==NULL||fast->next==NULL)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head)
    {
        return NULL;
    }
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            struct ListNode *p=fast;
            struct ListNode *q=head;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            return p;
        }
    }
    return NULL;
}




typedef struct {
    int stackin[100],stackout[100];
    int stackintop,stackouttop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue=(MyQueue *)malloc(sizeof(MyQueue));
    queue->stackintop=0;
    queue->stackouttop=0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackin[obj->stackintop]=x;
    obj->stackintop++;
}

int myQueuePop(MyQueue* obj) {
    int top;
    while(obj->stackintop>0)
    {
        obj->stackout[obj->stackouttop++]=obj->stackin[--obj->stackintop];
    }
    top=obj->stackout[--obj->stackouttop];
    while(obj->stackouttop>0)
    {
        obj->stackin[obj->stackintop++]=obj->stackout[--obj->stackouttop];
    }
    return top;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stackin[0];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->stackintop==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    obj->stackintop=0;
    obj->stackouttop=0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/




typedef struct {
    int queuein[100],queueout[100];
    int queueinfront,queueinrear;
    int queueoutfront,queueoutrear;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack=(MyStack *)malloc(sizeof(MyStack));
    stack->queueinfront=0;
    stack->queueinrear=0;
    stack->queueoutfront=0;
    stack->queueoutrear=0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queuein[obj->queueinrear++]=x;
}

int myStackPop(MyStack* obj) {
    for(int i=obj->queueinrear-1;i>=obj->queueinfront;i--)
    {
        obj->queueout[obj->queueoutrear++]=obj->queuein[i];
    }
    int top=obj->queueout[0];
    if(obj->queueoutrear==1)
    {
        obj->queuein[0]=obj->queueout[0];
        obj->queueinrear=1;
    }
    obj->queueinrear=0;
    for(int i=obj->queueoutrear-1;i>obj->queueoutfront;i--)
    {
        obj->queuein[obj->queueinrear++]=obj->queueout[i];
    }
    obj->queueoutrear=0;
    return top;
}

int myStackTop(MyStack* obj) {
    return obj->queuein[obj->queueinrear-1];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->queueinrear==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    obj->queueinfront=0;
    obj->queueinrear=1;
    obj->queueoutfront=0;
    obj->queueoutrear=1;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

typedef struct{
    char string[10000];
    int top;
}str;

bool isValid(char* s) {
    str *s2=(str*)malloc(sizeof(str));
    s2->top=0;
    int i=0;
    // if(s[i]=='}'||s[i]==']'||s[i]==')')
    // {
    //     return 0;
    // }
    while(s[i]!='\0')
    {
        if(s[i]=='{')
        {
            s2->string[s2->top]=s[i];
            s2->top++;
        }
        else if(s[i]=='[')
        {
            s2->string[s2->top]=s[i];
            s2->top++;
        }
        else if(s[i]=='(')
        {
            s2->string[s2->top]=s[i];
            s2->top++;
        }
        else if(s2->top>0&&s2->string[s2->top-1]=='{'&&s[i]=='}')
        {
            s2->top--;
        }
        else if(s2->top>0&&s2->string[s2->top-1]=='['&&s[i]==']')
        {
            s2->top--;
        }
        else if(s2->top>0&&s2->string[s2->top-1]=='('&&s[i]==')')
        {
            s2->top--;
        }
        else if(s[i]=='}'||s[i]==']'||s[i]==')')
        {
            return 0;
        }
        i++;
    }
    if(s2->top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int queue[n]; //队列
    int front = 0, rear = -1; //队首 队尾
    int left = 0, right = 0; //窗口左下标 窗口右下标
    while (right < n)//窗口右移至终点
    { 
        while (rear >= front && nums[right] > queue[rear])
        {
            rear--; //维护队列的单调性（非递增），即保证队首元素就是当前窗口的最大值
        }
        queue[++rear] = nums[right++]; //入队下一个窗口可能的最大值
        if (left + k <= right)//窗口大小大于k
        { 
            if (nums[left] == queue[front])
            {
                front++; //如果最大值已经在窗口的左边，则将它永久出队
            }
            else
            {
                nums[left] = queue[front]; //否则记录最大值进原数组中
            }
            left++; //左框右移
        }
    }
    *returnSize = n - k + 1;
    return nums; //返回原数组
}

typedef struct{
    char string[100001];
    int top;
}str;

char* removeDuplicates(char* s) {
    str *s2=(str*)malloc(sizeof(str));
    s2->top=0;
    int i=0;
    while(s[i]!='\0')
    {
        if(s2->top>0&&s[i]==s2->string[s2->top-1])
        {
            s2->top--;
        }
        else
        {
            s2->string[s2->top]=s[i];
            s2->top++;
        }
        i++;
    }
    s2->string[s2->top]='\0';
    return s2->string;
}

typedef struct{
    char *string[10000];
    int top;
}str;

int evalRPN(char** tokens, int tokensSize) {
    str* s=(str*)malloc(sizeof(str));
    for (int i=0;i<10000;i++)
    {
        s->string[i]=(char*)malloc(100);
    }
    s->top=0;
    for(int i=0;i<tokensSize;i++)
    {
        if(strcmp(tokens[i],"+")==0)
        {
            sprintf(s->string[s->top-2],"%d",atoi(s->string[s->top-2])+atoi(s->string[s->top-1]));
            s->top--;
        }
        else if(strcmp(tokens[i],"-")==0)
        {
            sprintf(s->string[s->top-2],"%d",atoi(s->string[s->top-2])-atoi(s->string[s->top-1]));
            s->top--;
        }
        else if(strcmp(tokens[i],"*")==0)
        {
            sprintf(s->string[s->top-2],"%d",atoi(s->string[s->top-2])*atoi(s->string[s->top-1]));
            s->top--;
        }
        else if(strcmp(tokens[i],"/")==0)
        {
            sprintf(s->string[s->top-2],"%d",atoi(s->string[s->top-2])/atoi(s->string[s->top-1]));
            s->top--;
        }
        else
        {
            strcpy(s->string[s->top],tokens[i]);
            s->top++;
        }
    }
    return atoi(s->string[s->top-1]);
}

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> n(2);
        sort(nums.begin(),nums.end());
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            if(curr==prev)
            {
                n[0]=prev;
            }
            else if(curr-prev>1)
            {
                n[1]=prev+1;
            }
            prev=curr;
        }
        if(nums[nums.size()-1]!=nums.size())
        {
            n[1]=nums.size();
        }
        return n;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l3=(struct ListNode *)malloc(sizeof(struct ListNode));
    l3->val=0;
    struct ListNode *p=l3;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
    return l3->next;
}

int reverse(int x){
    long long n=0;
    while(x!=0)
    {
        n=n*10+x%10;
        x/=10;
    }
    return n > INT_MAX || n < INT_MIN ? 0 : n;
}

class DiningPhilosophers {
    mutex mtx;
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex> lock(mtx);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head=(struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* p=head;
    struct ListNode* p1=list1;
    struct ListNode* p2=list2;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->val<p2->val)
        {
            p->next=p1;
            p1=p1->next;
        }
        else
        {
            p->next=p2;
            p2=p2->next;
        }
        p=p->next;
    }
    p->next = p1 != NULL ? p1 : p2;
    struct ListNode* tem=head;
    head=head->next;
    free(tem);
    return head;
}

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=5;
        for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
}; 

class Solution {
public:
    string reverseWords(string s) {
        int fast=s.length()-1;
        int slow;
        std::string str;
        while(fast>=0)
        {
            while(fast>=0&&s[fast]==' ')
            {
                fast--;
            }
            if(fast<0)
            {
                break;
            }
            slow=fast;
            while(fast>=0&&s[fast]!=' ')
            {
                fast--;
            }
            if(!str.empty())
            {
                str+= ' ';
            }
            str+=s.substr(fast+1,slow-fast);
        }
        return str;    
    }
};

class Foo {
public:
    mutex mtx1,mtx2,mtx3;
    std::condition_variable cv1,cv2;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mtx1);
        printFirst();
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx2);
        cv1.wait(lock);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
       std::unique_lock<std::mutex> lock(mtx3);
        cv2.wait(lock);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

func numOfSubarrays(arr []int, k int, threshold int) int {
    n := 0
    m := 0
    for i,right := range arr {
        m += right
        if i < k-1 {
            continue
        }
        if float64(m)/float64(k) >= float64(threshold) {
            n++
        }
        left := arr[i-k+1]
        m -= left
    }
    return n
}