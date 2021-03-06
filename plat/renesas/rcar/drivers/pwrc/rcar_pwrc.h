/*
 * Copyright (c) 2013-2014, ARM Limited and Contributors. All rights reserved.
 * Copyright (c) 2015-2016, Renesas Electronics Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RCAR_PWRC_H__
#define RCAR_PWRC_H__

/* RCAR Power controller register offset etc */
#define PPOFFR_OFF		0x0
#define PPONR_OFF		0x4
#define PCOFFR_OFF		0x8
#define PWKUPR_OFF		0xc
#define PSYSR_OFF		0x10

#define PWKUPR_WEN		(1ull << 31)

#define PSYSR_AFF_L2		(1 << 31)
#define PSYSR_AFF_L1		(1 << 30)
#define PSYSR_AFF_L0		(1 << 29)
#define PSYSR_WEN		(1 << 28)
#define PSYSR_PC		(1 << 27)
#define PSYSR_PP		(1 << 26)

#define PSYSR_WK_SHIFT		(24)
#define PSYSR_WK_MASK		(0x3)
#define PSYSR_WK(x)		(((x) >> PSYSR_WK_SHIFT) & PSYSR_WK_MASK)

#define WKUP_COLD		0x0
#define WKUP_RESET		0x1
#define WKUP_PPONR		0x2
#define WKUP_GICREQ		0x3

#define	RCAR_INVALID		(0xffffffffU)
#define PSYSR_INVALID		0xffffffff

#ifndef __ASSEMBLY__

/*******************************************************************************
 * Function & variable prototypes
 ******************************************************************************/
void rcar_pwrc_setup(void);
void rcar_pwrc_clusteroff(uint64_t mpidr);
void rcar_pwrc_cpuoff(uint64_t mpidr);
void rcar_pwrc_cpuon(uint64_t mpidr);
void rcar_pwrc_enable_interrupt_wakeup(uint64_t mpidr);
void rcar_pwrc_disable_interrupt_wakeup(uint64_t mpidr);
uint32_t rcar_pwrc_status(uint64_t mpidr);
uint32_t rcar_pwrc_get_cpu_wkr(uint64_t mpidr);
void bl31_secondly_reset(void);

/* for Suspend to RAM */
void rcar_bl31_go_suspend_to_ram(void);
void rcar_bl31_set_suspend_to_ram(void);
void rcar_bl31_code_copy_to_system_ram(void);
void rcar_bl31_init_suspend_to_ram(void);

extern uint32_t rcar_bl31_asm_switch_stack_pointer(uintptr_t jump, uintptr_t stack,
                void *arg);

extern void rcar_bl31_save_generic_timer(uint64_t *rcar_stack_generic_timer);

extern uint8_t __system_ram_start__[1];
extern uint8_t __system_ram_end__[1];
extern uint8_t __SRAM_COPY_START__[1];

extern uint64_t rcar_stack_generic_timer[5];

#endif /*__ASSEMBLY__*/

#endif /* RCAR_PWRC_H__ */
