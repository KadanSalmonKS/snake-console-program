#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
//short cuts
#define CLEAR system("cls")
#define P printf("\n\nhere\n"); getch()
#define ch(c) (printf("\n\n%s\n",c)); getch()
#define face 2 //smiling face
#define body '*'

enum Colors { //colors to be used 
	black=0,
	blue=1,
	green,
	blu_gree, 
	red, 
	purple,
	yellow, 
	grey, 
	dgrey, 
	hblue, 
	hgreen,
	cyan, 
	hred,
	hpurple, 
	hyellow,
	hwhite 
};

enum Direc{ // direction of the snake
	UP = 1,
	DOWN,//2
	LEFT,//3
	RIGHT//4
};

 struct snake_band {
 	int x;//x axis position of this band
	int y;//y axis position of this band
	int direction;
	struct snake_band *next;//new band on snake
};

struct playfield{
	int tleft;//top left
	int tright;//top right
	int bleft;//bottom left
	int bright;//bottom right
	
};

int snake_length(struct snake_band *head);//accept the first band of the snake

struct snake_band * initialize_snake(struct snake_band *head);//accept the first band of the snake and return the head node
struct snake_band * move_right(struct snake_band *head);
struct snake_band * move_left(struct snake_band *head);
struct snake_band * move_up(struct snake_band *head);
struct snake_band * move_down(struct snake_band *head);

struct snake_band * extend_snake(struct snake_band *head);
int envi_pri(struct playfield *en);

int gotoxy(int x, int y);
int delay(int millisec);//delay
void textcolor(int color);
void textbackground(int color);
void clrscr(void);
void hidecursor(void);
void showcursor(void);

 
	
int main(int argc, char *argv[])
{
	struct snake_band *curr_head,*newnode,*snake_head;
	struct playfield *pf;
	
	int x=0,num=0,curr_dir=0;
	int pre_state= -1 ;
	char key;
	
	
	snake_head = (struct snake_band *)malloc(sizeof(struct snake_band));//keep the head of the pointer on the outside
	pf = (struct playfield *)malloc(sizeof(struct playfield));//keep the head of the pointer on the outside
	
	//snake_head = curr_head;
	//curr_head->next = NULL;
	
	//curr_head->x = 9;
	//curr_head->y = 9;
	
	``
	//update_node();
	
	//printf("the value in head is %d\n",curr_head->data);
	//print_node();
	//delay(5000);
	
	//snake_head = 
	
	
	//delay(2000);
	//CLEAR;
	//move_right(snake_head);
	hidecursor();
	
	
	initialize_snake(snake_head);
	
//	num = snake_length(snake_head);
	//P;
	//printf("\nthe size of the snake is : %d\n",num);
	//extend_snake(snake_head,snake_head);
	curr_dir = RIGHT;
	while(1)
	{
		
		//delay(2000);
		if(kbhit())
		{
			key = getch();
			
			
			switch(key)
			{
				case 72 :
					if(curr_dir != DOWN && curr_dir != UP )
						curr_dir = UP;
					
				break;
				
				case 80 :
					if(curr_dir != UP && curr_dir != DOWN )
						curr_dir = DOWN;
				break;
				
				case 77 :
					if(curr_dir != LEFT && curr_dir != RIGHT )
						curr_dir = RIGHT;
				break;
				
				case 75 :
					if(curr_dir != RIGHT && curr_dir != LEFT )
						curr_dir = LEFT;
				break;
				
				//case 'e' :
				//	curr_dir = 9;
				//break;
				
			}
			
		
			if(key == 'e')//if want to extend snake
			{
				//clrscr();
				extend_snake(snake_head);
				//break;
				
			}
			if(key == 'p')//if want to pause
			{
				if(pre_state == -1)//if snake is not paused
				{
					pre_state = curr_dir;
					curr_dir = 0;
				}
				else if(pre_state != -1)//if snake is paused
				{
					curr_dir = pre_state;
					pre_state = -1;
					
				}
				
				
			}
		}
		switch(curr_dir)
		{
			case RIGHT :
				clrscr();
				move_right(snake_head);
			break;
			
			case LEFT :
				clrscr();
				move_left(snake_head);
			break;
				
			case UP :
				clrscr();
				move_up(snake_head);
			break;
				
			case DOWN :
				clrscr();
				move_down(snake_head);
			break;
			//case 9 :
				
				//extend_snake(snake_head);
				//clrscr();
				//move_right(snake_head);
			//break;
				
		}
		delay(50);
		
	}
	
	num = snake_length(snake_head);
	P;
	//printf("\nthe size of the snake is : %d\n",num);
	
	//P;
	//print_snake(snake_head,num);
	//while(x < 5)
	//{
	//	curr_head = update_snake(curr_head);
	//	num = snake_length(old_head);
		//gotoxy(9,9+x);
		//printf("@");
		//print_snake(old_head,num);
		
		//printf("\nthe value in old x and y is %d and %d\n",(curr_head->x),(curr_head->y));
	//	x++;
	//	printf("the value in current head is %d\n",curr_head->data);
//	}
	//print_snake(old_head,num);
	//printf("\nthe value in current x and y is %d and %d\n",old_head->x,old_head->y);
	//printf("\nthe value in current x and y is %d and %d\n",curr_head->x,curr_head->y);
	
	
	//SetColor(4,0);
 	free(snake_head);
 	free(pf);
	return 0;
}





