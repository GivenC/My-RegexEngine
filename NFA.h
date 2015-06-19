#ifndef _NFA_H
#define _NFA_H

#include "NFA_Node.h"
#include "NFA_Edge.h"
#include "RE_TreeNode.h"
#include "RE_Tree.h"
#include <vector>
#include <map>

using namespace std;

class NFA
{
private:
	/* ������ʽ����ʵ�� */
	RE_Tree reTree;

	/* ָ���ڽӱ��ͷָ�� */
	NFA_Node *head;

	/* ������ */
	int nodeNumber;

	/* ��ʼ״̬�ͽ���״̬ */
	int start, accept;

	/* �����еĶ���洢Ϊһ������, ��Ϊÿ�����㶼��һ��Ψһ�ı�ʶ��num, ��num����������ָ�� */
	vector<NFA_Node *> nodes;

	/* �����з�EPS�ߴ洢Ϊһ��multimap, ���ݱ��ϵ��ַ��������ߵ�ָ�� */
	multimap<char, NFA_Edge *> edges;

	/* ����nodes��edges���� */
	void newNodesAndEdges();

	/* Thompson�㷨 */
	void Thompson(RE_TreeNode *tree);

	/* ���һ���� */
	void addEdge(int from, int to, char ch);

	/*
	���ڽӱ��в�����û��num��ʶ�Ķ���, �����,�򷵻�ָ��ö����ָ��,
	���򴴽�һ���µĶ��㲢����ָ��ö����ָ��
	*/
	NFA_Node* loopUpOrInsert(int num);

public:
	NFA(string str);
	void operator=(string str);
	~NFA();

	/* ���ؿ�ʼ����ı�ʶ */
	int getStart();

	/* ���ؽ���״̬����ı�ʶ */
	int getAccept();

	/* ������������ʽ��NFA��ת�� */
	void RE_to_NFA();

	/* �������еĽڵ�ķ���״̬Ϊfalse */
	void resetNodesVisit();

	/* ���ض������� */
	vector<NFA_Node *> &getNodes();

	/* ���ر����� */
	multimap<char, NFA_Edge *> &getEdges();

	// ����
	void print();
};

#endif