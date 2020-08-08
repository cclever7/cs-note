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
重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#### 思路

1. 前序遍历第一个节点为父节点，刚可将中序遍历分成左右子树
2. 分成左右子树继续递归前面操作即可

```c++
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.empty() || vin.empty())
        return NULL;
    if(pre.size() == 1 || vin.size() == 1)
        return new TreeNode(pre[0]);
    TreeNode *node = new TreeNode(pre[0]);
    int idx = 0;
    for(uint32_t i = 0; i < vin.size(); i++){
        if(node->val == vin[i]){
            idx = i;
            break;
        }
    }
    vector<int> left_pre, left_in, right_pre, right_in;
    for(int i = 0; i < idx; i++){
        left_in.push_back(vin[i]);
        left_pre.push_back(pre[i+1]);
    }
    for(int i = idx + 1; i < vin.size(); i++){
        right_in.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }
    node->left = reConstructBinaryTree(left_pre, left_in);
    node->right = reConstructBinaryTree(right_pre, right_in);
    return node;
}
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

二进制中1的个数

输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

#### 思路

1. **对n操作时 n = n >> 1，不知道为什么超出时间限制**

```c++
int NumberOf1(int n) {
    uint32_t res = 0;
    unsigned int flag = 1;
    while(flag){
        if(n & flag)
            res++;
        flag = flag << 1;
    }
    return res;
}
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
树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

#### 思路

1. 递归判断A的父节点，左节点，右节点分别与B相等。
2. 相等时，判断当前节点的，左右节点是否与B的左右节点相等

```c++
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot2 == NULL)
        return true;
    if(pRoot1 == NULL)
        return false;
    if(pRoot1->val == pRoot2->val)
        return isSubtree(pRoot1->left,pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    else
        return false;
}
    
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot1 == NULL || pRoot2 == NULL)
        return false;
    return isSubtree(pRoot1, pRoot2) || isSubtree(pRoot1->left, pRoot2) || isSubtree(pRoot1->right, pRoot2);
}
```
## 18

操作给定的二叉树，将其变换为源二叉树的镜像。

```
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

#### 思路

1. 根节点不变
2. 左右节点互换，左右节点的子节点也需要互换

```c++
void Mirror(TreeNode *pRoot) {
    if(pRoot == NULL)
        return ;
    TreeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}
```

## 19

顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

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

1. 构造一个新栈进行操作，不断对pushV中的值进行入栈操作
2. 当pushV和popV相等时进行出栈操作，最终判断栈是否为空

```c++
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.empty() || popV.empty())
        return true;
    vector<int> v;
    uint32_t j = 0;
    for(uint32_t i = 0; i < pushV.size(); i++){
        v.push_back(pushV[i]);
        if(pushV[i] == popV[j]){
            v.pop_back();
            j++;
        }
    }
    for(; j < popV.size(); j++){
        if(v[v.size() - 1] == popV[j])
            v.pop_back();
        else
            break;
    }
    if(v.size() == 0)
        return true;
    return false;
}
```

## 22

从上到下打印二叉树

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#### 思路

使用队列进行操作

```c++
vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
        return res;
    list<TreeNode *> list;
    list.push_back(root);
    while(!list.empty()) {
        TreeNode *node = list.front();
        res.push_back(node->val);
        if(node->left != NULL){
            list.push_back(node->left);
        }
        if(node->right != NULL){
            list.push_back(node->right);
        }
        list.pop_front();
    }
    return res;
}
```

## 23

二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

#### 思路

1. 二叉树搜索树，父节点的值大于左子树的节点，小于右子树节点
2. 后序遍历，先左右节点再遍历 

```c++

```

## 24

二叉树中和为某一值的路径

输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#### 思路

```c++

```

## 25

复杂链表的复制  

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

#### 思路

```c++

```

## 26

二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

#### 思路

```c++

```

## 27

字符串全排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

#### 思路

```c++

