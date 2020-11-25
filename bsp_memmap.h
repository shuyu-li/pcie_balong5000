/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __BSP_MEMMAP_H__
#define __BSP_MEMMAP_H__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __KERNEL__
#ifndef __ASSEMBLY__
#include <linux/io.h>
#endif
#endif
#include "product_config.h"
#include "soc_memmap.h"

#ifdef __KERNEL__
/* macro to get at IO space when running virtually */
#ifdef CONFIG_MMU
/*
 * Statically mapped addresses:
 *
 */
#define IO_ADDRESS(x) ((((x)&0xF0000000) >> 4) | ((x)&0x00FFFFFF) | 0xF0000000)
#else
#define IO_ADDRESS(x) (x)
#endif

#define HI_IO_ADDRESS(x) IO_ADDRESS(x)
#else
#define HI_IO_ADDRESS(x) (x)
#endif

#if (defined __KERNEL__) && (defined BSP_CONFIG_PHONE_TYPE)
    extern void *g_ap_sysctrl_regbase_addr_virt;
    extern void *g_ddr_share_mem_addr_virt;
    extern void *g_ddr_gu_addr_virt;
    extern void *g_ddr_mntn_addr_virt;
    extern void *g_lpm3_tcm_virt;

#define HI_AP_SYSCTRL_BASE_ADDR_VIRT g_ap_sysctrl_regbase_addr_virt
#define HI_AP_SYS_CNT_BASE_ADDR_VIRT g_ap_syscnt_regbase_addr_virt
#define DDR_SHARED_MEM_VIRT_ADDR g_ddr_share_mem_addr_virt
#define DDR_MNTN_ADDR_VIRT g_ddr_mntn_addr_virt
#define DDR_GU_ADDR_VIRT g_ddr_gu_addr_virt
#define HI_IPF_REGBASE_ADDR_VIRT g_ipf_regbase_addr_virt
#define HI_M3TCM0_MEM_ADDR_VIRT g_lpm3_tcm_virt
#define HI_M3TCM1_MEM_ADDR_VIRT (HI_M3TCM0_MEM_ADDR_VIRT + HI_M3TCM0_MEM_SIZE)
    /*����Ϊͳһk3v3��p532/v7r5��k3�Ͻ��д�׮,k3�ϲ���ʹ�����µ�ַ*/

#else /* !((defined __KERNEL__) && (defined BSP_CONFIG_PHONE_TYPE)) */

#ifndef DDR_GU_ADDR_VIRT
#define DDR_GU_ADDR_VIRT 0 /* todo:��Ҫɾ������GUȷ�� */
#endif

/* SHARED_MEM */
#define DDR_SHARED_MEM_VIRT_ADDR HI_IO_ADDRESS(HI_SHARED_DDR_BASE_ADDR)

/* OM_MEM */
#define DDR_MNTN_ADDR_VIRT HI_IO_ADDRESS(DDR_MNTN_ADDR)

/************************************************************************
                * IP BASE ADDR *
************************************************************************/
/* AP��sysctrl reg base ,k3��*/
#ifdef HI_AP_SYSCTRL_BASE_ADDR
#define HI_AP_SYSCTRL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AP_SYSCTRL_BASE_ADDR)
#define HI_AP_SCTRL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AP_SYSCTRL_BASE_ADDR)
#endif
#ifdef HI_LP_PERI_CRG_REG_ADDR
#define HI_LP_PERI_CRG_REG_ADDR_VIRT HI_IO_ADDRESS(HI_LP_PERI_CRG_REG_ADDR)
#endif
#ifdef HI_AP_SYS_CNT_BASE_ADDR
#define HI_AP_SYS_CNT_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AP_SYS_CNT_BASE_ADDR)
#endif
/* IPCM */
#ifdef HI_IPCM_REGBASE_ADDR
#define HI_IPCM_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_IPCM_REGBASE_ADDR)
#endif
/* IPF */
#ifdef HI_IPF_REGBASE_ADDR
#define HI_IPF_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_IPF_REGBASE_ADDR)
#endif
/* SOCP */
#ifdef HI_SOCP_REGBASE_ADDR
#define HI_SOCP_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_SOCP_REGBASE_ADDR)
#endif
/* BBP SYSTIME */
#ifdef HI_BBP_SYSTIME_BASE_ADDR
#define HI_BBP_SYSTIME_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_SYSTIME_BASE_ADDR)
#endif
/* M3 TCM0 */
#ifdef HI_M3TCM0_MEM_ADDR
#define HI_M3TCM0_MEM_ADDR_VIRT HI_IO_ADDRESS(HI_M3TCM0_MEM_ADDR)
#endif
/* M3 TCM1 */
#ifdef HI_M3TCM1_MEM_ADDR
#define HI_M3TCM1_MEM_ADDR_VIRT HI_IO_ADDRESS(HI_M3TCM1_MEM_ADDR)
#endif

