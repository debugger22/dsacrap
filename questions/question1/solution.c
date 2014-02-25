#include <stdio.h>
#include <stdlib.h>

char value;
char temp;
struct list{
	char value;
	struct list *next;
};
unsigned int length;
unsigned int i=0;
unsigned int operation;
unsigned int position;
unsigned int times = 0;
unsigned int opPositions[] = {0,0,0,0,0};
unsigned int opHistory[] = {0,0,0,0,0};	// 1 - Insert, 2 - Delete, 3 - Undo, 4 - Display, 5 - Exit
unsigned int list_length(struct list *head);
char opChars[] = {' ',' ',' ',' ',' '};
void add(struct list *head, char val);
void insert(struct list *head, int position, char val);
char delete(struct list *head, int position);
void updateOp(unsigned int opType, char opChar, unsigned int opPos);
void resetOp();
void printlist(struct list *head);
void list_reverse(struct list *head);
void undo(struct list *head, unsigned int times);

void main(){
	struct list *mList;
	mList = (struct list *)malloc(sizeof(struct list));
	scanf("%d",&i);
	while(1){
		scanf("%c",&temp);
		if(temp=='\n'){
			break;
		}else if(temp!=' '){
			add(mList,temp);
		}
	}
	while(1){	
		scanf("%d",&operation);
		if(operation==1){
			scanf("%c", &temp);scanf("%d",&position);scanf("%c", &temp);
			scanf("%c",&value);scanf("%c", &temp);
			insert(mList,position,value);
			updateOp(1,value,position);
		}else if(operation==2){
			scanf("%c", &temp);scanf("%d",&position);
			scanf("%c", &temp);
			value = delete(mList,position);
			updateOp(2,value,position);
		}else if(operation==3){
			scanf("%c", &temp);scanf("%d",&times);scanf("%c", &temp);
			undo(mList, times);
			updateOp(3,' ',0);
		}else if(operation==4){
			scanf("%c", &temp);printlist(mList);	
			updateOp(4, ' ',0);	
		}else if(operation==5){
			scanf("%c", &temp);
			//updateOp(5, ' ',0);
			break;
		}	
	}
	for(i=0;i<5;i++){
	   printf("%d%c ",opHistory[i],opChars[i]);
	}
}

void add(struct list *head, char val){
    //create new node
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    if(newNode == NULL){
        exit(-1);
    }
    newNode->value = val;
    newNode->next = NULL;  // Change 1
    //check for first insertion
    if(head->next == NULL){
        head->next = newNode;
    }else{
        //else loop through the list and find the last
        //node, insert next to it
        struct list *current = head;
        while (1) {
            if(current->next == NULL){
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}

void printlist(struct list *head) {
	struct list *tmp = head;

	if (tmp == NULL) {
		return;
	}
	while (tmp != NULL) {
		if (tmp->next == NULL) {
			fprintf(stdout, "%c", tmp->value);
		}else{
		   fprintf(stdout, "%c", tmp->value);
		}
		tmp = tmp->next;
	}
}

void insert(struct list *head, int position, char val){
	if(list_length(head)<position){
		fprintf(stdout, "no");
		exit(EXIT_FAILURE);
	}
	struct list *tmp;
	struct list *nxt;
	if ((tmp = malloc(sizeof(struct list))) == NULL) {
		(void)exit(EXIT_FAILURE);
	}
	tmp->value = val;
	for(i=0;i<position-1;i++){
		head = head->next;
	}
	nxt = head->next;
	head->next = tmp;
	tmp->next = nxt;
}

char delete(struct list *head, int position){
   char item;
	if(list_length(head)<position){
		fprintf(stdout, "no");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<position-1;i++){
		head = head->next;
	}
	struct list *pre;
	struct list *nxt;
	pre = head;
	head = head->next;
	nxt = head->next;
	item = head->value;
	free(head);
	pre->next = nxt;
	return item;
}

void list_reverse(struct list *head){
    struct list *ptr, *prev = NULL, *tmp;
    if (head == NULL) return;
    ptr = head->next;  
    while (ptr){
       tmp = ptr->next;
       ptr->next = prev;
       prev = ptr;
       ptr = tmp;
    } 
    head->next = prev;
    return;
}

unsigned int list_length(struct list *head){
    int count = -1;
    while (head){
        head = head->next;
        count++;
    }
    return count;
}


void updateOp(unsigned int opType, char opChar, unsigned int opPos){
   for(i=0;i<4;i++){
      opHistory[i] = opHistory[i+1];
      opChars[i] = opChars[i+1];
      opPositions[i] = opPositions[i+1];
   }
   opHistory[i] = opType;
   opChars[i] = opChar;
   opPositions[i] = opPos;
}

void undo(struct list *head, unsigned int times){
   for(i=0;i<times;i++){
      if(opHistory[4-i]!=0){
      	if(opHistory[4-i]==1){
      		delete(head,opPositions[4-i]);
      	}else if(opHistory[4-i]==2){
      		insert(head,opPositions[4-i],opChars[4-i]);
      	}
      }
   }
   resetOp();
}

void resetOp(){
	for(i=1;i<5;i++){
      opHistory[i] = opHistory[i-1];
      opChars[i] = opChars[i-1];
      opPositions[i] = opPositions[i-1];
   }

   opHistory[0] = 0;
   opChars[0] = ' ';
   opPositions[0] = 0;
}