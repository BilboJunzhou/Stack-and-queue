#pragma once
#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_
#include <atomic>
#include "ListNode.h"
#define MAXNUM 100
#define DataType int 
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

struct SeqQueueNode
{
protected:
public:
	ListNode* Last;
	SeqQueueNode();
	SeqQueueNode(int val);
	int getHead();				// 返回头元素
	int getLast();				// 返回尾元素
	void getAll();
	void inQueueNode(int val);	// 插入尾元素
	void outQueueNode();		// 删除头元素
};
#endif