#endif /* !((defined __KERNEL__) && (defined BSP_CONFIG_PHONE_TYPE)) */

/* A15 GIC */
#ifdef HI_A15_GIC_BASE_ADDR
#define HI_A15_GIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_A15_GIC_BASE_ADDR)
#endif
/* APP GIC */
#ifdef HI_APP_GIC_BASE_ADDR
#define HI_APP_GIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_APP_GIC_BASE_ADDR)
#endif
/* MDM GIC */
#ifdef HI_MDM_GIC_BASE_ADDR
#define HI_MDM_GIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_MDM_GIC_BASE_ADDR)
#endif
/* APP A9 L2 reg */
#ifdef HI_APPA9_L2_REGBASE_ADDR
#define HI_APPA9_L2_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_APPA9_L2_REGBASE_ADDR)
#endif
/* MDM A9 L2 reg */
#ifdef HI_MDMA9_L2_REGBASE_ADDR
#define HI_MDMA9_L2_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MDMA9_L2_REGBASE_ADDR)
#endif
/* DSP subsystem */
#ifdef HI_DSP_SUBSYSTEM_BASE_ADDR
#define HI_DSP_SUBSYSTEM_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP_SUBSYSTEM_BASE_ADDR)
#endif
/* DSP DTCM */
#ifdef HI_BBE16DMEM_BASE_ADDR
#define HI_BBE16DMEM_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBE16DMEM_BASE_ADDR)
#endif
/* DSP ITCM */
#ifdef HI_BBE16IMEM_BASE_ADDR
#define HI_BBE16IMEM_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBE16IMEM_BASE_ADDR)
#endif

/* GBBP */
#ifdef HI_GBBP_REG_BASE_ADDR
#define HI_GBBP_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_GBBP_REG_BASE_ADDR)
#endif
/* GBBP1 */
#ifdef HI_GBBP1_REG_BASE_ADDR
#define HI_GBBP1_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_GBBP1_REG_BASE_ADDR)
#endif

/*WBBP*/
#ifdef HI_WBBP_REG_BASE_ADDR
#define HI_WBBP_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_WBBP_REG_BASE_ADDR)
#endif

/* CS_SYS */
#ifdef HI_CS_SYS_REGBASE_ADDR
#define HI_CS_SYS_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_CS_SYS_REGBASE_ADDR)
#endif
/* PCIE PHY */
#ifdef HI_PCIE_PHY_BASE_ADDR
#define HI_PCIE_PHY_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE_PHY_BASE_ADDR)
#endif
/* system controller */
#ifdef HI_SYSCTRL_BASE_ADDR
#define HI_SYSCTRL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_BASE_ADDR)
#define HI_SYSCRG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_BASE_ADDR)
#define HI_SYSSC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_BASE_ADDR)
#define HI_SYSSC_AO_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_BASE_ADDR)
#define HI_PWRCTRL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_BASE_ADDR)
#endif
/* wdog */
#ifdef HI_WDT_BASE_ADDR
#define HI_WDT_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_WDT_BASE_ADDR)
#endif
/* timer 0~7 */
#ifdef HI_TIMER_00TO07_REGBASE_ADDR
#define HI_TIMER_00TO07_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_00TO07_REGBASE_ADDR)
#endif
/* timer 8~15 */
#ifdef HI_TIMER_08TO15_REGBASE_ADDR
#define HI_TIMER_08TO15_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_08TO15_REGBASE_ADDR)
#endif
/* timer 16~23 */
#ifdef HI_TIMER_16TO23_REGBASE_ADDR
#define HI_TIMER_16TO23_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_16TO23_REGBASE_ADDR)
#endif

