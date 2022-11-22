#include<stdio.h>
#include<stdlib.h>

int mutex=1,empty=3,full=0,x=0;

void main(){

	int no;

	void producer();
	void consumer();

	int wait(int);
	int signal(int);

	printf("1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

	while(1){
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&no);

		switch(no){
		
			case 1:
				if((empty!=0) && (mutex==1))
					producer();
				else
					printf("BUFFER IS FULL\n");
					break;
			case 2:
				if((full!=0) && (mutex==1))
					consumer();
				else
					printf("BUFFER IS EMPTY\n");
					break;
			case 3:
					exit(0);
					break;
		}
	}
}
int add(int x){
	return(++x);
}
int sub(int x){
	return(--x);
}
void producer(){
	mutex=sub(mutex);
	empty=sub(empty);
	full=add(full);
	x++;
	printf("producer produces an item %d\n",x);
	mutex=add(mutex);
}
void consumer(){
	mutex=sub(mutex);
	empty=add(empty);
	full=sub(full);
	printf("consumer consumes an item %d\n",x);
	x--;
	mutex=add(mutex);
}
