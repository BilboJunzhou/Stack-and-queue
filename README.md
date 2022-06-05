@[TOC](数据结构-队列与栈（定义和基本操作）)
# 前言
课程学习用书为《算法与数据结构-C语言描述（第三版）》
此次使用语言为C++，为了使程序清晰，建立了多个.h和.cpp的类进行实现
完整代码上传至Github可自行下载：

[https://github.com/BilboJunzhou/Stack-and-queue](https://github.com/BilboJunzhou/Stack-and-queue)

其中包括队列与栈的定义和一些基本操作，使用时引用头文件即可
# 队列
## 什么是队列
队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。进行插入操作的端称为队尾，进行删除操作的端称为队头。
## 通过链表定义顺序表
只定义一个指针，指针指向队列的尾部，那么环装队列尾指针的下一个就是头指针，可以很方便的进行相关操作。
图例：
![在这里插入图片描述](https://img-blog.csdnimg.cn/e1d470b71d78414fb57bac97ea7017cf.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5pep5a6J5LiN5a6J,size_20,color_FFFFFF,t_70,g_se,x_16)
### 链式结构顺序表的定义和相关操作
这里，为了方便起见，直接使用了之前我定义好的ListNode(链表)进行相关操作，操作主要包含尾部插入元素、头部删除元素、队列遍历。

SeqQueueNode.h:
```c
#define MAXNUM 100
struct SeqQueueNode
{
protected:
	// 成员
	ListNode* Last;
public:
	// 成员方法
	SeqQueueNode();
	SeqQueueNode(int val);
	int getHead();				// 返回头元素
	int getLast();				// 返回尾元素
	void getAll();
	void inQueueNode(int val);	// 插入尾元素
	void outQueueNode();		// 删除头元素
};
```

SeqQueueNode.cpp:
```c
SeqQueueNode::SeqQueueNode()
{
    Last = new ListNode();
}
SeqQueueNode::SeqQueueNode(int val)
{
    Last = new ListNode();
    Last->val = val;
    Last->next = Last;
}

int SeqQueueNode::getLast()
{
    if (!Last->next)
    {
        std::cout << "The Last is empty." << std::endl;
        throw 2;
    }
    return Last->next->val;
}

void SeqQueueNode::getAll()
{
    auto curr = Last->next;
    while (curr!=Last)
    {
        std::cout << curr->val << ' ';
        curr = curr->next;
    }
    std::cout << curr->val << std::endl;
}

int SeqQueueNode::getHead()
{
    if (!Last->next)
    {
        std::cout << "The Last is empty." << std::endl;
        throw 2;
    }
    return Last->val;
}


void SeqQueueNode::inQueueNode(int val)
{
    if (!Last->next)
    {
        Last->val = val;
        Last->next = Last;
        return;
    }
    else {
        ListNode* curr = new ListNode(val, Last->next);
        Last->next = curr;
        Last = Last->next;
    }
}

void SeqQueueNode::outQueueNode()
{
    if (Last->next == nullptr) {
        std::cout << "This queue is empty" << std::endl;
        return;
    }
    if (Last->next == Last) {
        Last->next = nullptr;
    }
    else
    {
        auto curr = Last->next;
        Last->next = Last->next->next;
        delete(curr);
    }
}
```
### 通过数组实现队列
数组实现队列的主要难点在于如何能够实现对数组的循环利用，而不是进行一定量的数组删除操作后，头指针指向数组的尾部，就无法操作了，这里我们应该着重注意循环！
具体图例如下：
![
](https://img-blog.csdnimg.cn/ef01c26933264f569487746b8bd2bc9f.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5pep5a6J5LiN5a6J,size_20,color_FFFFFF,t_70,g_se,x_16)
### 基本的定义和操作
这里具体功能和链式队列一样，主要注意不同实现方式的思想和代码写法：
SeqQueue.h:
```c
#define MAXNUM 100
struct SeqQueue
{
protected:
	int MaxNum;
	int head,last;
	DataType* element;
public:
	SeqQueue() :MaxNum(MAXNUM), head(0), last(0), element((int*)malloc(sizeof(DataType)* MaxNum)) {}
	SeqQueue(int MAX) :MaxNum(MAX), head(0),last(0), element((int*)malloc(sizeof(DataType)* MAX)) {}
	bool isFull();		  // 判断是否为满
	bool isEmpty();		  // 判断是否为空
	void inQueue(int val);// 插入尾元素
	void outQueue();	  // 删除头元素 
	int getHead();		  // 返回头元素
	int length();
	void getAll();
};
```
SeqQueue.cpp:
```c
bool SeqQueue::isFull()
{
    return (last+1)%MaxNum==head;
}

bool SeqQueue::isEmpty()
{
    return head==last;
}

void SeqQueue::inQueue(int val)
{
    if (isFull()) {
        std::cout << "The queue is empty!" << std::endl;
        return;
    }
    element[last] = val;
    last = (last + 1) % MaxNum;
}

void SeqQueue::outQueue()
{
    if (isEmpty()) {
        std::cout << "This queue is empty!" << std::endl;
        return;
    }
    head = (head + 1) % MaxNum;
}

int SeqQueue::getHead()
{
    if (isEmpty()) {
        std::cout << "This queue is empty!" << std::endl;
        throw 2;
    }
    return element[head];
}

int SeqQueue::length()
{
    return (last+MaxNum-head)%MaxNum;
}

void SeqQueue::getAll()
{
    for (int i = head; i < head + length(); i++) {
        std::cout << element[i % MaxNum] << ' ';
    }
    std::cout << '\n';
}
```
# 栈
只允许在一端进行插入或删除操作的线性表。栈是一种线性表，但限定这种线性表只能在某一段进行插入和删除操作。
## 栈的定义和相关操作
栈的相关操作比较简单，这里我便直接给出代码：
SeqStack.h:
```c
#define MAXNUM 100
struct SeqStack
{
	int MaxNum;
	unsigned int t;  // t指示栈顶位置，而不是元素个数
	DataType* val;
	SeqStack() : MaxNum(MAXNUM), t(0), val((DataType*)malloc(sizeof(int)* MAXNUM)) {}
	SeqStack(int MAX): MaxNum(MAX), t(0), val((DataType*)malloc(sizeof(int)* MAX)) {}
	int isEmpty(SeqStack st);// 判断是否为空
	void SeqPush(SeqStack& st, DataType x); // 插入值
	void SeqPop(SeqStack& st); // 删除顶部值
	DataType SeqTop(SeqStack st); // 返回顶部值
};
```
SeqStack.cpp:
```c
int SeqStack::isEmpty(SeqStack st)
{
    if (st.t == -1)return 1;
    else return 0;
}

void SeqStack::SeqPush(SeqStack& st, DataType x)
{
    if (st.t == st.MaxNum-1)
    {
        std::cout << "The stack is full cannot be inserted" << std::endl;
        return;
    }
    st.t++;
    st.val[st.t] = x;
}

void SeqStack::SeqPop(SeqStack& st)
{       
    if (st.t=0)
    {
        st.t--;
    }
    else
    {
        std::cout << "This SeqStack is empty." << std::endl;
    }
}

DataType SeqStack::SeqTop(SeqStack st)
{
    return st.val[st.t];
}
```
