	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 0
	.globl	__Z3addiiii                     ; -- Begin function _Z3addiiii
	.p2align	2
__Z3addiiii:                            ; @_Z3addiiii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	str	w2, [sp, #4]
	str	w3, [sp]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	add	w8, w8, w9
	ldr	w9, [sp, #4]
	add	w8, w8, w9
	ldr	w9, [sp]
	add	w0, w8, w9
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w0, #1
	mov	w1, #2
	mov	w2, #3
	mov	w3, #4
	bl	__Z3addiiii
	mov	w0, #0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
