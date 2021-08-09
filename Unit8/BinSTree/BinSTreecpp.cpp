#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//排序二叉树
typedef int KeyType;
//关键字段
typedef struct {
  KeyType key;
} DataType;
typedef struct BinSTreeNode {
  DataType Elem;
  struct BinSTreeNode* lchild;
  struct BinSTreeNode* rchild;
} * BinSTree;

//查找操作
BinSTree BTreeSearch(BinSTree t, KeyType k) {
  if (t == NULL) {  //树为空
    return NULL;
  }
  if (t->Elem.key == k) {  //根节点与其相同
    return t;
  }
  if (t->Elem.key > k) {  //结点的元素大于k
    return BTreeSearch(t->lchild, k);
  } else {  //结点的元素小于k
    return BTreeSearch(t->rchild, k);
  }
}
//插入 注意 这里的t是需要被保留的数
//课本中的少考虑了k已经在二叉排序树中存在的情况
void BTreeInsert(BinSTree* t, KeyType k) {
  BinSTree r;
  if (t == NULL) {
    r = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    r->Elem.key = k;
    r->lchild = r->rchild = NULL;
    *t = r;  //注意这里是*t 二次指针相当于把原来的那个指针表达成最初的形式
    return;  //用来结束循环
  } else {
    if (k < (*t)->Elem.key) {  //跳入左子树
      BTreeInsert(&((*t)->lchild), k);
    } else if (k = (*t)->Elem.key) {
      printf("元素已经被存在树里了！");
    } else {
      BTreeInsert(&((*t)->rchild), k);//跳入右子树
    }
  }
}
//创建二叉排序树


int main(int argc, char** argv) {
  system("pause");
  return 0;
}