#ifdef HI_TIMER_00_REGBASE_ADDR
#define HI_TIMER_00_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_00_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_01_REGBASE_ADDR
#define HI_TIMER_01_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_01_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_02_REGBASE_ADDR
#define HI_TIMER_02_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_02_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_03_REGBASE_ADDR
#define HI_TIMER_03_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_03_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_04_REGBASE_ADDR
#define HI_TIMER_04_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_04_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_05_REGBASE_ADDR
#define HI_TIMER_05_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_05_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_06_REGBASE_ADDR
#define HI_TIMER_06_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_06_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_07_REGBASE_ADDR
#define HI_TIMER_07_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_07_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_08_REGBASE_ADDR
#define HI_TIMER_08_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_08_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_09_REGBASE_ADDR
#define HI_TIMER_09_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_09_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_10_REGBASE_ADDR
#define HI_TIMER_10_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_10_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_11_REGBASE_ADDR
#define HI_TIMER_11_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_11_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_12_REGBASE_ADDR
#define HI_TIMER_12_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_12_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_13_REGBASE_ADDR
#define HI_TIMER_13_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_13_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_14_REGBASE_ADDR
#define HI_TIMER_14_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_14_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_15_REGBASE_ADDR
#define HI_TIMER_15_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_15_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_16_REGBASE_ADDR
#define HI_TIMER_16_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_16_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_17_REGBASE_ADDR
#define HI_TIMER_17_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_17_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_18_REGBASE_ADDR
#define HI_TIMER_18_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_18_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_19_REGBASE_ADDR
#define HI_TIMER_19_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_19_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_20_REGBASE_ADDR
#define HI_TIMER_20_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_20_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_21_REGBASE_ADDR
#define HI_TIMER_21_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_21_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_22_REGBASE_ADDR
#define HI_TIMER_22_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_22_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_23_REGBASE_ADDR
#define HI_TIMER_23_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_23_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_24_REGBASE_ADDR
#define HI_TIMER_24_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_24_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_25_REGBASE_ADDR
#define HI_TIMER_25_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_25_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_26_REGBASE_ADDR
#define HI_TIMER_26_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_26_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_27_REGBASE_ADDR
#define HI_TIMER_27_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_27_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_28_REGBASE_ADDR
#define HI_TIMER_28_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_28_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_29_REGBASE_ADDR
#define HI_TIMER_29_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_29_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_30_REGBASE_ADDR
#define HI_TIMER_30_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_30_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_31_REGBASE_ADDR
#define HI_TIMER_31_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_31_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_32_REGBASE_ADDR
#define HI_TIMER_32_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_32_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_33_REGBASE_ADDR
#define HI_TIMER_33_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_33_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_34_REGBASE_ADDR
#define HI_TIMER_34_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_34_REGBASE_ADDR)
#endif
#ifdef HI_TIMER_35_REGBASE_ADDR
#define HI_TIMER_35_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TIMER_35_REGBASE_ADDR)
#endif

#ifdef HI_SYSCTRL_AO_REG_BASE_ADDR
#define HI_SYSCTRL_AO_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_AO_REG_BASE_ADDR)
#define HI_SYSCTRL_AO_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_AO_REG_BASE_ADDR)
#endif

#ifdef HI_AO_CRG_REG_BASE_ADDR
#define HI_AO_CRG_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AO_CRG_REG_BASE_ADDR)
#endif

