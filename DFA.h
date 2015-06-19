#ifndef _DFA_H
#define _DFA_H

#include "DFA_Node.h"
#include "DFA_Edge.h"
#include "NFA.h"
#include <set>
#include <map>
#include <vector>

using namespace std;

class DFA
{
private:
	/* NFA��ʵ�� */
	NFA nfa;

	/* ����ĸ��� */
	int nodeNumber;

	/* ��ĸ��, �洢��ǰ������ʽ�е������ַ� */
	set<char> alphabeta;

	/* �ڽӱ��ͷָ�� */
	DFA_Node *head;

	/* �����еĶ���洢Ϊһ������, ��Ϊÿ�����㶼��һ��Ψһ�ı�ʶ��num, ��num����������ָ�� */
	vector<DFA_Node *> nodes;

	/* �����бߴ洢Ϊһ��multimap, ���ݱ��ϵ��ַ��������ߵ�ָ�� */
	multimap<char, DFA_Edge *> edges;

	/* ���Ӽ������㷨���ж��Ƿ���Ҫ�½�һ������ */
	bool needNewNode;

	/*
	���ڽӱ��в�����û���뼯��s��ͬ�ļ��ϵĶ���, �����,�򷵻�ָ��ýڵ��ָ��
	���򴴽�һ���µĽڵ㲢����ָ��ýڵ��ָ��
	*/
	DFA_Node *loopUpOrInsert(set<int> *s);

	/* �½�һ���� */
	void addEdge(set<int> *from, set<int> *to, char c);

	/* �Ӷ��㼯��q��ͨ���ַ�q����ת�Ƶ��Ķ���ļ��� */
	set<int> delta(set<int> *q, char c);

	/* ���㼯��x����Ҫͨ���κ��ַ��Ϳ���ת�Ƶ��Ķ���ļ��� */
	set<int> eps_closure(set<int> x);

	/* �Ӽ������㷨 */
	void subsetConstruct();

	/* ����nodes��edges���� */
	void newNodesAndEdges();

public:
	DFA(string str);
	void operator=(string str);
	~DFA();

	/* ������NFA��DFA��ת�� */
	void NFA_to_DFA();

	/* ������ĸ�� */
	set<char> getAlphabeta();

	/* �����ڽ������ͷָ�� */
	DFA_Node *getHead();

	/* ���ض������� */
	vector<DFA_Node *> &getNodes();

	/* ���ر����� */
	multimap<char, DFA_Edge *> &getEdges();

	/* ��ӡ���, ���� */
	void print();
};

#endif