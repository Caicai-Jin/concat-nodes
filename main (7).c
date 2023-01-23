#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct strnode{
    char str[5];
    struct strnode * next;
};



struct strnode * creat_node(char str[], struct strnode * next);
struct strnode * free_node(struct strnode * node);
void concat_nodes(struct strnode * head, char * str);

int main(){
    
    struct strnode * node1= creat_node("abc",NULL);
    assert(node1->next==NULL);
    assert(strcmp(node1->str, "abc")==0);
    
    struct strnode * node2=creat_node("def",node1);
    assert(node2->next==node1);
    assert(strcmp(node2->str, "def")==0);
    
    struct strnode * node3=creat_node("ghi",node2);
    assert(node3->next==node2);
    assert(strcmp(node3->str, "ghi")==0);
    
    assert(strcmp(node3->next->next->str, "abc")==0);
    
    assert(free_node(node3)==node2);
    assert(free_node(node2)==node1);
    assert(free_node(node1)==NULL);
    
    struct strnode * new;
    for (int i=0;i<26;i++){
        char now=90-i;
        char letter[]={now, '\0'};
        if (i==0){
            struct strnode * head=malloc(sizeof(*head));
            strcpy(head->str,letter);
            head->next=NULL;
            new=head;
            printf("%s", head->str);
        }
        else{
            struct strnode * head=malloc(sizeof(*head));
            strcpy(head->str,letter);
            head->next=new;
            printf("%s", head->str);
            new=head;
        }
    }
    printf("\nAll the cases are passed!\n");
    
}

struct strnode * creat_node(char str[], struct strnode * next){
    struct strnode * node=(struct strnode *) malloc(sizeof(struct strnode));
    if(node==NULL){
        return NULL;
    }
    node->next =next;
    strcpy(node->str, str);
    return node;
    
}

struct strnode * free_node(struct strnode * node){
    struct strnode * next=node->next;
    free(node);
    return next;
}

void concat_nodes(struct strnode * head, char * str){
    
    while(head!=NULL){
        strcpy(str, head->str);
        str=str+strlen(head->str);
        if(head->next!=NULL){
            strcpy(str, " ");
            str++;
        }
        head=head->next;
        
    }
    strcpy(str, " ");
}






