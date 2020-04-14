/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZSN700 CRC �û������ļ�
 * \sa am_hwconf_zsn700_crc.c
 *
 * \internal
 * \par Modification history
 * - 1.00 19-09-20
 * \endinternal
 */
#include "ametal.h"
#include "am_zsn700.h"
#include "am_clk.h"
#include "am_zsn700_crc.h"
#include "hw/amhw_zsn700_rcc_reset.h"
/**
 * \addtogroup am_if_src_hwconf_zsn700_crc
 * \copydoc am_hwconf_zsn700_crc.c
 * @{
 */

/** \brief CRCƽ̨��ʼ�� */
void __zsn700_crc_plfm_init (void)
{
    /* ʹ��CRCʱ�� */
    am_clk_enable(CLK_CRC);
}

/** \brief ���CRCƽ̨��ʼ�� */
void __zsn700_crc_plfm_deinit (void)
{
    am_clk_disable(CLK_CRC);
}

/** \brief CRC �豸��Ϣ */
static const am_zsn700_crc_devinfo_t __g_crc_devinfo = {
     ZSN700_CRC_BASE,               /**< \brief CRC�Ĵ������ַ */
    __zsn700_crc_plfm_init,         /**< \brief ƽ̨��ʼ�� */
    __zsn700_crc_plfm_deinit        /**< \brief ƽ̨ȥ��ʼ�� */
};

/** \brief CRC�豸���� */
static am_zsn700_crc_dev_t __g_crc_dev;

/** \brief CRC ʵ����ʼ�������CRC��׼������ */
am_crc_handle_t am_zsn700_crc_inst_init (void)
{
    return am_zsn700_crc_init(&__g_crc_dev, &__g_crc_devinfo);
}

/** \brief CRC ʵ�����ʼ�� */
void am_zsn700_crc_inst_deinit (am_crc_handle_t handle)
{
    am_zsn700_crc_deinit(handle);
}

/**
 * @}
 */

/* end of file */