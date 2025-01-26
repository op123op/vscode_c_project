#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/msg.h>

typedef struct msgbuf
{
    long mtype; // 消息的标识
    char mtext[20]; // 消息的正文 可以是任何类型数据
}Msg_Buff;
int main(int argc, char const *argv[])
{
    
    
    int pid = fork();
    if (pid > 0)
    {
        struct msgbuf msg_buf = {
            .mtype = 'X',
            .mtext = "hello msg!"
        };
        key_t key = ftok("./msg.txt",1);
        if (key == -1)
        {
            perror("创建key失败：");
            return 0;
        }
        int msg_id = msgget(key,IPC_CREAT | 0644);
        if (msg_id == -1)
        {
            perror("创建消息队列失败：");
            return -1;
        }
        int msg_snd = msgsnd(msg_id, &msg_buf, sizeof(msg_buf.mtext),IPC_NOWAIT);
        if (msg_snd == -1)
        {
            perror("发送失败：");
            return -1;
        }
        
    }else if (pid == 0)
    {
        Msg_Buff msg_buff1 = {0};
        key_t key = ftok("./msg.txt",1);
        int msg_id = msgget(key,IPC_CREAT | 0644);
        if (msg_id == -1)
        {
            perror("创建消息队列失败：");
            return -1;
        }
        ssize_t msg_rcv = msgrcv(msg_id, &msg_buff1, sizeof(msg_buff1.mtext), 'X',IPC_NOWAIT);
        if (msg_rcv == -1)
        {
            perror("接受失败：");
            return -1;
        }
        printf("mtext:%s\n",msg_buff1.mtext);
        // 标记删除
        msgctl(msg_id , IPC_RMID , NULL );
    }
    
    return 0;
}
