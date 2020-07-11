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
#### 思路
```c++

```
## 14 
#### 思路
```c++

```
## 15 
#### 思路
```c++

```
## 16
#### 思路
```c++

```
## 17 
#### 思路
```c++

```
##  
#### 思路
```c++

```
##  
#### 思路
```c++
​```##  
#### 思路
​```c++
```
##  
#### 思路
```c++

```
##  
#### 思路
```c++

```
##  
#### 思路
```c++

```


## 00
#### 思路
```c++
```


## 00
#### 思路
```c++
```

