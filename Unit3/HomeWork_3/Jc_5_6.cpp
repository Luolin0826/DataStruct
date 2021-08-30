#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
#define MaxSize 20
typedef struct {
  DataType data[MaxSize];
  int Stack0, Stack1;  //标识指示两个栈
  int length,Maxsize;          //元素个数
} UnionStack, *PUnionStack;
//初始化
PUnionStack InitStack() {
  PUnionStack P;
  P = (UnionStack*)malloc(sizeof(UnionStack) * MaxSize);//注意Sizeof里面的内容 如果填DataType会引发内存泄漏
  P->length = 0;
  P->Maxsize = MaxSize;
  P->Stack0 = -1;
  P->Stack1 = MaxSize - 1;
  return P;
}
//进栈操作 i=0或1代表不同的栈
void Push(PUnionStack P, int i, DataType x) {
  if (P->length <= MaxSize) {  //栈中还有空间
    if (i == 0) {              //头部进栈
      P->data[++P->Stack0] = x;
      P->length++;
    } else if (i == 1) {  //尾部进栈
      P->data[P->Stack1--] = x;
      P->length++;
    } else {  //出错
      printf("参数出错！");
      return;
    }
  } else {
    printf("栈满或者栈不存在！");
    return;
  }
}
//出栈操作
void Pop(PUnionStack P, int i) {
  if (P->length > 0) {  //栈中存有元素
    if (i == 0) {
      P->Stack0--;  //逻辑上删除0栈中的元素
      P->length--;
    } else if (i == 1) {
      P->Stack1++;
      P->length--;
    } else {
      printf("参数出错！");
      return;
    }
  } else {
    printf("栈空或者栈不存在！");
    return;
  }
}

//输出显示
void Printf_Union(PUnionStack P) {
  int i, j;
  printf("\n栈0中的元素有：");
  for (i = 0; i <= P->Stack0; i++) {
    printf("%d ", P->data[i]);
  }
  printf("\n栈1中的元素有：");
  for (j = P->Maxsize-1; j > P->Stack1; j--) {
    printf("%d ", P->data[j]);
  }
}

int main(int argc, char** argv) {
  PUnionStack P = InitStack();
  for (int i = 0; i < 5; i++) {
    Push(P, 0, i);
  }
  for (int j = 8; j < 14; j++) {
    Push(P, 1, j);
  }
  Printf_Union(P);
//  Pop(P,0);
//  Pop(P, 1);
//  Printf_Union(P);
  system("pause");
  return 0;
}
