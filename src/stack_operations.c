#include "push_swap.h"

int numb_stack_size(char **numbers)
{
    size_t	length;

	length = 0;
	while (numbers[length] != NULL)
	{
		length++;
	}
	return (length);
}

void *initiallize_stack(int capacity, int is_array) 
{
    if (is_array)
    {
        t_stack_array *stack = malloc(sizeof(t_stack_array));
        if (!stack)
        return NULL;
      
        stack->arr = malloc(capacity * sizeof(int));    
        if (!stack->arr)
        return (free(stack), NULL);

        stack->size = 0;
        stack->capacity = capacity;
        return stack;
    }
    else
    {
        t_stack_list *stack = malloc(sizeof(t_stack_list));
        if (!stack)
            return NULL;
        stack->top = NULL;
        stack->bottom = NULL;
        stack->size = 0;
        return (stack);
    }
}

void push(void *stack, int value, int is_array)
{   
    if (is_array == 1)
    {
        t_stack_array *array_stack = (t_stack_array *)stack;
        int i = array_stack->size;
        if (array_stack->size == array_stack->capacity)
        {
            printf("Stack overflow");
            return;
        }
        //printf("i = %i\n", i);
        while( i > 0)
        {
            array_stack->arr[i] = array_stack->arr[i - 1];
            i--;
        }        
        array_stack->arr[0] = value;
        array_stack->size++;        
    }
    else
    {
        t_stack_list *list_stack = (t_stack_list *)stack;
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
        {
            printf("Error: Memory allocation failed\n");
            return;
        }
        new_node->value = value;
        new_node->next = list_stack->top;
        new_node->prev = NULL;

        if (list_stack->top) 
        {
            list_stack->top->prev = new_node;
        } 
        else
        {
            list_stack->bottom = new_node;
        }

        list_stack->top = new_node;
        list_stack->size++;
    }
}

int pop(void *stack, int is_array)
{
    if (is_array == 1)
    {
        int i = 0;
        t_stack_array *array_stack = (t_stack_array *)stack;

        if (array_stack->size == 0) 
        {
            //printf("Stack Underflow\n");
            return -1; // Indicating an error
        }
        int top_value = array_stack->arr[0];

        while (i < array_stack->size)
        {
            array_stack->arr[i] = array_stack->arr[i + 1];
            i++;
        }
        array_stack->size--;
        return (top_value);
    }
    else
    {
        t_stack_list *list_stack = (t_stack_list *)stack;
        if (list_stack->top == NULL || list_stack->size == 0) // (!list_stack->top)
        {
            //printf("Stack Underflow\n");
            return -1;
        }            
        t_node *temp = list_stack->top;
        int value = temp->value;

        list_stack->top = temp->next;  

        if (list_stack->top) 
        {
            list_stack->top->prev = NULL; // Remove the link to the popped node
        } 
        else 
        {
            list_stack->bottom = NULL; // If the stack is now empty
        }

        free(temp);    
        list_stack->size--;
        return value;
    }
}

void append_node(t_stack_list *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (!stack->top) 
    { // If the stack is empty, new node becomes the top
        stack->top = new_node;
    } 
    else 
    {
        t_node *current = stack->top;
        while (current->next) { // Traverse to the last node
            current = current->next;
        }
        current->next = new_node; // Append the new node
        new_node->prev = current;
    }
    stack->size++;
}

void fill_stack_from_args(void *stack, int nums_size, char **numbers, int is_array)
{
    int i;

    i = 0;
    if (is_array)
    {      
        t_stack_array *stack_array = (t_stack_array *)stack;            
        if (numbers[i] == NULL)
            print_error();
        while (i < nums_size)
        {
            int value = atoi(numbers[i]);
            stack_array->arr[i] = value;
            stack_array->size++;
            i++;
        }
    }
    else
    {
        while (i < nums_size)
        {        
            if (numbers[i] == NULL)
                print_error();
            int value = atoi(numbers[i]);
            append_node(stack, value);
            i++;
        }    
    }
}

/*void fill_stack_from_args(void *stack, int nums_size, char **numbers, int is_array)
{
    int i;

    i = 0;
    while (i < nums_size)
    {        
        if (numbers[i] == NULL)
            print_error();
        int value = atoi(numbers[i]);
        push(stack, value, is_array);
        i++;
    }    
}*/
