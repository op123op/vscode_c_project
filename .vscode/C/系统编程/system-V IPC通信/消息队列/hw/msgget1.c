#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext;    /* message data */
};

int main(int argc, char const *argv[])
{
    struct msgbuf msg ={
        .mtype = 'a',
        .mtext = 'p'
    };
    key_t key = ftok("./", 1);
    int msg_id = msgget(key, IPC_CREAT | 0644);
    if (msg_id == -1)
    {
        perror("创建消息队列失败：");
    }
    
    int i = 0;
    printf("%d\t%d\n",sizeof(msg.mtext),sizeof(msg));
    while (1)
    {
        int msg_snd = msgsnd(msg_id, &msg, sizeof(msg.mtext),0);
        if (msg_snd == -1)
        {
            perror("发送失败：");
            continue;
        }
        printf("已发送：%d字节\n",++i);
    }
    
    
    
    return 0;
}
