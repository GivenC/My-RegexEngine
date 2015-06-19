#ifndef _MDFA_H
#define _MDFA_H

#include "DFA.h"
#include "MDFA_Node.h"
#include "MDFA_Edge.h"

class MDFA
{
private:
	/* DFA��ʵ�� */
	DFA dfa;

	/* ����ĸ��� */
	int nodeNumber;

	/* �ڽӱ��ͷָ�� */
	MDFA_Node *head;

	/* �����еĶ���洢Ϊһ������, ��Ϊÿ�����㶼��һ��Ψһ�ı�ʶ��num, ��num����������ָ�� */
	vector<MDFA_Node *>nodes;

	/* ��ĸ��, �洢��ǰ������ʽ�е������ַ� */
	set<char> alphabeta;

	/* ��Hopcroft�㷨��,��Ҫ�����ж����λ�����û�б仯, P��������ǰһ�λ��ֵĽ��, T�������滮�ֺ�Ľ�� */
	set<set<int>> T, P;

	/* �����㷨 */
	pair<set<int>, set<int>> split(set<int> S);

	/* Hopcroft�㷨 */
	void hopcroft();

	/* �½�һ���� */
	void addEdge(int f, int t, char c);

	/* ����DFA�ж���ı�ʶ��, ���ظö�����MDFA�еı�ʶ�� */
	int findNode(int i);

public:
	MDFA(string str);
	void operator=(string str);
	~MDFA();

	/* ��С��DFA */
	void minimizeDFA();

	vector<MDFA_Node *> &getNodes();

	/* ��ӡ���, ���� */
	void print();
};

#endif
