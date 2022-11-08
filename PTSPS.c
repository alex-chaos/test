#include    "PTC.h"
#define     PTC2 //PTC2为二序列，PTC4为四序列

void PTC_fun(void)
{
    PTC_param.Error = PTC_param.V2ref - PTC_param.V2;
    #ifdef PTC4
    switch(PTC_param.PTC_State)
    {
        case S1:
            if(PTC_param.Error >= PTC_param.Error_th1)
            {
                PTC_param.PTC_State = S1;
            }
            else 
            {
                PTC_param.PTC_State = S2;
            }
            break;
        case S2:
            if(PTC_param.Error < PTC_param.Error_th1 && PTC_param.Error >= 0)
            {
                PTC_param.PTC_State = S2;
            }
            else if(PTC_param.Error >= PTC_param.Error_th1)
            {
                PTC_param.PTC_State = S1;
            }
            else
            {
                PTC_param.PTC_State = S3;
            }
            break;
        case S3:
            if(PTC_param.Error >= -PTC_param.Error_th1 && PTC_param.Error < 0)
            {
                PTC_param.PTC_State = S3;
            }
            else if(PTC_param.Error >= 0)
            {
                PTC_param.PTC_State = S2;
            }
            else
            {
                PTC_param.PTC_State = S4;
            }
            break;
        case S4:
            if(PTC_param.Error < -PTC_param.Error_th1 )
            {
                PTC_param.PTC_State = S4;
            }
            else
            {
                PTC_param.PTC_State = S3;
            }
            break;
        default:PTC_param.PTC_State = S4;

    }

    switch(PTC_param.PTC_State)
    {
        case S1:
            PTC_param.P0 = 1;
            // PTC_param.P0 = 0.7;
            break;
        case S2:
            PTC_param.P0 = 0.7;
            // PTC_param.P0 = 0.55;
            break;
        case S3:
            PTC_param.P0 = 0.4;
            // PTC_param.P0 = 0.4;
            break;
        case S4:
            PTC_param.P0 = 0.1;
            // PTC_param.P0 = 0.2;
            break;
        default:PTC_param.P0 = 0.1;

    }
    #endif
    #ifdef PTC2

    if(PTC_param.Error > 0)
    {
        PTC_param.P0 = 1;
    }
    else 
    {
        PTC_param.P0 = 0.1;
    }
    #endif
    
}