#ifdef HI_SYSCTRL_PD_REG_BASE_ADDR
#define HI_SYSCTRL_PD_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_PD_REG_BASE_ADDR)
#endif

#ifdef HI_PD_CRG_BASE_ADDR
#define HI_PD_CRG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PD_CRG_BASE_ADDR)
#endif

#ifdef HI_SYSCTRL_PCIE_REG_BASE_ADDR
#define HI_SYSCTRL_PCIE_REG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSCTRL_PCIE_REG_BASE_ADDR)
#endif

#ifdef HI_MODEM_SC_BASE_ADDR
#define HI_MODEM_SC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_MODEM_SC_BASE_ADDR)
#endif

/* RTC */
#ifdef HI_RTC_REGBASE_ADDR
#define HI_RTC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_RTC_REGBASE_ADDR)
#endif
#ifdef HI_RTC0_BASE_ADDR
#define HI_RTC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_RTC0_BASE_ADDR)
#endif
/* UART0 */
#ifdef HI_UART0_REGBASE_ADDR
#define HI_UART0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART0_REGBASE_ADDR)
#endif
/* UART5 */
#ifdef HI_UART5_REGBASE_ADDR
#define HI_UART5_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART5_REGBASE_ADDR)
#endif
/* IPC_S*/
#ifdef HI_IPC_S_REGBASE_ADDR
#define HI_IPC_S_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_IPC_S_REGBASE_ADDR)
#endif
/*SCI0*/
#ifdef HI_SCI0_REGBASE_ADDR
#define HI_SCI0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_SCI0_REGBASE_ADDR)
#endif
/*SCI1*/
#ifdef HI_SCI1_REGBASE_ADDR
#define HI_SCI1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_SCI1_REGBASE_ADDR)
#endif
/* bc_ctrl */
#ifdef HI_BC_CTRL_REGBASE_ADDR
#define HI_BC_CTRL_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_BC_CTRL_REGBASE_ADDR)
#endif
/* TDS SYSCTRL */
#ifdef HI_TDS_SYSCTRL_REGBASE_ADDR
#define HI_TDS_SYSCTRL_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TDS_SYSCTRL_REGBASE_ADDR)
#endif
/* UART1 */
#ifdef HI_UART1_REGBASE_ADDR
#define HI_UART1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART1_REGBASE_ADDR)
#endif
/* UART2 */
#ifdef HI_UART2_REGBASE_ADDR
#define HI_UART2_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART2_REGBASE_ADDR)
#endif
/* UART3 */
#ifdef HI_UART3_REGBASE_ADDR
#define HI_UART3_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART3_REGBASE_ADDR)
#endif

/* UART_MDM */
#ifdef HI_UART_MDM_REGBASE_ADDR
#define HI_UART_MDM_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UART_MDM_REGBASE_ADDR)
#endif

#ifdef HI_BBP_CTU_BASE_ADDR
#define HI_BBP_CTU_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_CTU_BASE_ADDR)
#endif

/*BBP MIPI*/
#define BBP_MIPI_BASE_ADDR_VIRT HI_IO_ADDRESS(BBP_MIPI_BASE_ADDR)
/*BBP MIPI*/
#define BBP_MIPI_1_BASE_ADDR_VIRT HI_IO_ADDRESS(BBP_MIPI_1_BASE_ADDR)

