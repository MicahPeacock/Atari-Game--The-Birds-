		xdef		_clear_8
		xdef		_clear_16
		xdef		_clear_32


		xdef		_set_8
		xdef		_set_16
		xdef		_set_32


ADDRESS		equ		8
ALPHAMASK	equ		12
BITMAP		equ		12
HEIGHT		equ		16

_clear_8:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		ALPHAMASK(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts


_clear_16:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		ALPHAMASK(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts
       

_clear_32:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		ALPHAMASK(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts
        

_set_8:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		BITMAP(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts
        

_set_16:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		BITMAP(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts
        

_set_32:	link		a6,#0
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		ADDRESS(a6),a0
		move.l		BITMAP(a6),a1
		move.w		HEIGHT(a6),d0

		movem.l		(sp)+,d0-d7/a0-a6
		unlk		a6
		rts
        
        
; This is Marks code btw, NOT mine...
; quick clear (uses movem to reduce fetch-execute cycle overhead)
;
; takes about half the number of clock cycles as the code in clear.s, and
; so runs in about 1/100th of a second (at 8MHz) instead of 1/50th

		xdef		_clear_screen

base		equ		64		; offset from SP, not A6

_clear_screen:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

zeros:		ds.l		13
