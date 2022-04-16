#pragma once
#include <iostream>
#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#define DataType int 
#define MAXNUM 100
struct SeqStack
{
	int MaxNum;
	unsigned int t;  // tָʾջ��λ�ã�������Ԫ�ظ���
	DataType* val;
	SeqStack() : MaxNum(MAXNUM), t(0), val((DataType*)malloc(sizeof(int)* MAXNUM)) {}
	SeqStack(int MAX): MaxNum(MAX), t(0), val((DataType*)malloc(sizeof(int)* MAX)) {}
	int isEmpty(SeqStack st);// �ж��Ƿ�Ϊ��
	void SeqPush(SeqStack& st, DataType x); // ����ֵ
	void SeqPop(SeqStack& st); // ɾ������ֵ
	DataType SeqTop(SeqStack st); // ���ض���ֵ
};


#endif // !_SEQSTACK_H_
