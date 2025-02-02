#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>



typedef struct node {
    int index;
    float min;
    float max;
    struct node *next;
} node_t;



void print_node(node_t *node){
    bool cont = true;
    printf("Printing Database Contents \n");
    //int i = 0;
    if (node->next == NULL) {
        printf("Empty list");
    }
    node_t *to_print = node->next;
    
    printf("day ");
    printf("min ");
    printf("max\n");
    while(cont){
        //printf("Node number: %d", i);
        printf("%d  ", to_print->index);
        printf("%f  ", to_print->min);
        printf("%f  \n", to_print->max);
        if(to_print->next){
            to_print = to_print->next;
        }
        else{
            return;
        }
        

    }
}


void insert(node_t *list, int index, float min, float max) {
    node_t *current = list;
    for (int i = 1; i <= 31; i++) {
        if(current->index == i) {
            current->min = min;
            current->max = max;
            return;
        } else if(current->next != NULL && current->next->index > index) {
            printf("HELLO\n");
            node_t* new_node =  malloc(sizeof(node_t));
            new_node->next = current->next;
            current->next = new_node;
            new_node->index = index;
            new_node->min = min;
            new_node->max = max;
            return;
        } else if(current->next == NULL) {
            node_t* new_node =  malloc(sizeof(node_t));
            current->next = new_node;
            new_node->index = index;
            new_node->min = min;
            new_node->max = max; 
            return;
        }

        current = current->next;
    }   
}

void delete_list(node_t *node) {
    node_t *current = node;
    while(current->next != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(node);
}





int main(int argc, char const *argv[]){
    bool cont = true;
    char line[256];
    node_t *node = malloc(sizeof(node_t));
    node->next = NULL;
    node->index = 200;
    char c;
    int index;
    float min, max;


    while(cont){
        printf("Enter command: ");
        c = 0;
        //scanf("%c %i %f %f ", &c, &index, &min, &max);
        if (!fgets(line, sizeof(line), stdin)) {
            // If we fail to get a line, break or handle error
            break;
        }

        // Try to parse up to four items (command + 3 arguments)
        int count = sscanf(line, "%c %d %f %f", &c, &index, &min, &max);
        
        printf("This is c: %d \n", c);
        //do stuff
        switch (c)  {
        case 'A':
            // We need at least 4 tokens here: c, index, min, max
            if (count == 4) {
                insert(node, index, min, max);
                print_node(node);
                //printf("A command: index = %d, min = %f, max = %f\n", index, min, max);
            } else {
                printf("Invalid number of arguments for 'A'\n");
            }
            break;
        case 'P':
            if (count >= 1) {
                printf("P command: printing data...\n");
                print_node(node);
            } else {
                printf("Invalid number of arguments for 'P'\n");
            }
            break;
        case 'Q':
            // 'Q' might be just the command, no extra arguments
            printf("Shutting down...\n");
            delete_list(node);
            cont = false;
            break;
            
        case 'D':
        printf("Print D \n");
            /* code */
            // 'D' might need only 1 extra argument (the index)
            if (count >= 2) {
                printf("Deleting at index...\n");
                node_t *current = node;
                printf("Deleting day %d\n", index);
                // your delete logic
                if (current->next == NULL) {
                    free(current);
                }
                while (current->next != NULL) {
                    if (current->next->index == index){
                    node_t *to_free = current->next;
                    current->next = current->next->next;
                    free(to_free);
                    }
                    else{
                        current = current->next;
                    }
                }
            } else {
                printf("Invalid number of arguments for 'D'\n");
            }
            cont = false;
            break;
        default:
            printf("Invalid input... shutting down \n");
            cont = false;
        }
        

    }
    return 1;
}