/* I2C */
#ifdef HI_I2C_REGBASE_ADDR
#define HI_I2C_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_I2C_REGBASE_ADDR)
#endif
/* I2C0 */
#ifdef HI_I2C0_REGBASE_ADDR
#define HI_I2C0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_I2C0_REGBASE_ADDR)
#endif
/* I2C1 */
#ifdef HI_I2C1_REGBASE_ADDR
#define HI_I2C1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_I2C1_REGBASE_ADDR)
#endif
/* MDDRC */
#ifdef HI_MDDRC_REGBASE_ADDR
#define HI_MDDRC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MDDRC_REGBASE_ADDR)
#endif
/* EDMA */
#ifdef HI_EDMA_REGBASE_ADDR
#define HI_EDMA_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_EDMA_REGBASE_ADDR)
#endif
/* ASHB */
#ifdef HI_ASHB_REGBASE_ADDR
#define HI_ASHB_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_ASHB_REGBASE_ADDR)
#endif
/* EDMA CH4 */
#ifdef HI_EDMA_CH4_REGBASE_ADDR
#define HI_EDMA_CH4_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_EDMA_CH4_REGBASE_ADDR)
#endif
/* ASHB_M3_SLV */
#ifdef HI_ASHB_M3_SLV_BASE_ADDR
#define HI_ASHB_M3_SLV_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_ASHB_M3_SLV_BASE_ADDR)
#endif
/* ASHB_M3_MST */
#ifdef HI_ASHB_M3_MST_BASE_ADDR
#define HI_ASHB_M3_MST_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_ASHB_M3_MST_BASE_ADDR)
#endif

