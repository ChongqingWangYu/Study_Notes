#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType; //typedef表示取别名 
typedef int Status;

//ElemType是元素的类型 
//Status 是函数的类型，其值是函数结果状态代码，如ok等。

typedef struct{
	ElemType data[MAXSIZE];
	int length;//线性表当前长度 
}SqList; 


//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：用e返回L中第i个数据元素的值。
Status GetElem(SqList L,int i ,ElemType *e) {
	if(L->length == 0 || i<1 || i>L->length){
		return ERROR;
	}
	*e = L->data[i-1];
	
	return OK;
}


//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：在L中第i个位置之前插入新的数据元素e,L长度+1。
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){ //顺序线性表已经满了 
		return ERROR;
	}
	if(i<1 || i>L->length){ //当i不在范围内时 
		return ERROR; 
	} 
	if(i < L->length) { //若插入数据位置不在表尾 
		
		//将要插入位置后数据元素向后移动一位
		for(k=L->length-1;k >= i-1;k--){
			L->data[k+1] = L->data[k];
		} 
	}
	
	L->data[i-1] = e;//将新元素插入
	L->length++;
	
	return OK; 
} 


//初始条件： 顺序线性表L已存在，1<=i<=ListLength(L)
//操作结果：删除L中第i个数据元素，并用e返回其值,L长度-1。
Status ListDelete(SqList *L,int i,ElemType *e){
	int k ;
	
	if(L->length ==0){
		return ERROR;
	} 
	
	if(i<1 || i>L->length){ //当i不在范围内时 
		return ERROR; 
	} 
	
	*e = L->data[i-1];
	
	if(i < L->length){ //若删除的数据不在表尾 
		//将要删除位置后的数据元素向前移动一位
		for(k=i;k <= L->length-1;k++){
			L->data[k-1] = L->data[k];
		} 
	} 
	
	L->length--;
	
	return OK;
	
}

