int envi_pri(struct playfield *en)
{
	
}


/*
IMPORTANT SNAKE MOVEMENT FUNCTIONS
***************************************************************
* These are the functions responsible for performing snake    *
* movements    : 											  *
* 				start 										  *
* 				move left,   								  *
* 				move right,									  *
* 				move up,     								  *
* 				move down 									  *
*				               					 			  *
***************************************************************/

struct snake_band * extend_snake(struct snake_band *head)
{
	int x_a,y_a,x=0;
	int len;
	struct snake_band *head_band,*sec_band,*thir_band,*new_band;//for linked list
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	new_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	head_band = head;//leat head_band point to the space allocated to store the head of the snake
	
	while(head_band->next != NULL){
		head_band = head_band->next;
	}
	
	new_band->x = (head_band->direction == RIGHT) ? head_band->x - 1 : ((head_band->direction == LEFT) ? head_band->x + 1 :  ((head_band->direction == UP) ? head_band->x : (head_band->direction == DOWN) ? head_band->x : head_band->x));
	
	new_band->y = (head_band->direction == RIGHT) ? head_band->y : (head_band->direction == LEFT) ? head_band->y : (head_band->direction == UP) ? head_band->y + 1 : (head_band->direction == DOWN) ? head_band->y - 1 : head_band->y - 1;
	new_band->direction = (head_band->direction == RIGHT) ? RIGHT : (head_band->direction == LEFT) ? LEFT : (head_band->direction == UP) ? UP : (head_band->direction == DOWN) ? DOWN : DOWN;
	new_band->next = NULL;
	
	head_band->next = new_band;
	
	
	return head_band;//return pointer to head of snake
}
struct snake_band * move_down(struct snake_band *head)
{
	int x_a,y_a,x=0;
	int len;
	int prev_x,prev_y,prev_dir,tmp1,tmp2,tmp3;
	
	struct snake_band *head_band,*sec_band,*thir_band,*old;//for linked list
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	
	head_band = head;//leat head_band point to the space allocated to store the head of the snake

	len = snake_length(head_band);
	for(x=0;x<len;x++)//iterate through the entire linked list
	{
		//print data
		tmp1 = head_band->x;
		tmp2 = head_band->y;
		tmp3 = head_band->direction;
		
		head_band->x = (x==0) ? head_band->x : prev_x;
		head_band->y = (x==0) ? (head_band->y) + 1 : prev_y;
		head_band->direction = (x==0) ? DOWN : prev_dir;
		
		prev_x = tmp1;
		prev_y = tmp2;
		prev_dir = tmp3;
		
		x_a = head_band->x;
		y_a = head_band->y;
		gotoxy(x_a,y_a);
		printf("%c",(x == 0) ? face : body);
		//end print data
		head_band = head_band->next;
	}
	
	
	return head_band;//return pointer to head of snake
}
struct snake_band * move_up(struct snake_band *head)
{
	int x_a,y_a,x=0;
	int len;
	int prev_x,prev_y,prev_dir,tmp1,tmp2,tmp3;
	
	struct snake_band *head_band,*sec_band,*thir_band,*old;//for linked list
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	
	head_band = head;//leat head_band point to the space allocated to store the head of the snake

	len = snake_length(head_band);
	for(x=0;x<len;x++)//iterate through the entire linked list
	{
		//print data
		tmp1 = head_band->x;
		tmp2 = head_band->y;
		tmp3 = head_band->direction;
		
		head_band->x = (x==0) ? head_band->x : prev_x;
		head_band->y = (x==0) ? (head_band->y) - 1 : prev_y;
		head_band->direction = (x==0) ? UP : prev_dir;
		
		prev_x = tmp1;
		prev_y = tmp2;
		prev_dir = tmp3;
		
		x_a = head_band->x;
		y_a = head_band->y;
		gotoxy(x_a,y_a);
		printf("%c",(x == 0) ? face : body);
		//end print data
		head_band = head_band->next;
	}
	
	
	return head_band;//return pointer to head of snake
}

struct snake_band * initialize_snake(struct snake_band *head )//accept space for head and return the head node 
{
	int x_a,y_a,x=0;
	int len;
	struct snake_band *head_band,*sec_band,*thir_band,*old;//for linked list
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	sec_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	thir_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	old = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	//head = NULL;
	head_band = head;//leat head_band point to the space allocated to store the head of the snake

	//initialize the head of the snake
	head_band->x = 15;
	head_band->y = 15;
	head_band->direction = RIGHT;
	
	
	