/* APB_MIPI */
#ifdef HI_APB_MIPI_REGBASE_ADDR
#define HI_APB_MIPI_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_APB_MIPI_REGBASE_ADDR)
#endif
/* SYSREG_PD */
#ifdef HI_SYSREG_PD_BASE_ADDR
#define HI_SYSREG_PD_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_SYSREG_PD_BASE_ADDR)
#endif
/* BBP_COMMON */
#ifdef HI_BBP_COMON_REGBASE_ADDR
#define HI_BBP_COMON_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_COMON_REGBASE_ADDR)
#endif
/* BBP_APB */
#ifdef HI_BBP_APB_REGBASE_ADDR
#define HI_BBP_APB_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_APB_REGBASE_ADDR)
#endif
/* PWM0 */
#ifdef HI_PWM0_REGBASE_ADDR
#define HI_PWM0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_PWM0_REGBASE_ADDR)
#endif
/* ET */
#ifdef HI_ET_REGBASE_ADDR
#define HI_ET_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_ET_REGBASE_ADDR)
#endif
/* PMUSSI0 */
#ifdef HI_PMUSSI0_REGBASE_ADDR
#define HI_PMUSSI0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_PMUSSI0_REGBASE_ADDR)
#endif
/* PMUSSI1 */
#ifdef HI_PMUSSI1_REGBASE_ADDR
#define HI_PMUSSI1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_PMUSSI1_REGBASE_ADDR)
#endif
/* TCSSI0 */
#ifdef HI_TCSSI0_REGBASE_ADDR
#define HI_TCSSI0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TCSSI0_REGBASE_ADDR)
#endif
/* TCSSI1 */
#ifdef HI_TCSSI1_REGBASE_ADDR
#define HI_TCSSI1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_TCSSI1_REGBASE_ADDR)
#endif
/* UICC */
#ifdef HI_UICC_REGBASE_ADDR
#define HI_UICC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_UICC_REGBASE_ADDR)
#endif
/* HSIC */
#ifdef HI_HSIC_REGBASE_ADDR
#define HI_HSIC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_HSIC_REGBASE_ADDR)
#endif
/* GMAC */
#ifdef HI_GMAC_REGBASE_ADDR
#define HI_GMAC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_GMAC_REGBASE_ADDR)
#endif
/* EMI */
#ifdef HI_EMI_REGBASE_ADDR
#define HI_EMI_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_EMI_REGBASE_ADDR)
#endif
/* EMI MEM */
#ifdef HI_EMIMEM_REGBASE_ADDR
#define HI_EMIMEM_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_EMIMEM_REGBASE_ADDR)
#endif
/* NANDC reg */
#ifdef HI_NANDC_REGBASE_ADDR
#define HI_NANDC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_NANDC_REGBASE_ADDR)
#endif
/* LTE SIO */
#ifdef HI_LTESIO_REGBASE_ADDR
#define HI_LTESIO_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_LTESIO_REGBASE_ADDR)
#endif
/* HS UART */
#ifdef HI_HSUART_REGBASE_ADDR
#define HI_HSUART_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_HSUART_REGBASE_ADDR)
#endif
/* AXI DMAC */
#ifdef HI_AXIDMAC_REGBASE_ADDR
#define HI_AXIDMAC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_AXIDMAC_REGBASE_ADDR)
#endif
/* MMC HOST0 */
#ifdef HI_MMC_HOST0_REGBASE_ADDR
#define HI_MMC_HOST0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MMC_HOST0_REGBASE_ADDR)
#endif
/* MMC HOST1 */
#ifdef HI_MMC_HOST1_REGBASE_ADDR
#define HI_MMC_HOST1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MMC_HOST1_REGBASE_ADDR)
#endif
/* MMC HOST2 */
#ifdef HI_MMC_HOST2_REGBASE_ADDR
#define HI_MMC_HOST2_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MMC_HOST2_REGBASE_ADDR)
#endif
/* MMC DEV */
#ifdef HI_MMC_DEV_REGBASE_ADDR
#define HI_MMC_DEV_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_MMC_DEV_REGBASE_ADDR)
#endif
/*SSDMAģ��*/
#ifdef HI_SSDMA_REGBASE_ADDR
#define HI_SSDMA_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_SSDMA_REGBASE_ADDR)
#endif
/* USB2 OTG */
#ifdef HI_USB2OTG_REGBASE_ADDR
#define HI_USB2OTG_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_USB2OTG_REGBASE_ADDR)
#endif
/* CICOM0 */
#ifdef HI_CICOM0_REGBASE_ADDR
#define HI_CICOM0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_CICOM0_REGBASE_ADDR)
#endif
/* CICOM1 */
#ifdef HI_CICOM1_REGBASE_ADDR
#define HI_CICOM1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_CICOM1_REGBASE_ADDR)
#endif
/* HDLC */
#ifdef HI_HDLC_REGBASE_ADDR
#define HI_HDLC_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_HDLC_REGBASE_ADDR)
#endif
/* DM */
#ifdef HI_DM_REGBASE_ADDR
#define HI_DM_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_DM_REGBASE_ADDR)
#endif
/* VIC0 */
#ifdef HI_VIC0_REGBASE_ADDR
#define HI_VIC0_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_VIC0_REGBASE_ADDR)
#endif
/* VIC1 */
#ifdef HI_VIC1_REGBASE_ADDR
#define HI_VIC1_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_VIC1_REGBASE_ADDR)
#endif
/* VIC2 */
#ifdef HI_VIC2_REGBASE_ADDR
#define HI_VIC2_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_VIC2_REGBASE_ADDR)
#endif
/* VIC3 */
#ifdef HI_VIC3_REGBASE_ADDR
#define HI_VIC3_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_VIC3_REGBASE_ADDR)
#endif
/* GU MDM VIC */
#ifdef HI_MDM_GU_VIC_BASE_ADDR
#define HI_MDM_GU_VIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_MDM_GU_VIC_BASE_ADDR)
#endif
/* GU APP VIC */
#ifdef HI_APP_GU_VIC_BASE_ADDR
#define HI_APP_GU_VIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_APP_GU_VIC_BASE_ADDR)
#endif
/* PCIE0PHY */
#ifdef HI_PCIE0PHY_REGBASE_ADDR
#define HI_PCIE0PHY_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE0PHY_REGBASE_ADDR)
#endif
/* UPACC */
#ifdef HI_UPACC_BASE_ADDR
#define HI_UPACC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_UPACC_BASE_ADDR)
#endif
/* BOOTROM */
#ifdef HI_BOOTROM_REGBASE_ADDR
#define HI_BOOTROM_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_BOOTROM_REGBASE_ADDR)
#endif
/* USB3 */
#ifdef HI_USB3_REGBASE_ADDR
#define HI_USB3_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_USB3_REGBASE_ADDR)
#endif
/* NANDC */
#ifdef HI_NAND_MEM_BUFFER_ADDR
#define HI_NAND_MEM_BUFFER_ADDR_VIRT HI_IO_ADDRESS(HI_NAND_MEM_BUFFER_ADDR)
#endif
/* STM */
#ifdef HI_STM_BASE_ADDR
#define HI_STM_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_STM_BASE_ADDR)
#endif

