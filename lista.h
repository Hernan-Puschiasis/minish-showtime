struct list_elem {           
    char *str;            
    struct list_elem *next;  
    struct list_elem *prev;  
};




struct list {                
    int count;              
    struct list_elem *leftmost;  
    struct list_elem *rightmost;
};




extern struct list *list_create(void);
extern struct list_elem *list_append(struct list *list, char *s);
extern struct list_elem *list_pop_left(struct list *list);
extern void list_print(struct list *deque);
extern void list_print_with_space(struct list *list);
extern struct list_elem *list_append_alphabetically(struct list *list, char *s);