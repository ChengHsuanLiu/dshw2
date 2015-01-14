#include <stdio.h>
#include <stdlib.h>

/*建立struct
 --------------------------*/
typedef struct node{
    
    struct node *lchild;
    int data;
    struct node *rchild;
    
}tree_node;



typedef tree_node *tree_pointer;



/*走訪全部的節點
 -------------------------------*/
void inorder(tree_pointer root){
    
    
    
    if(root){
        
        inorder(root->lchild);
        printf("%d\n", root->data);
        inorder(root->rchild);
        
        
    }
    
}


/*搜尋節點
 ---------------------------------*/
tree_pointer search(tree_pointer root,int key){
    
    tree_pointer current;
    current = root;
    while(current){
        if(key == current->data)return current;
        if (key < current->data) {
            current = current->lchild;
        }
        else
            current = current->lchild;
    }
    
    return NULL;
}

/*刪除節點
 ---------------------------------------*/

tree_pointer delete(tree_pointer root){
    
    tree_pointer current,previous;
    
    if (!root)
    {		/* code */
        printf("樹是空的，無資料可以刪除\n");
        return root;
        
    }
    else{
        
        current = root;
        while(current->lchild){
            
            previous = current;
            current = current->lchild;
        }
        
        if(current->rchild){
            
            if (current==root) {
            
                root = current->rchild;
                printf("已刪除%d這個資料的節點\n", current->data);
                free(current);
                
            }
            else{
                previous->lchild = current->rchild;
                printf("已刪除%d這個資料的節點\n", current->data);
                free(current);
            
            }
            
        }
        else{
            previous->lchild = NULL;
            printf("已刪除%d這個資料的節點\n", current->data);
            free(current);
            
        }
        return root;
        
        
    }
}


/*插入節點
 -----------------------------------*/


tree_pointer insert(tree_pointer root,int key){
    
    tree_pointer ptr,current,previous;
    if (search(root,key))
    {
        /* code */
        printf("資料已經存在，無法再插入節點！\n");
        return root;
    }
    
    ptr = (tree_pointer)malloc(sizeof(tree_node));
    ptr->data = key;
    ptr->lchild = NULL;
    ptr->rchild = NULL;
    
    if (!root)
    {
        /* code */
        root = ptr;
        printf("插入節點成功！增加%d這筆資料。\n",key);
    }
    else{
        
        current = root;
        while(current){
            previous = current;
            if (ptr->data < current->data)
            {
                /* code */
                current = current->lchild;
                
            }
            else{
                current = current->rchild;
                
            }
        }
        
        
        if (ptr->data < previous->data)
        {
            /* code */
            previous->lchild = ptr;
            printf("插入節點成功！增加%d這筆資料。\n",key);
        }
        else {
            previous->rchild = ptr;
            printf("插入節點成功！增加%d這筆資料。\n",key);
        }
    }
    return root;
    
    
}



/*Main
 ------------------------*/

int main()
{
    /* code */
    
    int order=1,numb;
    int next = 0;
    
    tree_pointer root = NULL;
    
    while( order!=0 ){
        
        
        if(next == 0)
            printf("這是一個樹狀資料結構的程式，請輸入以下指令來控制它\n");
        else
            printf("您已經完成了上一個指令，接著輸入下一個指令吧！\n");
        
        
        
        printf("1:Create an empty binary search tree. \n2:Insert a key into a binary search tree \n3.Remove the key with the lowest value. \n4.Print out all keys in increasing order. \n0:Exit this program.\n");
        scanf("%d", &order);
        
        switch(order){
                
            case 1:
                
                printf("一顆空的樹已經創立！\n");
                
                break;
                
            case 2:
                
                printf("請輸入您想要插入的數值:");
                scanf("%d",&numb);
                root = insert(root, numb);
                
                break;
                
            case 3:
                
                root = delete(root);
                
                break;
                
            case 4:
                printf("開始進行印出作業...\n");
                inorder(root);
                printf("印出作業結束。\n");
                
                break;
                
            case 0:
                break;
                
            default:
                printf("您輸入的指令無效，請依照指示輸入有效的指令。");
                break;
                
                
        }
        
        next++;
        
    }
    
    
    
    return 0;
}





