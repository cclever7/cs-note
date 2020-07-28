<center><font size = 45>SwordOffer</font></center>

## 题序

- [01~10](#01)
- [11~20](#11)
- [21~30](#21)
- [31~40](#31)
- [41~50](#41)
- [51~60](#51)
- [61~67](#61)

## 01

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


## 11

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

## 21

栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

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

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#### 思路

```c++

```

## 29

最小的K个数

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

#### 思路

1. 方法一：排序后直接遍历K个数
2. 方法二：堆排序，交换过程中直接可以取得K个最小值

```c++

```

## 30

#### 思路

```c++

```

## 31

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

两个链表的第一个公共节点

输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

#### 思路

1. 使用hash表找到第一个重复的
2. 可以同时求得二者的长度差K，使长链表先往前遍历K个结点，之后两链表同时前进行，即可得到相同的节点

```c++
//方法一
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(pHead2 == NULL || pHead1 == NULL)
        return NULL;
    map<ListNode*, int> *m = new map<ListNode*, int>();
    while(pHead1 != NULL){
        m->insert(pair<ListNode*, int>(pHead1, 1));
        pHead1 = pHead1->next;
    }
    while(pHead2 != NULL){
        if(m->find(pHead2) != m->end()){
            return pHead2;
        }
        pHead2 = pHead2->next;
    }
    return NULL;
}
//方法二
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(pHead1 == NULL || pHead2 == NULL)
        return NULL;
    int len1 = 0, len2 = 0;
    ListNode *p1 = pHead1, *p2 = pHead2;	//测量链表1 和 链表2 的长度
    while(p1 != NULL){
        len1++;
        p1= p1->next;
    }
    while(p2 != NULL){
        len2++;
        p2 = p2->next;
    }
    int diff = abs(len2 - len1);	//求得链表长度差diff，让长链表先遍历diff节点
    p1 = pHead1, p2 = pHead2;
    if(len1 >= len2){
        while(diff > 0){
            p1 = p1->next;
            diff--;
        }
    }else{
        while(diff > 0){
            p2 = p2->next;
            diff--;
        }
    }
    while(p1 != NULL && p2 != NULL){	//两链表同时向前搜索，找到公共节点为止
        if(p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}
```

## 37

统计一个数字在排序数组中出现的次数。

#### 思路

1. 使用二分搜索，找到后向左向右寻找

```c++
int GetNumberOfK(vector<int> data ,int k) {
    if(data.empty())
        return 0;
    int start = 0, end = data.size() - 1;
    int mid = (start + end) / 2;
    int idx = -1;
    while(start <= end){
        if(data[mid] < k){
            start = mid + 1;
        }else if(data[mid] > k){
            end = mid - 1;
        }else{
            idx = mid;
            break;
        }
    }
    if(idx != -1){
        int i = idx, j = idx;
        while(data[i] == k && i < data.size())
            i++;
        while(data[j] == k && j > 0)
            j--;
        return i - j - 1;
    }else{
        return 0;
    }
}
```

## 38

二叉树的深度

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#### 思路

1. 递归解法
2. 非递归解法

```c++

```

## 39

#### 思路

```c++

```

## 40

数组中只出现一个次的数

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

#### 思路

1. 主要思想是基于异或
2. 依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还是先异或，剩下的数字肯定是A、B异或的结果，**这个结果的二进制中的1，表现的是A和B的不同的位**。我们就取第一个1所在的位数，假设是第3位，接着把原数组分成**两组**，分组标准是第3位是否为1。如此，**相同的数肯定在一个组**，因为相同数字所有位都相同，而不同的数，**肯定不在一组**。然后把这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。

```c++

```

## 41

和为S的连续正数序列

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

#### 思路

1. 使用滑动窗口进行查找

```c++

```

## 42

和为S的两个数

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

#### 思路

1. 暴力求解 O(N2)
2. 使用Map进行存储后来进行寻找当前键值的差值

```c++

```

## 43

左旋转字符串

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

#### 思路

1. 左旋转K位就是将，前K位放置于字符串的尾部

```c++

```

## 44

翻转单词的顺序

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

#### 思路

1.  

```c++

```

## 45

#### 思路

```c++

```

## 46

孩子们的游戏 

每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

如果没有小朋友，请返回-1

#### 思路

约瑟夫环问题

```c++

```

## 47

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#### 思路

1. 不能使用循环则改用成递归(面试可能会遇到：不用循环怎么做加法)
2. 不能使用判断则使用 && 短路功能

```c++
int Sum_Solution(int n) {
    int res = n;
    bool flag = (n > 0) && (res +=Sum_Solution(n - 1)) > 0;
    return res;
}
```

## 48

不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

#### 思路

```c++

```

## 49

#### 思路

```c++

```

## 50

数组中重复的数字

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

#### 思路

1. 对数组进行排序，之后判断i+1的值和i值是否相等。

```c++
bool duplicate(int numbers[], int length, int* duplication) {
    quickSort(numbers, 0, length - 1);
    for(int i = 1; i < length; i++){
        if(numbers[i - 1] == numbers[i]){
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}
static void quickSort(int number[], int start, int end){
    if(start > end)
        return ;
    int val = number[start];
    int i = start, j = end;
    while(i < j){
        while(i < j && number[j] > val){
            j--;
        }
        while(i < j && number[i] < val){
            i++;
        }
        if(number[i] == number[j] && i < j){
            i++;
        }else{
            int temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        }
    }
    if(i - 1 > start)
        quickSort(number, start, i - 1);
    if(i + 1 < end)
        quickSort(number, i + 1, end);
}
```

## 51

#### 思路

```c++

```

## 52

#### 思路

```c++

```

## 53

#### 思路

```c++

```

## 54

#### 思路

```c++

```

## 55

链表中环的入口

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#### 思路

1. 使用Map或者Set进行存储，找到第一重复的节点
2. 快慢指针，使用套圈原理，当快慢指针指向同一节点时，将快指针指向头节点后，快慢指针同时开始遍历到相同的节点即为公共节点（证明略）

```c++
//方法1

//方法2

```

## 56

删除链表中重复的节点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

#### 思路

1. 遍历，将前指针指向后指即可

```c++

```

## 57

二叉树的下一节点

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

#### 思路

中序遍历的下一节点

1. 如果这个节点有右节点，
2. 如果这个节点没有右节点，

```c++

```

## 58

对称二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#### 思路

1. 使用递归方法
2. 判断条件：当一个树的左右节点相同，则判断左右节点，左子树的右节点等于右子树的左节点，左子树的左节点等于右子树的右节点

```c++

```

## 59

按之字形打印二叉树

请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

#### 思路

1. 二叉树的层序遍历，将奇数偶数层进行反转

```c++

```

## 60

#### 思路

```c++

```

## 61

#### 思路

```c++

```

## 62

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）  中，按结点数值大小顺序第三小结点的值为4。

#### 思路

二叉搜索树中序遍历得到一个有序的数组，第k-1位即是所求的值

```c++
TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
{
    if(pRoot==NULL||k<=0) return NULL;
    vector<TreeNode*> vec;
    Inorder(pRoot,vec);
    if(k>vec.size())
        return NULL;
    return vec[k-1];
}
//中序遍历，将节点依次压入vector中
void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
{
    if(pRoot==NULL) return;
    Inorder(pRoot->left,vec);
    vec.push_back(pRoot);
    Inorder(pRoot->right,vec);
} 
```

## 63

#### 思路

```c++

```

## 64

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

#### 思路

使用队列对滑动窗口中的值进存储，当超过size将头结点退出

```c++
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> myVec;
    if(size == 0)
        return myVec;
    list<int> myList;
    for(int i = 0; i < num.size(); i++)
    {
        myList.push_back(num[i]);
        if(myList.size() >= size)
        {
            list<int>::iterator itor = max_element(myList.begin(), myList.end());
            myVec.push_back(*itor);
            myList.pop_front();
        }
    }
    return myVec;
}
```

## 65

#### 思路

```c++

```

## 66

#### 思路

```c++

```

## 67

#### 思路

```c++

```

