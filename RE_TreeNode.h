#ifndef _RE_TREENODE_H
#define _RE_TREENODE_H

// ������ʽ���Ľڵ������
enum NodeKind {
	Element,	// �ַ�
	ALT,		// ѡ������
	CONCAT,		// ��������
	CLOSURE		// �հ�����
};

class RE_TreeNode
{
public:
	NodeKind nodeKind;
	char ch;
	RE_TreeNode *child[2];		// ÿ���ڵ������������

	RE_TreeNode(NodeKind nodeKind, char ch, RE_TreeNode *child0, RE_TreeNode *child1)
	{
		this->nodeKind = nodeKind;
		this->ch = ch;
		child[0] = child0;
		child[1] = child1;
	}
};

#endif