```

## 28

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#### 思路

1. 若该数超过数组一半，那么该数肯定位于数组中间位置
2. 取得该数后向左向右遍历其范围，查看其范围大小是否过一半。

```c++
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.empty())
        return 0;
    sort(numbers.begin(), numbers.end());
    int mid = (numbers.size() - 1) / 2;
    int i = mid, j = mid, res = numbers[mid];
    while(numbers[i] == res && i >= 0)
        i--;
    while(numbers[j] == res && j < numbers.size())
        j++;
    if((j - i - 1) > numbers.size()/2)
        return res;
    else
        return 0;
}
```

## 29

最小的K个数

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

#### 思路

1. 方法一：排序后直接遍历K个数
2. 方法二：堆排序，交换过程中直接可以取得K个最小值

```c++
// method 1
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> v;
    if(input.empty() || input.size() < k)
        return v;
    sort(input.begin(), input.end(), my_cmp);
    for(uint32_t i = 0; i < k; i++){
        v.push_back(input[i]);
    }
    return v;
}
static int my_cmp(int v1, int v2){
    return v1 < v2;
}
```

## 30

连续子数组的最大和

HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

#### 思路

1. 1阶动态规划
2. 到第i个数的最大和等于 max[i] = max[i-1] + arr[i] > arr[i] ? max[i-1] + arr[i] : arr[i];

```c++
int FindGreatestSumOfSubArray(vector<int> array) {
    if(array.empty())
        return 0;
    int *res = new int[array.size()];
    for(int i = 0; i < array.size(); i++) {
        *(res + i) = 0;
    }
    *res = array[0];
    for(int i = 1; i < array.size(); i++) {
        int last_val = *(res + i - 1);
        if(last_val + array[i] > array[i]) {
            *(res + i) = last_val + array[i];
        } else {
            *(res + i) = array[i];
        }
    }
    int max = 1 << 31;
    for(int i = 0; i < array.size(); i++) {
        max = *(res + i) > max ? *(res + i) : max;
    }
    return max;
} 
```

## 31

整数中1出现的次数（从1到n整数中1出现的次数）

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

#### 思路

1. 循环计算即可

```c++
int NumberOf1Between1AndN_Solution(int n) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int temp = i;
        while(temp > 0) {
            if(temp % 10 == 1)
                res++;
            temp /= 10;
        }
    }
    return res;
}

