#pragma once
#include <iostream>
#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#define DataType int 
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


#endif // !_SEQSTACK_H_
