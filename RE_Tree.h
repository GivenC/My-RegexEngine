#ifndef _RE_TREE_H
#define _RE_TREE_H

#include "RE_TreeNode.h"
#include <string>
#include <set>

using namespace std;

class RE_Tree
{
private:
	/* exp�����洢������ʽ */
	string exp;

	/* pos��ָ��exp��λ��ָ�� */
	int pos;

	/* ���浱ǰ���ַ� */
	char currentChar;

	/* reTree��ָ��������ʽ���ĸ��ڵ� */
	RE_TreeNode *root;

	/* ����expʱ, ����exp�е���һ���ַ� */
	char getNextChar();

	/*
	������ʽ��BNF
	    exp -> exp | A
	        -> A
	      A -> A + B
	        -> B
	      B -> C*
	        -> C
	      C -> ( exp )
	        -> e
	�õݹ��½��ķ�ʽ������������ʽ, ���ɱ��ʽ��
	������ĸ������ֱ��Ӧ��BNF�е��ĸ��Ƶ�
	*/
	RE_TreeNode *parse_exp();
	RE_TreeNode *parse_A();
	RE_TreeNode *parse_B();
	RE_TreeNode *parse_C();

public:
	RE_Tree(string str);
	void operator=(string str);
	~RE_Tree();

	/* ���ر��ʽ���ĸ��ڵ�ָ�� */
	RE_TreeNode *getTreeRoot();

	/* ���ݱ��ʽexp�����ɱ��ʽ�� */
	void toRE_Tree();

	// ����
	void print();
	void printTree(RE_TreeNode *reTree);
};

#endif 
