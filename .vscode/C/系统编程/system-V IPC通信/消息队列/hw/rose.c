#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[128];    /* message data */
};

void rcv(int msg_id){
    struct msgbuf msg;
    int msg_snd ;
    while (1)
    {
        bzero(msg.mtext,128);
        printf("已读：");
        msg_snd = msgrcv(msg_id, &msg, 128,'b',0);
        if (msg_snd == -1)
        {
            perror("读取失败：");
            continue;
        }
        printf("%s\n",msg.mtext);
    }
}
int main(int argc, char const *argv[])
{
    struct msgbuf msg ={
        .mtype = 'a'
    };
    key_t key = ftok("./", 1);
    int msg_id = msgget(key, IPC_CREAT | 0644);
    if (msg_id == -1)
    {
        perror("创建消息队列失败：");
    }
    int pid = fork();
    if (pid == 0)
    {
        rcv(msg_id);
        return 0;
    }
    int msg_snd;
    while (1)
    {
        bzero(msg.mtext,128);
        printf("以写：");
        fgets(msg.mtext,128,stdin);
        msg_snd = msgsnd(msg_id, &msg, strlen(msg.mtext),0);
        if (msg_snd == -1)
        {
            perror("发送失败：");
            break;
        }
        printf("\n");
    }
    

    return 0;
}
