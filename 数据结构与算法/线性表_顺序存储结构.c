#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType; //typedef��ʾȡ���� 
typedef int Status;

//ElemType��Ԫ�ص����� 
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��ok�ȡ�

typedef struct{
	ElemType data[MAXSIZE];
	int length;//���Ա�ǰ���� 
}SqList; 


//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//�����������e����L�е�i������Ԫ�ص�ֵ��
Status GetElem(SqList L,int i ,ElemType *e) {
	if(L->length == 0 || i<1 || i>L->length){
		return ERROR;
	}
	*e = L->data[i-1];
	
	return OK;
}


//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L����+1��
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){ //˳�����Ա��Ѿ����� 
		return ERROR;
	}
	if(i<1 || i>L->length){ //��i���ڷ�Χ��ʱ 
		return ERROR; 
	} 
	if(i < L->length) { //����������λ�ò��ڱ�β 
		
		//��Ҫ����λ�ú�����Ԫ������ƶ�һλ
		for(k=L->length-1;k >= i-1;k--){
			L->data[k+1] = L->data[k];
		} 
	}
	
	L->data[i-1] = e;//����Ԫ�ز���
	L->length++;
	
	return OK; 
} 


//��ʼ������ ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//���������ɾ��L�е�i������Ԫ�أ�����e������ֵ,L����-1��
Status ListDelete(SqList *L,int i,ElemType *e){
	int k ;
	
	if(L->length ==0){
		return ERROR;
	} 
	
	if(i<1 || i>L->length){ //��i���ڷ�Χ��ʱ 
		return ERROR; 
	} 
	
	*e = L->data[i-1];
	
	if(i < L->length){ //��ɾ�������ݲ��ڱ�β 
		//��Ҫɾ��λ�ú������Ԫ����ǰ�ƶ�һλ
		for(k=i;k <= L->length-1;k++){
			L->data[k-1] = L->data[k];
		} 
	} 
	
	L->length--;
	
	return OK;
	
}

























