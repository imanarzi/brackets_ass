#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line);
	int r = -1; 
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            	Bracket b;
		//b = malloc(sizeof(Bracket));
	    	if(next == '(')
			b.type = 0;
		if(next == '[')
			b.type = 1;
		if(next == '{')
			b.type = 2;
            	push(opening_brackets_stack, b);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
       		if(next == ')' && pop(opening_brackets_stack).type != 0){
			r = position;
			break;
		}
		if(next == ']' && pop(opening_brackets_stack).type != 1){
			r = position;
			break;
		}
		if(next == '}' && pop(opening_brackets_stack).type != 2){
			r = position;
			break;
		}
        	//break;
	}
    }

    // Printing answer, write your code here
	printf("My result is:\n");
	if(r >= 0)
                printf("%d\n", r + 1);
	else if(!isEmpty(opening_brackets_stack))
                printf("%d\n", pop(opening_brackets_stack).position + 1);
	else
		printf("Success\n"); 
    return 0;
}
