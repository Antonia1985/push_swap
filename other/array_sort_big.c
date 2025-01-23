#include "push_swap_initial.h"

/*
** A simple bubble sort to help find chunk boundaries
** (You could also do quicksort or any standard sort algorithm).
*/
static void sort_array(int *arr, int size)
{
    int temp;
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

/*
** Given stack A, we create 'num_chunks' chunk boundaries by sorting
** the array and slicing it evenly (the last chunk may have extra elements).
**
** chunk_bounds is of size 2 * num_chunks. For each chunk i:
**   - chunk_bounds[2*i]   = min_val (start of chunk range)
**   - chunk_bounds[2*i+1] = max_val (end of chunk range)
*/
static void create_chunks(t_stack_array *a, int num_chunks, int *chunk_bounds)
{
    int  i;
    int  chunk_size;
    int *sorted_arr;

    sorted_arr = malloc(sizeof(int) * a->size);
    if (!sorted_arr)
    {
        ft_printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < a->size)
    {
        sorted_arr[i] = a->arr[i];
        i++;
    }
    sort_array(sorted_arr, a->size);

    chunk_size = a->size / num_chunks;
    i = 0;
    while (i < num_chunks)
    {
        chunk_bounds[2 * i] = sorted_arr[i * chunk_size];
        if (i == num_chunks - 1)
            chunk_bounds[2 * i + 1] = sorted_arr[a->size - 1];
        else
            chunk_bounds[2 * i + 1] = sorted_arr[(i + 1) * chunk_size - 1];
        i++;
    }
    free(sorted_arr);
}

/*
** This helper finds how many elements (in A) fit in the given min_val..max_val range.
** We do that so that we know how many elements we expect to push to B for this chunk.
*/
static int count_elements_in_range(t_stack_array *a, int min_val, int max_val)
{
    int i;
    int count = 0;

    i = 0;
    while (i < a->size)
    {
        if (a->arr[i] >= min_val && a->arr[i] <= max_val)
            count++;
        i++;
    }
    return (count);
}

/*
** Improved push for each chunk:
**   - We keep pushing from A to B all elements that lie in [min_val .. max_val].
**   - If the top of A is in range, we pb() immediately.
**   - If the bottom of A is in range, we rra() then pb().
**   - Otherwise, we rotate A (ra) to find in-range elements.
**   - [Key optimization] If the element is in the lower half of the chunk range,
**     we push to B, then immediately rb() so that smaller chunk elements collect
**     at the bottom, leaving bigger elements near the top. This reduces the final sorting on B.
*/
static void push_values_of_each_chunk(t_stack_array *a, t_stack_array *b,
                                      int min_val, int max_val)
{
    int to_push;
    int pushed = 0;

    to_push = count_elements_in_range(a, min_val, max_val);
    while (pushed < to_push && a->size > 0)
    {
        // Top is in range -> push it
        if (a->arr[0] >= min_val && a->arr[0] <= max_val)
        {
            pb(b, a);
            // If we just pushed a "smaller half" number, rotate B so it goes to bottom.
            // We'll define "smaller half" as below the midpoint of [min_val..max_val].
            if (b->arr[0] < (min_val + max_val) / 2 && b->size > 1)
                rb(b);
            pushed++;
        }
        // Bottom is in range -> reverse rotate A then push
        else if (a->arr[a->size - 1] >= min_val && a->arr[a->size - 1] <= max_val)
        {
            rra(a);
            pb(b, a);
            if (b->arr[0] < (min_val + max_val) / 2 && b->size > 1)
                rb(b);
            pushed++;
        }
        else
        {
            // If top of B is bigger than second of B, we might do rr
            // (some people do a "double rotate" if it's beneficial).
            // For brevity, let's just ra(a) here to find in-range faster.
            ra(a);
        }
    }
}

/*
** We find the position of the maximum element in B.
*/
static int find_max_pos(t_stack_array *b)
{
    int max;
    int max_position;
    int i;

    if (b->size == 0)
        return (0);
    max = b->arr[0];
    max_position = 0;
    i = 1;
    while (i < b->size)
    {
        if (b->arr[i] > max)
        {
            max = b->arr[i];
            max_position = i;
        }
        i++;
    }
    return (max_position);
}

/*
** Final step: B is (roughly) full of chunked elements. We now push them back to A
** in descending order so that A ends up sorted ascending. We do so by:
**   - finding the max in B
**   - rotating B forward or backward to bring that max on top
**   - pa() it to A
**   - repeat until B is empty
**   - small optimization: if B.size <= 3, just sort_3_desc(b) then push all
*/
static void sort_stack_b_descending_and_push(t_stack_array *b, t_stack_array *a)
{
    int i;
    int max_pos;
    int half_size;

    while (b->size > 0)
    {
        if (b->size <= 3)
        {
            sort_3_desc(b); // user-provided function for 3 or fewer elements in B
            while (b->size)
                pa(a, b);
            break;
        }
        max_pos = find_max_pos(b);
        half_size = b->size / 2;

        if (max_pos <= half_size)
        {
            i = 0;
            while (i < max_pos)
            {
                rb(b);
                i++;
            }
        }
        else
        {
            i = b->size;
            while (i > max_pos)
            {
                rrb(b);
                i--;
            }
        }
        pa(a, b);
    }
}

/*
** The main big-sort function:
**   1. Decide on a # of chunks (for ~100 numbers, 5 or 6 chunks is a decent pick)
**   2. Create chunk boundaries
**   3. For each chunk, push chunk-range elements from A to B (with the half-chunk optimization)
**   4. Finally, sort B in descending order, pushing everything back to A
*/
void array_sort_big(t_stack_array *a, t_stack_array *b)
{
    int num_chunks = 4; // try 5 or 6 for ~100 elements
    int *chunk_bounds;
    int i;

    chunk_bounds = malloc(sizeof(int) * 2 * num_chunks);
    if (!chunk_bounds)
    {
        ft_printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // 1. Find chunk boundaries
    create_chunks(a, num_chunks, chunk_bounds);

    // 2. Push chunk by chunk
    i = 0;
    while (i < num_chunks)
    {
        int min_val = chunk_bounds[2 * i];
        int max_val = chunk_bounds[2 * i + 1];

        push_values_of_each_chunk(a, b, min_val, max_val);
        i++;
    }

    // 3. Sort B in descending order and push back to A
    sort_stack_b_descending_and_push(b, a);

    free(chunk_bounds);
}
