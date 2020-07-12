## 题序

- <a href="#01">01~10</a>
- <a href="#11">11~20</a>
- <a href="#21">21~30</a>
- <a href="#31">31~40</a>
- <a href="#41">41~50</a>
- <a href="#51">51~60</a>

## 01<a id="01"> </a>

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#### 思路
1. 从右上角开始寻找（重要）
2. 大于目标值就向下，小于目标值就向左寻找  

```c++
bool Find(int target, vector<vector<int>> array) {
    if(array.empty())
        return false;
    int rows = array.size(), cols = array[0].size();
    int i = 0, j = cols - 1;
    while(i < rows && j >= 0){
        int val = array[i][j];
        if(val == target)
            return true;
        else if(val < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}
```
## 02
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
#### 思路
1. 测量得到新数的长度
2. 申请新的空间，将原数组重后往前赋值（重要），遇到空格时进行替换

```c++
	void replaceSpace(char *str,int length) {
        if(str == NULL||length<=0)
            return;
        int len = 0;
        int count = 0;
        int i=0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
                count++;
            len++;
            i++;
        }
         
        int newlen=len+count*2;
        if(length<newlen)
            return;
        int a=len;
        int b=newlen;
        while(a>=0&&b>=0)
        {
            if(str[a]==' ')
            {
                str[b--]='0';
                str[b--]='2';
                str[b--]='%';
            }
            else{
                str[b]=str[a];
                b--;
            }
            a--;
        }
        return;
	}
```
## 03
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
#### 思路
主要使用栈来操作
```c++
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL)
            return res;
        stack<int> s;
        while(head != NULL){
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
```
## 04 
#### 思路
```c++

```
## 05 
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#### 思路
1. 入栈，直接stack1入栈即可
2. 出栈，先将stack1的值放入stack2中，返回stack的top()
3. 最后再将stack2的值放回stack1中。

```c++
void push(int node) {
    stack1.push(node);
}

int pop() {
    while(!stack1.empty()){
        stack2.push(stack1.top());
        stack1.pop();
    }
    int res = stack2.top();
    stack2.pop();
    while(!stack2.empty()){
        stack1.push(stack2.top());
        stack2.pop();
    }
    return res;
}
```
## 06 
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
#### 思路
1. 二分法进行查找
2. 如果mid值大于end值，则最小值位于右区间
3. 如果Mid值等于end值，则需要按位查找， {1,0,1,1,1,1,1};
4. 其它，则end = mid;

```c++
int minNumberInRotateArray(vector<int> rotateArray) {
     if(rotateArray.empty())
        return -1;
    int start = 0, end = rotateArray.size() - 1;
    while(start < end){
        int mid = (start + end) / 2;
        if(rotateArray[mid] > rotateArray[end]){
            start = mid + 1;
        }else if(rotateArray[mid] == rotateArray[end]){
            end = end - 1;
        }else
            end = mid;
    }
    return rotateArray[start];
}
```
## 07 
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
#### 思路
```c++
int Fibonacci(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    int i = 3;
    int val1 = 1, val2 = 1, sum = 0;
    while(i <= n){
        sum = val1 + val2;
        val1 = val2;
        val2 = sum;
        i++;
    }
    return sum;
}
```
## 08 
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
#### 思路
简单一维动态规划，res[i] = res[i-1] + res[i-2];
```c++
int jumpFloor(int number) {
     if(number == 1)
        return 1;
    if(number == 2)
        return 2;
    int* res = new int[number + 1]{};
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i <= number; i++){
        res[i] = res[i-1] + res[i-2];
    }
    return res[number];
}
```
## 09
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
#### 思路
简单动态规划 res[i] = 1 + res[i-1] + res[i-2] + ... + res[0];
```c++
int jumpFloorII(int number) {
    if(number == 1)
        return  1;
    if(number == 2)
        return  2;
    int *res = new int[number + 1]{};
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i <= number; i++){
        res[i] += 1;
        for(int j = 0; j < i; j++)
            res[i] += res[j];
    }
    return res[number];
}
```
## 10 
我们可以用2X1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2x1的小矩形无重叠地覆盖一个2xn的大矩形，总共有多少种方法？
#### 思路
Fibonnaci数据列，val3 = val1 + val2;
```c++
int rectCover(int number) {
    if(number == 1)
        return 1;
    if(number == 2)
        return 2;
    int val1 = 1, val2 = 2, res = 0;
    for(int i = 3; i <= number; i++){
        res = val1 + val2;
        val1 = val2;
        val2 = res;
    }
    return res;
}
```


## 11<a id="11"> </a>

