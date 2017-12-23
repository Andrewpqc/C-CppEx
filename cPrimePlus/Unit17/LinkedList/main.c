#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (void){
    NodePtr head=create_list();
    for(int i=0;i<10;i++){
        Item tempitem={"sdf",i};
        add_node_at_rear(head,tempitem);
    }
    show(head);






    return 0;
}