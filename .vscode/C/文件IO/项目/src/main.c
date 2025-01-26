#include "./../include/main.h"

int main(int argc, char const *argv[])
{
    Menu menu;
    while (1)
    {
        menu = menu1();
        switch (menu)
        {
            case Resource_update:
                res_update();  //资源管理
                break;
            case media_player:
                mda_ply();     //媒体播放
                break;
            case lucky_draw:
                ly_dw();       //幸运抽奖
                break;
            default:
                break;
        }
    }
    
    return 0;
}
