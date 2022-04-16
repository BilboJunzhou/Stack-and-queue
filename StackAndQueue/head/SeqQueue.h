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
	bool isFull();		  // �ж��Ƿ�Ϊ��
	bool isEmpty();		  // �ж��Ƿ�Ϊ��
	void inQueue(int val);// ����βԪ��
	void outQueue();	  // ɾ��ͷԪ�� 
	int getHead();		  // ����ͷԪ��
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
	int getHead();				// ����ͷԪ��
	int getLast();				// ����βԪ��
	void getAll();
	void inQueueNode(int val);	// ����βԪ��
	void outQueueNode();		// ɾ��ͷԪ��
};
#endif
