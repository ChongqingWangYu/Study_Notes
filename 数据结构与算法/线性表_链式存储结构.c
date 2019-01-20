#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType; //typedef��ʾȡ���� 
typedef int Status;

typedef struct Node{
	ElemType data;//������
	struct Node* next;//ָ���� 
}Node; 
typedef struct Node* LinkList; 



//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//�����������e����L�е�i������Ԫ�ص�ֵ��
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

//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L����+1��
Status ListInsert(LinkList *L,int i,ElemType e){
	int j;
	LinkList p,s;
	
	p=*L;
	j=1;
	while(p && j<i){ //����Ѱ�ҵ�i����� 
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

//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//���������ɾ��L�е�i������Ԫ�أ�����e������ֵ,L����-1��
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


