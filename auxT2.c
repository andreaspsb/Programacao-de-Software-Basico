mymemory_t *mymemory_init(size_t size)
{
    mymemory_t *memory = (mymemory_t *)malloc(sizeof(mymemory_t));
    if (!memory)
    {
        return NULL;
    }
    memory->pool = malloc(size);
    if (!memory->pool)
    {
        free(memory);
        return NULL;
    }
    memory->total_size = size;
    memory->head = NULL;
    return memory;
}
void *mymemory_alloc(mymemory_t *memory, size_t size)
{
    if (size == 0 || size > memory->total_size)
    {
        return NULL;
    }

    allocation_t *new_allocation = (allocation_t *)malloc(sizeof(allocation_t));
    if (!new_allocation)
    {
        return NULL;
    }

    new_allocation->start = memory->pool;
    new_allocation->size = size;
    new_allocation->next = memory->head;
    memory->head = new_allocation;

    return new_allocation->start;
}
void mymemory_free(mymemory_t *memory, void *ptr)
{
    allocation_t *current = memory->head;
    allocation_t *previous = NULL;

    while (current != NULL)
    {
        if (current->start == ptr)
        {
            if (previous == NULL)
            {
                memory->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
void mymemory_display(mymemory_t *memory)
{
    allocation_t *current = memory->head;
    while (current != NULL)
    {
        printf("Allocation: %p, Size: %zu\n", current->start, current->size);
        current = current->next;
    }
}
void mymemory_stats(mymemory_t *memory)
{
    size_t total_allocated = 0;
    allocation_t *current = memory->head;
    while (current != NULL)
    {
        total_allocated += current->size;
        current = current->next;
    }
    printf("Total allocated: %zu bytes\n", total_allocated);
}
void mymemory_cleanup(mymemory_t *memory)
{
    allocation_t *current = memory->head;
    while (current != NULL)
    {
        allocation_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(memory->pool);
    free(memory);
}
void mymemory_release(mymemory_t *memory)
{
    mymemory_cleanup(memory);
}