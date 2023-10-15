#include "dio.h"
#include "Bitwise_Operations.h"

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType channel_value;

    if(ChannelId <= 7)
    {
        channel_value = (GPIO_PORTA_DATA_R>>ChannelId);
    }
    else if((ChannelId >= 8) && (ChannelId <= 15) )
    {
        channel_value = (GPIO_PORTB_DATA_R>>(ChannelId-8));
    }
    else if((ChannelId >= 16) && (ChannelId <= 23) )
    {
        channel_value = (GPIO_PORTC_DATA_R>>(ChannelId-(8*2)));
    }
    else if((ChannelId >= 24) && (ChannelId <= 31) )
    {
        channel_value = (GPIO_PORTD_DATA_R>>(ChannelId-(8*3)));
    }
    else if((ChannelId >= 32) && (ChannelId <= 37) )
    {
        channel_value = (GPIO_PORTE_DATA_R>>(ChannelId-((8*3)+6) ));
    }
    else if((ChannelId >= 38) && (ChannelId <= 45) )
    {
        channel_value = (GPIO_PORTF_DATA_R>>(ChannelId-((8*4)+6) ));
    }
    else
    {}

    return channel_value;
}


void Dio_WriteChannel (Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    if(Level == STD_HIGH)
    {
        if(ChannelId <= 7)
        {
            SET_BIT(GPIO_PORTA_DATA_R, ChannelId);
        }
        else if((ChannelId >= 8) && (ChannelId <= 15) )
        {
            SET_BIT(GPIO_PORTB_DATA_R, (ChannelId-8));
        }
        else if((ChannelId >= 16) && (ChannelId <= 23) )
        {
            SET_BIT(GPIO_PORTC_DATA_R, (ChannelId-(8*2)));
        }
        else if((ChannelId >= 24) && (ChannelId <= 31) )
        {
            SET_BIT(GPIO_PORTD_DATA_R, (ChannelId-(8*3)));
        }
        else if((ChannelId >= 32) && (ChannelId <= 37) )
        {
            SET_BIT(GPIO_PORTE_DATA_R, (ChannelId-((8*3)+6)) );
        }
        else if((ChannelId >= 38) && (ChannelId <= 45) )
        {
            SET_BIT(GPIO_PORTF_DATA_R, (ChannelId-((8*4)+6)) );
        }
        else
        {}
    }
    else if(Level == STD_LOW)
    {
        if(ChannelId <= 7)
        {
            CLEAR_BIT(GPIO_PORTA_DATA_R, ChannelId);
        }
        else if((ChannelId >= 8) && (ChannelId <= 15) )
        {
            CLEAR_BIT(GPIO_PORTB_DATA_R, (ChannelId-8));
        }
        else if((ChannelId >= 16) && (ChannelId <= 23) )
        {
            CLEAR_BIT(GPIO_PORTC_DATA_R, (ChannelId-(8*2)));
        }
        else if((ChannelId >= 24) && (ChannelId <= 31) )
        {
            CLEAR_BIT(GPIO_PORTD_DATA_R, (ChannelId-(8*3)));
        }
        else if((ChannelId >= 32) && (ChannelId <= 37) )
        {
            CLEAR_BIT(GPIO_PORTE_DATA_R, (ChannelId-((8*3)+6)) );
        }
        else if((ChannelId >= 38) && (ChannelId <= 45) )
        {
            CLEAR_BIT(GPIO_PORTF_DATA_R, (ChannelId-((8*4)+6)) );
        }
        else
        {}
    }
}


Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType port_value;
    switch (PortId)
    {
        case 0: port_value = GPIO_PORTA_DATA_R;
            break;
        case 1: port_value = GPIO_PORTB_DATA_R;
            break;
        case 2: port_value = GPIO_PORTC_DATA_R;
            break;
        case 3: port_value = GPIO_PORTD_DATA_R;
            break;
        case 4: port_value = GPIO_PORTE_DATA_R;
            break;
        case 5: port_value = GPIO_PORTF_DATA_R;
            break;
    }
    return port_value;
}


void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)
{
    switch (PortId)
    {
        case 0: GPIO_PORTA_DATA_R = Level;
            break;
        case 1: GPIO_PORTB_DATA_R = Level;
            break;
        case 2: GPIO_PORTC_DATA_R = Level;
            break;
        case 3: GPIO_PORTD_DATA_R = Level;
            break;
        case 4: GPIO_PORTE_DATA_R = Level;
            break;
        case 5: GPIO_PORTF_DATA_R = Level;
            break;
    }
}
