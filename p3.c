#include<stdio.h>
#include<stdlib.h>
#include<string.h>//
#include"recognition.h"
#include"signup.h"
#include"login.h"
#include"loginPARTtwo.h"
#include"posting.h"
#include"like.h"
#include"users.h"
typedef struct sn_user sn_user;
typedef struct sn_msg sn_msg;
struct sn_user{
    char* username; //=(char*)malloc(100*sizeof(char));
    char* password; //=(char*)malloc(100*sizeof(char));
    struct sn_user *next;
};
struct sn_msg{
    char* post_txt;//mohtava
    char* username;
    int post_id;
    int like;
    struct sn_msg *next;
};
int main(){////1.post id  2.like  3.user that loged in
    int o=0;
    char order_of_user[100];
    int condition=1;
    while(condition){
            gets(order_of_user);//user can give the order whith space
            recognition_the_order_of_user(order_of_user[o]);
    }
}
////////////////////////////////////////////////////////////////////////////////////
int recognition_the_order_of_user(char order_of_user[100],int condition){
    if(order_of_user[0]==115){///harf aval s
        signup(order_of_user);
    }          
    if(order_of_user[0]==108){//harf aval l
        if(order_of_user[3]==105){//harf 4om i(its login)
            if(condition==2){//if before login , we have a login accont we should have eror
                printf("first logout your accont");
            } 
            login(order_of_user);
            if(condition==2){
                saving_your_username(order_of_user);//if we have login we save the user name of that accont
            } 
        }
        if(order_of_user[3]==117){//harf 4om u(its log out)
            if(condition==2){
                logout();
            }   
            else{
                printf("first login an accont");
            } 
        }
        if(order_of_user[3]==101){//harf 4om e;(its like)
            if(condition==2){
               like(order_of_user);
            }
            else{
                printf("first login an accont");
            } 
        }
    }
    if(order_of_user[0]==112){// harf aval p
        if(condition==2){
            post(order_of_user,the_new_post_id,username_entered_by_user_for_login);
        }
        else{
                printf("first login an accont");
            } 
    }
    if(order_of_user[0]==100){//harf aval d
        if(condition==2){
            delete(username_entered_by_user_for_login);
        }
        else{
                printf("first login an accont");
            } 
    }
    if(order_of_user[0]==105){///harf aval i
        if(condition==2){
            info(username_entered_by_user_for_login,password_entered_by_user_for_login);
        }
        else{
                printf("first login an accont");
            } 
    }
    if(order_of_user[0]==102){/// harf aval f
        if(condition==2){
            find_user(order_of_user);
        } 
        else{
                printf("first login an accont");
            }    
    }
    return condition;//This return allows the user to always give orders
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void signup(char* order_of_user){
    int o=0 , or=1 , u=0 , us=1 , p=0 , ps=1;
    char* order=(char*)malloc(1*sizeof(char));
    char* username_signup=(char*)malloc(1*sizeof(char));
    char* password_signup=(char*)malloc(1*sizeof(char));
        while(ch=getchar()!=32){
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!=32){
            username_signup[u]=(char)ch;
            u++;
            us++;
            username_signup=(char*)realloc(username_signup,us*sizeof(char));
        }
        while(ch=getchar()!='\0'){
            password_signup[u]=(char)ch;
            p++;
            ps++;
            password_signup=(char*)realloc(password_signup,ps*sizeof(char));
        }
    make_new_node_for_sn_user(username_signup,password_signup);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int login(char* order_of_user){
    int condition=1;
    int o=0 , or=1 , u=0 , us=1 , p=0 , ps=1;
    char* order=(char*)malloc(1*sizeof(char));
    char* username_entered_by_user_for_login=(char*)malloc(1*sizeof(char));
    char* password_entered_by_user_for_login=(char*)malloc(1*sizeof(char));
        while(ch=getchar()!=32){
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!=32){//we separate entered username here
            username_entered_by_user_for_login[u]=(char)ch;
            u++;
            us++;
            username_entered_by_user_for_login=(char*)realloc(username_entered_by_user_for_login,us*sizeof(char));
        }
        while(ch=getchar()!='\0'){//we separate entered password here
            password_entered_by_user_for_login[u]=(char)ch;
            p++;
            ps++;
            password_entered_by_user_for_login=(char*)realloc(password_entered_by_user_for_login,us*sizeof(char));
        }
    search_node(username_entered_by_user_for_login,password_entered_by_user_for_login);
        return condition;     
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int search_node(char*username_entered_by_user_for_login,char*password_entered_by_user_for_login)
{//in this function we chek , do we have this signes in accont
    int condition=1;
    struct sn_user cur;
    cur = head;//cur= username;   current point to head of list
    while(cur.next!=NULL&&strcmp(cur.username , username_entered_by_user_for_login)!=0){
        cur=cur->next;//cur=cur.next;
    }
    if(strcmp(cur.username,username_entered_by_user_for_login)==0){//if user name was same we chek password
        if(strcmp(cur.password,password_entered_by_user_for_login)==0){
            condition=2;//if condition=2, means we loged in an accont
        }
        else{
            printf("your password is false");
            condition = 1;
        }
    }
    if(cur.next==NULL){
        printf("your username is false");
        condition = 1;
    }
    return condition;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* saving_your_username(char* order_of_user){//in this function we save the username of loged in accont
    char* order=(char*)malloc(1*sizeof(char));
    char* username_entered_by_user_for_login=(char*)malloc(1*sizeof(char));
    int o=0 , or=1 , u=0 , us=1;
        while(ch=getchar()!=32){
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!=32){//we separate username here
            username_entered_by_user_for_login[u]=(char)ch;
            u++;
            us++;
            username_entered_by_user_for_login=(char*)realloc(username_entered_by_user_for_login,us*sizeof(char));
        }
    return username_entered_by_user_for_login;
}
///////////////////////////////////////////////////////////////////////////////////////
sn_user* make_new_node_for_sn_user(char*username_signup,char*password_signup)
{
    sn_user *sn_user_Output = (sn_user *)malloc(5*sizeof(sn_user));
    sn_user_Output->username = (char *)malloc(30*sizeof(char));
    sn_user_Output->password = (char *)malloc(30*sizeof(char));
    strcpy(sn_user_Output->username, username_signup);
    strcpy(sn_user_Output->password, password_signup);
    sn_user_Output->next = NULL;
    return sn_user_Output;
}
//////////////////////////////////////////////////////////////////////////////////////////
int logout(){
    int condition=1;//if condition=1,it means that we logout and Before login, almost no function works 
    return condition;
}
/////////////////////////////////////////////////////////////////////////////////////////
void info(char* username_entered_by_user_for_login,char*password_entered_by_user_for_login){
    struct sn_msg cur;
    cur = head;//cur= username;
      while(cur.next!=NULL&&strcmp(cur.username , username_entered_by_user_for_login)!=0){
        cur=cur->next;//cur=cur.next;
    }
    while(cur.next!=NULL){
        if(strcmp(cur.username,username_entered_by_user_for_login)==0){//we print the post of user here
            printf("%s\n",sn_msg_Output->post_txt);
            printf("%s\n",sn_msg_Output->username);
            printf("%d\n",sn_msg_Output->post_id);
            printf("%d\n",sn_msg_Output->like);
        }
    } 
    printf("%s\n", password_entered_by_user_for_login );
}
///////////////////////////////////////////////////////////////////////////////////////////
void post(char* order_of_user,int the_new_post_id,char* username_entered_by_user_for_login){
    int p=0 , ps=1 , o=0 , or=1 , ch=0;
    char* order=(char*)malloc(1*sizeof(char));
    char* post_txt=(char*)malloc(1*sizeof(char));
        while(ch=getchar()!=32){//separating the order 
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!='\0'){
            post_txt[p]=(char)ch;//we separate the text of post
            p++;
            ps++;
            post_txt=(char*)realloc(post_txt,ps*sizeof(char));
        }
        make_new_node_for_sn_msg(post_txt,the_new_post_id,username_entered_by_user_for_login);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
sn_user* make_new_node_for_sn_msg(char* post_txt,int the_new_post_id,char* username_entered_by_user_for_login){
    sn_msg *sn_msg_Output = (sn_msg *)malloc(5*sizeof(sn_msg));
    sn_msg_Output->post_txt = (char *)malloc(300*sizeof(char));
    sn_msg_Output->username =username_entered_by_user_for_login;
    sn_msg_Output->post_id=(the_new_post_id);
    sn_msg_Output->like=0;//in this function we initialize(مقدار اولیه دادن)the node of new post of user
    strcpy(sn_user_Output->post_txt, post_txt);
    sn_msg_Output->next = NULL;//we initialize NULL to next node of sn_msg
    return sn_msg_Output;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void like(char* order_of_user){
    int u=0 , us=1 , o=0 , or=1 , ch=0 , i=0 , pi=1;
    char* order=(char*)malloc(1*sizeof(char));
    char* username_entered_by_user_for_like=(char*)malloc(1*sizeof(char));
    int* post_id=(int*)malloc(1*sizeof(int));
        while(ch=getchar()!=32){
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!=32){
            username_entered_by_user_for_like[u]=(char)ch;
            u++;
            us++;
            username_entered_by_user_for_like=(char*)realloc(username_entered_by_user_for_like,us*sizeof(char));
        }
        while(ch=getchar()!='\0'){
            post_id[u]=ch;
            i++;
            pi++;
            post_id=(int*)realloc(post_id,pi*sizeof(int));
        }
        search_node_for_like(username_entered_by_user_for_like,post_id);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void search_node_for_like(char* username_entered_by_user_for_like,int* post_id){
    struct sn_msg cur;
    cur = head;//cur= username;
    while(cur.next!=NULL&&strcmp(cur.username , username_entered_by_user_for_like)!=0){
        cur=cur->next;//cur=cur.next;
    }
    if(strcmp(cur.username,username_entered_by_user_for_like)==0){
        while(cur.next!=NULL){
            if(strcmp(sn_msg_Output->post_id,post_id)==0){
                sn_msg_Output->like=like+1;
            }
            if(strcmp(sn_msg_Output->post_id,post_id)!=0){
                cur=cur->next;
            }
        }
    }
    if(cur.next==NULL){
        printf("your username is false and you cant like post");
    }
}
///////////////////////////////////////////////////////////////////
int delete(char* username_entered_by_user_for_login){
    int o=0 , or=1 , p=0 , ps=1 , condition=2; 
    char* order=(char*)malloc(1*sizeof(char));
    int* post_id=(int*)malloc(1*sizeof(int));
        while(ch=getchar()!=32){
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!='\0'){
            post_id[p]=ch;
            p++;
            ps++;
            post_id=(int*)realloc(post_id,ps*sizeof(int));
        }
    struct sn_msg cur;
    cur = head;//cur= username;
    while(cur.next!=NULL&&strcmp(cur.username , username_entered_by_user_for_login)!=0){
        cur=cur->next;//cur=cur.next;
    }
    if(strcmp(cur.username,username_entered_by_user_for_login)==0){
        while(cur.next!=NULL){
            if(strcmp(sn_msg_Output->post_id,post_id)==0){//in this section we NULL the components(اجزا)and then free
                sn_msg_Output->post_txt =free(post_txt);//the memory of that node of sn_msg
                sn_msg_Output->username =free(username_entered_by_user_for_login);
                sn_msg_Output->post_id=NULL;
                sn_msg_Output->like=NULL;
            }
            if(strcmp(sn_msg_Output->post_id,post_id)!=0){//whit strcmp we find the loged in accont and the id of post
                cur=cur->next;
            }
        }
    }
    return condition;
}
/////////////////////////////////////////////////////////////////////////////////
int find_user(char* order_of_user){
    int o=0 , or=1 , u=0 , us=1 , condition=2; 
    char* order=(char*)malloc(1*sizeof(char));
    char* username_for_finding=(char*)malloc(1*sizeof(char));
        while(ch=getchar()!=32){//separating the order
            order[o]=(char)ch;
            o++;
            or++;
            order=(char*)realloc(order,or*sizeof(char));
        }
        while(ch=getchar()!='\0'){
            username_for_finding[u]=(char)ch;
            u++;
            us++;
            username_for_finding=(char*)realloc(username_for_finding,us*sizeof(char));
        }
    struct sn_msg cur;
    cur = head;//cur= username;
    while(cur.next!=NULL&&strcmp(cur.username , username_for_finding)!=0){
        cur=cur->next;//cur=cur.next;
    }
    while(cur.next!=NULL){//Until we arive NULL we chek sn_msg 
        if(strcmp(cur.username,username_for_finding)==0){//if we find we print the node of the sn_msg related the user 
            printf("%s\n",sn_msg_Output->post_txt);
            printf("%s\n",sn_msg_Output->username);
            printf("%d\n",sn_msg_Output->post_id);
            printf("%d\n",sn_msg_Output->like);
            printf("\n");
        }
    }
    if(cur.next==NULL){
        printf("your username is false and you cant find user");
    }    
    return condition;
}