/* AXI EXP32 */
#ifdef HI_AXI_EXP32_BASE_ADDR
#define HI_AXI_EXP32_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AXI_EXP32_BASE_ADDR)
#endif
/* AXI EXP64 */
#ifdef HI_AXI_EXP64_BASE_ADDR
#define HI_AXI_EXP64_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_AXI_EXP64_BASE_ADDR)
#endif
/* PCIE0 DATA */
#ifdef HI_PCIE0_DATA_BASE_ADDR
#define HI_PCIE0_DATA_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE0_DATA_BASE_ADDR)
#endif
/* PCIE0 CFG */
#ifdef HI_PCIE0_CFG_BASE_ADDR
#define HI_PCIE0_CFG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE0_CFG_BASE_ADDR)
#endif
/* PCIE1 CFG */
#ifdef HI_PCIE1_CFG_BASE_ADDR
#define HI_PCIE1_CFG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE1_CFG_BASE_ADDR)
#endif
/* PCIE DATA */
#ifdef HI_PCIE_DATA_BASE_ADDR
#define HI_PCIE_DATA_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE_DATA_BASE_ADDR)
#endif
/* PCIE CFG */
#ifdef HI_PCIE_CFG_BASE_ADDR
#define HI_PCIE_CFG_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCIE_CFG_BASE_ADDR)
#endif
/* FPGA */
#ifdef HI_GU_SOC_BASE_ADDR
#define HI_GU_SOC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_GU_SOC_BASE_ADDR)
#endif
#ifdef HI_LTE_DRX_BASE_ADDR
#define HI_LTE_DRX_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_LTE_DRX_BASE_ADDR)
#endif
#ifdef HI_FPGA_PMUSSI_BASE_ADDR
#define HI_FPGA_PMUSSI_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_FPGA_PMUSSI_BASE_ADDR)
#endif
#ifdef HI_DSP_VIC_BASE_ADDR
#define HI_DSP_VIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP_VIC_BASE_ADDR)
#endif
/* MDM VIC */
#ifdef HI_MDM_VIC_BASE_ADDR
#define HI_MDM_VIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_MDM_VIC_BASE_ADDR)
#endif
/* APP VIC */
#ifdef HI_APP_VIC_BASE_ADDR
#define HI_APP_VIC_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_APP_VIC_BASE_ADDR)
#endif
/* FPGA BBP*/
#ifdef HI_FPGA_BBP_BASE_ADDR
#define HI_FPGA_BBP_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_FPGA_BBP_BASE_ADDR)
#endif
/* CIPHER */
#ifdef HI_CIPHER_BASE_ADDR
#define HI_CIPHER_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CIPHER_BASE_ADDR)
#endif
/* BBP DMA */
#ifdef HI_BBP_DMA_BASE_ADDR
#define HI_BBP_DMA_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_DMA_BASE_ADDR)
#endif
/* BBP INT */
#ifdef HI_BBP_UL_BASE_ADDR
#define HI_BBP_UL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_UL_BASE_ADDR)
#endif
/* BBP INT */
#ifdef HI_BBP_INT_BASE_ADDR
#define HI_BBP_INT_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_INT_BASE_ADDR)
#endif
/* BBP STU */
#ifdef HI_BBP_STU_BASE_ADDR
#define HI_BBP_STU_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_STU_BASE_ADDR)
#endif
/*BBP TDS TF*/
#ifdef HI_BBP_TDSINT_BASE_ADDR
#define HI_BBP_TDSINT_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_TDSINT_BASE_ADDR)
#endif
/*BBP TDS STU INT*/
#ifdef HI_BBP_TSTU_BASE_ADDR
#define HI_BBP_TSTU_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_TSTU_BASE_ADDR)
#endif
/*BBP LTE DRX*/
#ifdef HI_BBP_LTEDRX_BASE_ADDR
#define HI_BBP_LTEDRX_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_LTEDRX_BASE_ADDR)
#endif
/*BBP TDS DRX*/
#ifdef HI_BBP_TDSDRX_BASE_ADDR
#define HI_BBP_TDSDRX_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_BBP_TDSDRX_BASE_ADDR)
#endif

