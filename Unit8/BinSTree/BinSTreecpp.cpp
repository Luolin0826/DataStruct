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
BinSTree BSTreeSearch(BinSTree t, KeyType k) {
  if (t == NULL) {  //树为空
    return NULL;
  }
  if (t->Elem.key == k) {  //根节点与其相同
    return t;
  }
  if (t->Elem.key > k) {  //结点的元素大于k
    return BSTreeSearch(t->lchild, k);
  } else {  //结点的元素小于k
    return BSTreeSearch(t->rchild, k);
  }
}
//插入 注意 这里的t是需要被保留的数
//课本中的少考虑了k已经在二叉排序树中存在的情况
void BSTreeInsert(BinSTree* t, KeyType k) {
  BinSTree r;
  if (t == NULL) {
    r = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    r->Elem.key = k;
    r->lchild = r->rchild = NULL;
    *t = r;  //注意这里是*t 二次指针相当于把原来的那个指针表达成最初的形式
    return;  //用来结束循环
  } else {
    if (k < (*t)->Elem.key) {  //跳入左子树
      BSTreeInsert(&((*t)->lchild), k);
    } else if (k = (*t)->Elem.key) {
      printf("元素已经被存在树里了！");
    } else {
      BSTreeInsert(&((*t)->rchild), k);  //跳入右子树
    }
  }
}
//使用非递归来实现二叉排序树的插入操作
void BSTreeInsert_FDG(BinSTree* t, KeyType k) {
  //第一步考虑节点为空的情况
  if (*t == NULL) {
    BinSTree q;
    q = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    q->Elem.key = k;
    q->lchild = q->rchild = NULL;
    *t = q;
  } else {
    BinSTree p = *t;  //定义一颗辅助树
    while (p) {
      if (k == p->Elem.key) {
        printf("元素已经被存在树里了！");
        return;
      } else if (k < p->Elem.key) {
        if (p->lchild != NULL) {  //左子树不为空时，继续对左子树进行扫描
          p = p->lchild;
        } else {  //这里是左子树为空的情况
          BinSTree m;
          m = (BinSTree)malloc(sizeof(struct BinSTreeNode));
          m->Elem.key = k;
          m->lchild = m->rchild = NULL;
          p->lchild = m;  //连接上去
        }
      } else {//这里是元素大于根节点的情况
        if (p->rchild != NULL) {  //右子树不为空时，继续对右子树进行扫描
          p = p->rchild;
        } else {  //这里是右子树为空的情况
          BinSTree m;
          m = (BinSTree)malloc(sizeof(struct BinSTreeNode));
          m->Elem.key = k;
          m->lchild = m->rchild = NULL;
          p->rchild = m;  //连接上去
        }
      }
    }
  }
}

//创建二叉排序树 其中 n为a中元素个数
BinSTree BSTreeCreat(KeyType a[], int n) {
  BinSTree t;
  t = NULL;
  for (int i = 0; i < n; i++) {
    BSTreeInsert(&t, a[i]);
  }
  return t;
}
//二叉排序树的删除操作 删除值为k的点 成功返回1 失败返回0
// 有三种可能
// 叶子节点：直接删掉
// 只有左子树或右子树：直接让子树来取代他
//既有左子树又有右子树：用直接前驱替换他
int BSTreeDelete(BinSTree* bt, KeyType k) {
  BinSTree f, p, q, s;
  p = *bt;
  f = NULL;
  while (p && p->Elem.key != k) {  //当p存在且值不为k 需要去寻找k
    f = p;                         // f为指向结点*p的双亲结点的指针
    if (p->Elem.key > k) {
      p = p->lchild;  //去左子树
    } else {
      p = p->rchild;
    }
  }
  //到这里 查找过程已经结束 如果查到了 p指针指向的地方就是，如果没查到
  //那么p肯定为空
  if (p == NULL) {
    return 0;
  }
  //以下为非空的情况
  if (p->lchild == NULL) {        //左子树为空
    if (f = NULL) {               //被删除的节点是根节点
      *bt = p->rchild;            //让右子树来继承
    } else if (f->lchild == p) {  //被删除的是左子树的结点
      f->lchild = p->rchild;
    } else {
      f->rchild = p->rchild;
    }
  } else {  //右子树为空 有左子树
    q = p;
    s = q->lchild;
    //这里循环的条件很巧妙 正好避免了使s为null的情况
    while (s->rchild) {  //去找直接前驱 在左子树的最有节点上
      q = s;             // q是s的双亲结点
      s = s->rchild;
    }
    //以下这段语句是为了将s从逻辑上删除
    if (q == p) {  //意思是，q就是s的祖先节点而且此时s右子树已经空了
      q->lchild = s->lchild;
    } else {
      q->rchild = s->lchild;  //注：此处的情况是 s为p的左子树的右子树结点
    }
    p->Elem.key = s->Elem.key;  //元素赋值
    free(s);                    //物理上释放
    return 1;
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
