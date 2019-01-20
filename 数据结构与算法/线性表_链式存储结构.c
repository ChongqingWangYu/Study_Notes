#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType; //typedef表示取别名 
typedef int Status;

typedef struct Node{
	ElemType data;//数据域
	struct Node* next;//指针域 
}Node; 
typedef struct Node* LinkList; 



//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：用e返回L中第i个数据元素的值。
Status GetElem(LinkList L,int i,ElemType *e){
	int j;
	LinkList p;
	
	p=L->next;
	j=1;
	
	while(p && j<i){
		p=p->next;
		++j;
	} 
	
	if(!p || j>i){
		return ERROR;
	}
	
	*e = p->data;
	
	return OK;
}

//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：在L中第i个位置之前插入新的数据元素e,L长度+1。
Status ListInsert(LinkList *L,int i,ElemType e){
	int j;
	LinkList p,s;
	
	p=*L;
	j=1;
	while(p && j<i){ //用于寻找第i个结点 
		p = p->next;
		j++;
	}
	
	if(!p || j>i){
		return ERROR;
	}
	
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	
	s->next = p-next;
	p->next = s;
	
	return OK;
}

//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：删除L中第i个数据元素，并用e返回其值,L长度-1。
Status ListDelete(SqList *L,int i,ElemType *e){
	int j ;
	LinkList p,q;
	
	p=*L;
	j=1;
	while(p->next && j<i){ //
		p = p->next;
		j++;
	}
	
	if(!(p->next) || j>i){
		return ERROR;
	}
	
	q = p->next;
	p->next = q->next;
	
	*e = q->data;
	free(q);
	
	
	return OK;
	
}


