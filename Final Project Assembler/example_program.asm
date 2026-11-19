PORTB = $6000       ; VIA Port B Output Register
DDRB  = $6002       ; VIA Port B Data Direction Register

      * = $8000     ; ROM / program start address

reset:
      lda #%00000001 ; Set PB0 as output
      sta DDRB

loop:
      lda #%00000001 ; Turn LED on (PB0 high)
      sta PORTB
      jsr delay

      lda #%00000000 ; Turn LED off (PB0 low)
      sta PORTB
      jsr delay

      jmp loop

delay:
      ldx #$FF
outer:
      ldy #$FF
inner:
      dey
      bne inner
      dex
      bne outer
      rts

      * = $FFFC     ; Reset vector
      .word reset