/* DSP */
#ifdef HI_DSP0DMEM0_BASE_ADDR
#define HI_DSP0DMEM0_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP0DMEM0_BASE_ADDR)
#endif

#ifdef HI_DSP0DMEM1_BASE_ADDR
#define HI_DSP0DMEM1_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP0DMEM1_BASE_ADDR)
#endif

#ifdef HI_DSP0IMEM0_BASE_ADDR
#define HI_DSP0IMEM0_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP0IMEM0_BASE_ADDR)
#endif

#ifdef HI_DSP0IMEM1_BASE_ADDR
#define HI_DSP0IMEM1_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_DSP0IMEM1_BASE_ADDR)
#endif

/* HIFI */
#ifdef HI_HIFI2DMEM0_BASE_ADDR
#define HI_HIFI2DMEM0_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_HIFI2DMEM0_BASE_ADDR)
#endif

#ifdef HI_HIFI2DMEM1_BASE_ADDR
#define HI_HIFI2DMEM1_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_HIFI2DMEM1_BASE_ADDR)
#endif

#ifdef HI_HIFI2IMEM0_BASE_ADDR
#define HI_HIFI2IMEM0_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_HIFI2IMEM0_BASE_ADDR)
#endif

#ifdef HI_HIFI2IMEM1_BASE_ADDR
#define HI_HIFI2IMEM1_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_HIFI2IMEM1_BASE_ADDR)
#endif

/* CoreSight STM */
#ifdef HI_CORESIGHT_STM_BASE_ADDR
#define HI_CORESIGHT_STM_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_STM_BASE_ADDR)
#endif
/* CoreSight ETF */
#ifdef HI_CORESIGHT_ETF_BASE_ADDR
#define HI_CORESIGHT_ETF_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_ETF_BASE_ADDR)
#endif
/* CoreSight CTI */
#ifdef HI_CORESIGHT_CTI_BASE_ADDR
#define HI_CORESIGHT_CTI_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_CTI_BASE_ADDR)
#endif
/* CoreSight FUNNEL */
#ifdef HI_CORESIGHT_FUNNEL_BASE_ADDR
#define HI_CORESIGHT_FUNNEL_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_FUNNEL_BASE_ADDR)
#endif
/* CoreSight ETR */
#ifdef HI_CORESIGHT_ETR_BASE_ADDR
#define HI_CORESIGHT_ETR_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_ETR_BASE_ADDR)
#endif
/* CoreSight Core0 PTM */
#ifdef HI_CORESIGHT_PTM0_BASE_ADDR
#define HI_CORESIGHT_PTM0_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_PTM0_BASE_ADDR)
#endif
/* CoreSight Core1 PTM */
#ifdef HI_CORESIGHT_PTM1_BASE_ADDR
#define HI_CORESIGHT_PTM1_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_CORESIGHT_PTM1_BASE_ADDR)
#endif

/* fpga �����ռ䣬Ϊ��ȡ��ģ/��ģ ģʽ�Ĵ�����ӳ���������ﻪ��ע */
#ifdef HI_FPGA_RESERVED_SPACE_FOR_MODE_SW_BASE_ADDR
#define HI_FPGA_RESERVED_SPACE_FOR_MODE_SW_BASE_ADDR_VIRT HI_IO_ADDRESS(HI_FPGA_RESERVED_SPACE_FOR_MODE_SW_BASE_ADDR)
#endif

#ifdef HI_PCTRL_REGBASE_ADDR
#define HI_PCTRL_REGBASE_ADDR_VIRT HI_IO_ADDRESS(HI_PCTRL_REGBASE_ADDR)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __BSP_MEMMAP_H__ */
