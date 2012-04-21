/**
  ******************************************************************************
  * @file    stm8s_it.c
  * @author  MCD Application Team
  * @version  V2.0.1
  * @date     18-November-2011
  * @brief   This file contains all the interrupt routines.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8s_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t TimeCounter = 0;
uint8_t step = 1;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/** @addtogroup TIM1_6Steps
  * @{
  */
#ifdef _COSMIC_
/**
  * @brief  Dummy interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(NonHandledInterrupt, 25)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*_COSMIC_*/

/**
  * @brief  TRAP interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  Top Level Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TLI_IRQHandler, 0)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Auto Wake Up Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Clock Controller Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTA Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTB Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTC Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTD Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTE Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#ifdef STM8S903
/**
  * @brief  External Interrupt PORTF Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(EXTI_PORTF_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined (STM8AF52Ax)
/**
  * @brief CAN RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_RX_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  CAN TX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_TX_IRQHandler, 9)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208 || STM8AF52Ax */

/**
  * @brief  SPI Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer1 Update/Overflow/Trigger/Break Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer1 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
   /* Clear TIM1 COM pending bit */
  TIM1_ClearITPendingBit(TIM1_IT_COM);

  if(step == 1)
  {
    /* Next step: Step 2 Configuration ---------------------------- */  
    /*  Channel3 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_3, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, DISABLE);

  /*  Channel1 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_1,(TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_1, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, ENABLE);
    
  /*  Channel2 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_2, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_2, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, ENABLE);  
    step++;
  }
  else if(step == 2)
  {
    /* Next step: Step 3 Configuration ---------------------------- */
    /*  Channel2 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_2, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_2, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, ENABLE);

  /*  Channel3 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_3, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_3, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, ENABLE);
    
  /*  Channel1 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_1, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, DISABLE); 
    step++;
  }
  else if(step == 3)
  {
    /* Next step: Step 4 Configuration ---------------------------- */
    /*  Channel3 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_3, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_3, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, ENABLE);

  /*  Channel2 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_2, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, DISABLE);
    
  /*  Channel1 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_1, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_1, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, ENABLE);
    step++;
  }
  else if(step == 4)
  {
    /* Next step: Step 5 Configuration ---------------------------- */
  /*  Channel3 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_3, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, DISABLE);
  
  /*  Channel1 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_1, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_1, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, ENABLE);

  /*  Channel2 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_2, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_2, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, ENABLE);    
    step++;
  }
  else if (step == 5)
  {
    /* Next step: Step 6 Configuration ---------------------------- */
  /*  Channel3 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_3, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_3, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, ENABLE);

  /*  Channel1 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_1, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, DISABLE);
    
  /*  Channel2 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_2, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
    TIM1_CCxCmd(TIM1_CHANNEL_2, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, ENABLE);
    step++;
  }
  else
  {
    /* Next step: Step 1 Configuration ---------------------------- */
    /*  Channel1 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_1, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_ACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_1, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_1, ENABLE);
    
  /*  Channel3 configuration */
  TIM1_SelectOCxM(TIM1_CHANNEL_3, (TIM1_OCMode_TypeDef)TIM1_FORCEDACTION_INACTIVE);
  TIM1_CCxCmd(TIM1_CHANNEL_3, ENABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_3, ENABLE);

  /*  Channel2 configuration */
  TIM1_CCxCmd(TIM1_CHANNEL_2, DISABLE);
  TIM1_CCxNCmd(TIM1_CHANNEL_2, DISABLE);
    step = 1;
  }
}

#ifdef STM8S903
/**
  * @brief  Timer5 Update/Overflow/Break/Trigger Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_UPD_OVF_BRK_TRG_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  Timer5 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
  * @brief  Timer2 Update/Overflow/Break Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer2 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S105) || \
    defined(STM8S005) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8AF626x)
/**
  * @brief Timer3 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer3 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208, STM8S207 or STM8S105 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S103) || \
    defined(STM8S003) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8S903)
/**
  * @brief  UART1 TX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  UART1 RX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S105*/

/**
  * @brief  I2C Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined(STM8S105) || defined(STM8S005) ||  defined (STM8AF626x)
/**
  * @brief  UART2 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }

/**
  * @brief  UART2 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }
#endif /* STM8S105*/

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief  UART3 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_TX_IRQHandler, 20)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }

/**
  * @brief  UART3 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_RX_IRQHandler, 21)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief  ADC2 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC2_IRQHandler, 22)
{

    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    return;

}
#else /*STM8S105, STM8S103 or STM8S903 or STM8AF626x */
/**
  * @brief  ADC1 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
{

    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    return;

}
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#ifdef STM8S903
/**
  * @brief  Timer6 Update/Overflow/Trigger Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM6_UPD_OVF_TRG_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
  * @brief  Timer4 Update/Overflow Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
  
  if (TimeCounter == 11)
  {
    /* Generate TIM1 COM event by software */
    TIM1_GenerateEvent(TIM1_EVENTSOURCE_COM);
    TimeCounter = 1;
  /*
    the TIM4 Update Interrupt occurs each 0.064ms ( Tui=(Period * Prescaler)/Fmaster = (256*128)/2Mhz = 16,384 ms )
    so after 11 TIM4 Update Interrupts,  180ms have been spent  (T= 11 * 16,384  = 180.2 ms)
  */

  }
  else
  {
    TimeCounter++;
  }
}
#endif /*STM8S903*/

/**
  * @brief  Eeprom EEC Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/