	//initialize the sec band of the snake
	sec_band->x = (head_band->x)-1;
	sec_band->y = head_band->y;
	sec_band->direction = head_band->direction;
	
	//initialize the thir band of the snake
	thir_band->x = (sec_band->x)-1;
	thir_band->y = sec_band->y;
	thir_band->direction = sec_band->direction;
	
	//move to the next node in the list
	head_band->next = sec_band;//next in list from head is sec
	//head_band = sec_band;//let head point to the second band of the snake
	sec_band->next = thir_band;//let its next value = the address of third band
	thir_band->next = NULL;//let head point to the third band of the snake
	
	
	
	
	//print to screen

	//system("mode 1000");
	len = snake_length(head_band);
	for(x=0;x<len;x++)//iterate through the entire linked list
	{
		//print data
		x_a = head_band->x;
		y_a = head_band->y;
		gotoxy(x_a,y_a);
		printf("%c",(x == 0) ? face : body);
		//end print data
		head_band = head_band->next;
	}
	
	
	
	return head_band;//return pointer to head of snake
	
}


int snake_length(struct snake_band *head)//count the num of bands this snake has
{
	int x=0;
	
	struct snake_band *curr;//current node 
	curr = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	curr = head;
	do
	{
		x++;
		curr = curr->next;//move to next node
	}while(curr->next != NULL);//if the next value in this node is NULL then stop
	return x+1;//if the next pointer in this node is NULL then this node will not be counted as data until the Next pointer is filled(if its filled)
	//so lets assume that if this NULL is reached, then count it as 1 extra node
}

struct snake_band * move_left(struct snake_band *head)
{
	int x_a,y_a,x=0;
	int len;
	int prev_x,prev_y,prev_dir,tmp1,tmp2,tmp3;
	
	struct snake_band *head_band,*sec_band,*thir_band,*old;//for linked list
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	
	//head = NULL;
	head_band = head;//leat head_band point to the space allocated to store the head of the snake

	len = snake_length(head_band);
	for(x=0;x<len;x++)//iterate through the entire linked list
	{
		//print data
		tmp1 = head_band->x;
		tmp2 = head_band->y;
		tmp3 = head_band->direction;
		
		head_band->x = (x==0) ? (head_band->x) - 1 : prev_x;
		head_band->y = (x==0) ? head_band->y : prev_y;
		head_band->direction = (x==0) ? LEFT : prev_dir;
		
		prev_x = tmp1;
		prev_y = tmp2;
		prev_dir = tmp3;
		
		x_a = head_band->x;
		y_a = head_band->y;
		gotoxy(x_a,y_a);
		printf("%c",(x == 0) ? face : body);
		//end print data
		head_band = head_band->next;
	}
	
	
	return head_band;//return pointer to head of snake
}

struct snake_band * move_right(struct snake_band *head)
{
	int x_a,y_a,x=0;
	int len;
	int prev_x,prev_y,prev_dir,tmp1,tmp2,tmp3;
	
	struct snake_band *head_band,*sec_band,*thir_band,*old;//for linked list
	
	
	head_band = (struct snake_band *)malloc(sizeof(struct snake_band));//reserve space for data
	
	//head = NULL;
	head_band = head;//leat head_band point to the space allocated to store the head of the snake

	len = snake_length(head_band);
	for(x=0;x<len;x++)//iterate through the entire linked list
	{
		//print data
		tmp1 = head_band->x;
		tmp2 = head_band->y;
		tmp3 = head_band->direction;
		
		head_band->x = (x==0) ? (head_band->x) + 1 : prev_x;
		head_band->y = (x==0) ? head_band->y : prev_y;
		head_band->direction = (x==0) ? RIGHT : prev_dir;
		
		prev_x = tmp1;
		prev_y = tmp2;
		prev_dir = tmp3;
		
		x_a = head_band->x;
		y_a = head_band->y;
		gotoxy(x_a,y_a);
		printf("%c",(x == 0) ? face : body);
		//end print data
		head_band = head_band->next;
	}
	
	
	return head_band;//return pointer to head of snake
}




/*
IMPORTANT CONSOLE FUNCTIONS
***************************************************************
* These are the functions responsible for performing console  *
* manipulation : 											  *
* 				clear_screen,								  *
* 				delay, 										  *
* 				hide cursor, 								  *
* 				text and background color					  *
* 				x and y axis position						  *
***************************************************************/

int gotoxy(int x, int y)
{
	HANDLE scr;
	scr = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = {x,y};
	SetConsoleCursorPosition(scr,Position);
	return 0;
}


int delay(int millisec)
{
	Sleep(millisec);//windows.h API
}

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color & 0x0F));
}
 
void textbackground(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((color & 0x0f) << 4));
}
void clrscr(void) {
    COORD topLeft = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', dwConSize,topLeft, &cCharsWritten);
    FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes,dwConSize, topLeft, &cCharsWritten);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);
}
void hidecursor(void)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void showcursor(void)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 0;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