#### 思路
```c++

```
## 12
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0
#### 思路
1. 暴力求解，直接遍历，会超出时间复杂度
2. 应从， 2的8次方 等于 2的4次方相乘，2的4次方等于2的2次方相乘考虑（重要）
3. 除此之外还要考虑指数为负数，和指数为奇数的情况

```c++
double Power(double base, int exponent) {
    if(exponent == 0)
        return 1;
    double res = 1;
    int i = exponent < 0 ? -exponent : exponent;
    while(i > 1){
        if (i % 2 == 1) {
            res = res * base;
            i--;
        }else {
            base = base * base;
            i /= 2;
        }
    }
    return exponent > 0 ? res * base : 1 / (res * base);
}
```
## 13 
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#### 思路

1. 从后往前遍历，找到偶数往后放，数组位置进行移动

```c++
void reOrderArray(vector<int> &array) {
    if(array.empty()){
        return ;
    }
    int len = array.size() - 1;
    for(int i = array.size() - 1; i >= 0; i--){
        if(array[i] % 2 == 0){
            int temp = array[i];
            for(int k = i; k < len; k++){
                array[k] = array[k+1];
            }
            array[len] = temp;
            len--;
        }
    }
}
```
## 14 

输入一个链表，输出该链表中倒数第k个结点。

#### 思路

1. 快慢指针即可

```c++
static ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == NULL)
        return NULL;
    ListNode *p = pListHead;
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    if(len < k)	//判断长度是否大于K
        return NULL;
    ListNode *slow = pListHead, *fast = pListHead;	//使用快慢指针进行操作
    while(k > 0){
        fast = fast->next;
        k--;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
```
## 15 
输入一个链表，反转链表后，输出新链表的表头。

#### 思路

1. 借助额外空间大小为N的栈进行操作

```c++
static ListNode* ReverseList(ListNode* pHead) {
    if(pHead == NULL)
        return NULL;
    stack<int> s;
    ListNode *p = pHead;
    while(p != NULL){
        s.push(p->val);
        p = p->next;
    }
    ListNode *pre_head = new ListNode(0);
    p = pre_head;
    while(!s.empty()){
        p->next = new ListNode(s.top());
        s.pop();
        p = p->next;
    }
    return pre_head->next;
}
```
## 16
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#### 思路

1. 直接比较后进行合并
2. 还需要查看链表1或链表2是否没有加入完，直接加入到后面部分

```c++
static ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;
    ListNode *new_head = new ListNode(0);
    ListNode *p = new_head;
    while(pHead1 != NULL && pHead2 != NULL) {
        if(pHead1->val <= pHead2->val){
            p->next = new ListNode(pHead1->val);
            pHead1 = pHead1->next;
        }else{
            p->next = new ListNode(pHead2->val);
            pHead2 = pHead2->next;
        }
        p = p->next;
    }
    while(pHead1 != NULL){
        p->next = new ListNode(pHead1->val);
        pHead1 = pHead1->next;
        p = p->next;
    }
    while(pHead2 != NULL){
        p->next = new ListNode(pHead2->val);
        pHead2 = pHead2->next;
        p = p->next;
    }
    return new_head->next;
}
```
## 17 
#### 思路
```c++

```
## 18

#### 思路

```c++

```

## 19

#### 思路

```c++

```

## 20

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

#### 思路

1. 使用两个栈用一个栈来保存当前的小的值
2. 当两个栈，栈顶的值相同时，需要同时出栈

```c++
stack<int> s1;
stack<int> s2;//保存小值
void push(int value) {
    s1.push(value);
    if(s2.empty()){
        s2.push(value);
    }else{
        if(value <= s2.top()){
            s2.push(value);
        }
    }
}
void pop() {
    if(s1.top() == s2.top()){
        s2.pop();
    }
    s1.pop();
}
int top() {
    return s1.top();
}
int min() {
    return s2.top();
}
```

## 21<a id="21"> </a>

#### 思路

```c++

```

## 22

#### 思路

```c++

```

## 23

#### 思路

```c++

```

## 24

#### 思路

```c++

```

## 25

#### 思路

```c++

```

## 26

#### 思路

```c++

```

## 27

#### 思路

```c++

```

## 28

#### 思路

```c++

```

## 29

#### 思路

```c++

```

## 30

#### 思路

```c++

```

## 31<a id="31"> </a>

#### 思路

```c++

```

## 32

#### 思路

```c++

```

## 33

#### 思路

```c++

```

## 34

#### 思路

```c++

```

## 35

#### 思路

```c++

```

## 36

#### 思路

```c++

```

## 37

#### 思路

```c++

```

## 38

#### 思路

```c++

```

## 39

#### 思路

```c++

```

## 40

#### 思路

```c++

```

## 41<a id="41"> </a>

#### 思路

```c++

```