```

## 32

把数组排成最小的数

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#### 思路

1.设定排序规则，后将数组连接到字符串，重点在cmp

```c++
string PrintMinNumber(vector<int> numbers) {
    int len = numbers.size();
    if(len == 0) return "";
    sort(numbers.begin(), numbers.end(), cmp);
    string res;
    for(int i = 0; i < len; i++){
        res += to_string(numbers[i]);
    }
    return res;
}
static bool cmp(int a, int b){
    string A = to_string(a) + to_string(b);
    string B = to_string(b) + to_string(a);
    return A < B;
}
```

## 33

丑数

把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#### 思路

首先从丑数的定义我们知道，一个丑数的因子只有2,3,5，那么丑数p = 2 ^ x * 3 ^ y * 5 ^ z，换句话说一个丑数一定由另一个丑数乘以2或者乘以3或者乘以5得到，那么我们从1开始乘以2,3,5，就得到2,3,5三个丑数，在从这三个丑数出发乘以2,3,5就得到4，6,10,6，9,15,10,15,25九个丑数，我们发现这种方法得到重复的丑数，而且我们题目要求第N个丑数，这样的方法得到的丑数也是无序的。那么我们可以维护三个队列：
（1）丑数数组： 1
乘以2的队列：2
乘以3的队列：3
乘以5的队列：5

```c++
int GetUglyNumber_Solution(int index) {
    if (index < 7)return index;
    vector<int> res(index);
    res[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0, i;
    for (i = 1; i < index; ++i)
    {
        res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
        if (res[i] == res[t2] * 2)t2++;
        if (res[i] == res[t3] * 3)t3++;
        if (res[i] == res[t5] * 5)t5++;
    }
    return res[index - 1];
}
```

## 34

第一个只出现一次的字符（字节跳动面试）

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）

#### 思路

1. 首先遍历字符串，利用map统计每个字符串出现的次数
2. 再次遍历字符串，并利用每位字符查找，首次发现为1 的即是结果
3. 优化解法，将map替换为长度为26的数组，数组的每一位的下标代表字母，值代表出现的次数

```c++
int FirstNotRepeatingChar(string str) {
    if(str.empty() || str.size() == 0)
        return -1;
    map<char, int> mmap;
    for(int i = 0; i < str.size(); i++) {
        map<char, int>::iterator itor = mmap.find(str[i]);
        if(itor != mmap.end())
            itor->second += 1;
        else
            mmap.insert(make_pair(str[i], 1));
    }
    for(int i = 0; i < str.size(); i++){
        map<char, int>::iterator itor = mmap.find(str[i]);
        if(itor->second == 1)
            return i;
    }
    return -1;
}
```

## 35

数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

#### 思路

1. 暴力扫描，双重循环复杂度为O(N平方)，算法超时

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
//method 1
int TreeDepth(TreeNode* pRoot) {
    if(pRoot == nullptr)
        return 0;
    int left = TreeDepth(pRoot->left) + 1;
    int right = TreeDepth(pRoot->right) + 1;
    return max(left, right);
}
```

## 39

平衡二叉树

输入一棵二叉树，判断该二叉树是否是平衡二叉树。在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树

#### 思路

1. 平衡二叉树左右子树的高度不超过1， 从上往下依次比较，若满足则深度需要加1
2. 递归解法 

```c++
bool IsBalanced_Solution(TreeNode* pRoot) {
    return get_tree_depth(pRoot) != -1;
}

int get_tree_depth(TreeNode *pRoot) {
    if(pRoot == nullptr) 
        return 0;
    int left = get_tree_depth(pRoot->left);
    if(left == -1)
        return -1;
    int right = get_tree_depth(pRoot->right);
    if(right == -1)
        return -1;
    return abs(left - right) > 1 ? -1 : 1 + max(left, right);
}
```

## 40

数组中只出现一个次的数

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

#### 思路

1. 主要思想是基于异或
2. 依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还是先异或，剩下的数字肯定是A、B异或的结果，**这个结果的二进制中的1，表现的是A和B的不同的位**。我们就取第一个1所在的位数，假设是第3位，接着把原数组分成**两组**，分组标准是第3位是否为1。如此，**相同的数肯定在一个组**，因为相同数字所有位都相同，而不同的数，**肯定不在一组**。然后把这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。

```c++
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    if(data.empty())
        return ;
    int res = data[0];
    for(int i = 1; i < data.size(); i++) {
        res = res ^ data[i];
    }
    int idx = 0;
    while(res > 0) {
        if(res & 1 == 1)
            break;
        res = res >> 1;
        idx++;
    }
    for(int i = 0; i < data.size(); i++) {
        if(data[i] >> idx & 1 == 1)
            *num1 ^= data[i];
        else
            *num2 ^= data[i];
    }
}
```

## 41

和为S的连续正数序列

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

#### 思路

1. 使用滑动窗口进行查找，等差数列的和为 (low + high) * (high - low + 1) / 2;
2. 如果相等即得到一组序列值 ，如果小于sum则窗口需要扩大->high++,若大于窗口需要缩小->low--

```c++
vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    if(sum == 1)
        return res;
    int low = 1, high = 2;
    while(low < high) {
        int val = (low + high) * (high - low + 1) / 2; //等差数列求和
        if(val == sum) {
            vector<int> v;
            for(int i = low; i <= high; i++)
                v.push_back(i);
            res.push_back(v);
            low++;
        } else if(val < sum) {
            high++;
        } else {
            low++;
        }
    }
    return res;
}
```

## 42

和为S的两个数

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

#### 思路

1. 暴力求解 O(N2)
2. 使用Map进行存储后来进行寻找当前键值的差值
3. 使用滑动窗口，来判断。

```c++
//method 3
 vector<int> FindNumbersWithSum(vector<int> array,int sum) {
     vector<int> res;
     if(array.size() <= 1)
         return res;
     int low = 0, high = array.size() - 1;
     while(low < high) {
         int val = array[low] + array[high];
         if(val < sum) {
             low++;
         } else if(val > sum) {
             high--;
         } else {
             res.push_back(array[low]);
             res.push_back(array[high]);
             break;  // 1 X 3 肯定小于 2 X 2
         }
     }
     return res;
 }
```

## 43

左旋转字符串

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

#### 思路

1. 左旋转K位就是将，前K位放置于字符串的尾部

```c++
string LeftRotateString(string str, int n) {
    string res = "";
    if(str.empty() || n > str.size())
        return res;
    for(int i = n; i < str.size(); i++) {
        res += str[i];
    }
    for(int i = 0; i < n; i++) {
        res += str[i];
    }
    return res;
}
```

## 44

翻转单词的顺序

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

#### 思路

1.   按空格进行翻转
2.  先整体翻转，再按单词进行翻转

```c++

```

## 45

扑克牌顺子

LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

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

构建乘积数组

给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。

#### 思路

下三角用连乘可以很容求得，上三角，从下向上也是连乘。

因此我们的思路就很清晰了，先算下三角中的连乘，即我们先算出B[i]中的一部分，然后倒过来按上三角中的分布规律，把另一部分也乘进去

<img src="D:\git\docs\dataStructures-algorithms\medium\image-20200808102436161.png" alt="image-20200808102436161" style="zoom: 67%;" />

```c++
vector<int> multiply(const vector<int>& A) {
    vector<int> res(A.size());
    if(A.size() <= 1)
        return res;
    //计算下三角
    res[0] = 1;
    for(int i = 1; i < A.size(); i++) {
        res[i] = res[i-1] * A[i-1];
    }
    //计算上三角
    int temp = 1;
    for(int j = A.size() - 2; j >= 0; j--) {
        temp *= A[j+1];
        res[j] *= temp;
    }
    return res;
}
```

## 52

正则表达式匹配

请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

#### 思路

**当模式中的第二个字符不是“\*”时：**

1、如果字符串第一个字符和模式中的第一个字符相匹配，那么字符串和模式都后移一个字符，然后匹配剩余的。

2、如果 字符串第一个字符和模式中的第一个字符相不匹配，直接返回false。

**而当模式中的第二个字符是“\*”时：**

如果字符串第一个字符跟模式第一个字符不匹配，则模式后移2个字符，继续匹配。如果字符串第一个字符跟模式第一个字符匹配，可以有3种匹配方式：

1、模式后移2字符，相当于x*被忽略；

2、字符串后移1字符，模式后移2字符；

3、字符串后移1字符，模式不变，即继续匹配字符下一位，因为*可以匹配多位；

```c++
bool match(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    //if the next character in pattern is not '*'
    if (*(pattern+1) != '*')
    {
        if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match(str+1, pattern+1);
        else
            return false;
    }
    //if the next character is '*'
    else
    {
        if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match(str, pattern+2) || match(str+1, pattern);
        else
            return match(str, pattern+2);
    }
}
```

## 53

表示数值的字符串

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

#### 思路

1. 方法一：正则表达式进行匹配
2. 方法二：如下，根据规则进行逐位判断

```c++
//method 2
bool isNumeric(char* str) {
    // 标记符号、小数点、e是否出现过
    bool sign = false, decimal = false, hasE = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'e' || str[i] == 'E') {
            if (i == strlen(str)-1) return false; // e后面一定要接数字
            if (hasE) return false;  // 不能同时存在两个e
            hasE = true;
        } else if (str[i] == '+' || str[i] == '-') {
            // 第二次出现+-符号，则必须紧接在e之后
            if (sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
            // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
            if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
            sign = true;
        } else if (str[i] == '.') {
            // e后面不能接小数点，小数点不能出现两次
            if (hasE || decimal) return false;
            decimal = true;
        } else if (str[i] < '0' || str[i] > '9') // 不合法字符
            return false;
    }
    return true;
}
```

## 54

字符流中第一个不重复的字符

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

#### 思路

1. 利用一个队列来记录数据读取的顺序 
2. 利用一个map来记录数据读入的次数
3. 顺序遍历这个队列，用map进行查找，找到1就返回

```c++
list<char> queue;
map<char, int> mmap;
void Insert(char ch) {
    queue.push_back(ch);
    map<char, int>::iterator itor = mmap.find(ch);
    if(itor == mmap.end()) {
        mmap.insert(make_pair(ch, 1));
    } else {
        itor->second += 1;
    }
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce() {
    for(list<char>::iterator itor = queue.begin(); itor != queue.end(); itor++) {
        map<char, int>::iterator map_itor = mmap.find(*itor);
        if(map_itor->second == 1) {
            return map_itor->first;
        }
    }
    return '#';
}

```

## 55

链表中环的入口

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#### 思路

1. 使用Map或者Set进行存储，找到第一重复的节点
2. 快慢指针，使用套圈原理，当快慢指针指向同一节点时，将快指针指向头节点后，快慢指针同时开始遍历到相同的节点即为公共节点（证明略）

```c++
//方法1
 ListNode* EntryNodeOfLoop(ListNode* pHead)
 {
     if(pHead == NULL)
         return NULL;
     map<ListNode *, int> mmap;
     ListNode *ptr = pHead;
     while(ptr != NULL){
         map<ListNode *, int>::iterator itor = mmap.find(ptr);
         if(itor != mmap.end()){
             return itor->first;
         }else{
             mmap.insert(make_pair(ptr, 1));
         }
         ptr = ptr->next;
     }
     return NULL;
 }
//方法2
ListNode* EntryNodeOfLoop(ListNode* pHead){
    if(pHead == NULL)
        return NULL;
    ListNode *slow = pHead, *fast = pHead;
    bool flag = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }
    if(flag != true)
        return NULL;
    fast = pHead;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
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

1. 二叉树的层序遍历，将奇数偶数层进行反转，类似于题60

```c++
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res; 
    if(pRoot == NULL)
        return res;
    list<TreeNode *> queue;
    queue.push_back(pRoot);
    int flag = 1;
    vector<int> v;
    int now = 1, next = 0;
    while(!queue.empty()) {
        TreeNode *node = queue.front();
        v.push_back(node->val);
        queue.pop_front();
        now--;
        if(node->left != NULL) {
            queue.push_back(node->left);
            next++;
        }
        if(node->right != NULL) {
            queue.push_back(node->right);
            next++;
        }
        if(now == 0) {
            vector<int> temp(v);
            v.clear();
            if(flag) {
                flag = 0;
            }else {
                flag = 1;
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            now = next;
            next = 0;
        }
    }
    return res;
}
```

## 60

把二叉树打印成多行

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

#### 思路

1. 使用队列就进行入队出队管理
2. 需要找到每一行最后一个节点，从而得到每一行的值，使用now和next变量控制每行的范围

```c++
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    if(pRoot == NULL)
        return res;
    list<TreeNode *> queue;
    queue.push_back(pRoot);
    vector<int> v;
    int now = 1, next = 0;
    while(!queue.empty()) {
        TreeNode *node = queue.front();
        v.push_back(node->val);
        queue.pop_front();
        now--;
        if(node->left != NULL) {
            queue.push_back(node->left);
            next++;
        }
        if(node->right != NULL) {
            queue.push_back(node->right);
            next++;
        }
        if(now == 0) {
            vector<int> temp(v);
            res.push_back(temp);
            v.clear();
            now = next;
            next = 0;
        }
    }
    return res;
}
```

## 61

序列化二叉树

请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树

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

数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

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

矩阵中的路径 

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如![image-20200807215247249](D:\git\docs\dataStructures-algorithms\medium\image-20200807215247249.png)矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

#### 思路

```c++

```

## 66

机器人运行范围

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

#### 思路

```c++

```

## 67

 剪绳子

给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

#### 思路

```c++

```

