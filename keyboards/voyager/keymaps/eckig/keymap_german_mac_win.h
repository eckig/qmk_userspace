#pragma once
#include "keycodes.h"

// Aliases
#define DE_CIRC KC_GRV  // ^ (dead)
#define DE_1    KC_1    // 1
#define DE_2    KC_2    // 2
#define DE_3    KC_3    // 3
#define DE_4    KC_4    // 4
#define DE_5    KC_5    // 5
#define DE_6    KC_6    // 6
#define DE_7    KC_7    // 7
#define DE_8    KC_8    // 8
#define DE_9    KC_9    // 9
#define DE_0    KC_0    // 0
#define DE_SS   KC_MINS // ß
#define DE_ACUT KC_EQL  // ´ (dead)
#define DE_Q    KC_Q    // Q
#define DE_W    KC_W    // W
#define DE_E    KC_E    // E
#define DE_R    KC_R    // R
#define DE_T    KC_T    // T
#define DE_Z    KC_Y    // Z
#define DE_U    KC_U    // U
#define DE_I    KC_I    // I
#define DE_O    KC_O    // O
#define DE_P    KC_P    // P
#define DE_UDIA KC_LBRC // Ü
#define DE_PLUS KC_RBRC // +
#define DE_A    KC_A    // A
#define DE_S    KC_S    // S
#define DE_D    KC_D    // D
#define DE_F    KC_F    // F
#define DE_G    KC_G    // G
#define DE_H    KC_H    // H
#define DE_J    KC_J    // J
#define DE_K    KC_K    // K
#define DE_L    KC_L    // L
#define DE_ODIA KC_SCLN // Ö
#define DE_ADIA KC_QUOT // Ä
#define DE_HASH KC_NUHS // #
#define DE_LABK KC_NUBS // <
#define DE_Y    KC_Z    // Y
#define DE_X    KC_X    // X
#define DE_C    KC_C    // C
#define DE_V    KC_V    // V
#define DE_B    KC_B    // B
#define DE_N    KC_N    // N
#define DE_M    KC_M    // M
#define DE_COMM KC_COMM // ,
#define DE_DOT  KC_DOT  // .
#define DE_MINS KC_SLSH // -
#define DE_DEG  S(DE_CIRC) // °
#define DE_EXLM S(DE_1)    // !
#define DE_DQUO S(DE_2)    // "
#define DE_SECT S(DE_3)    // §
#define DE_DLR  S(DE_4)    // $
#define DE_PERC S(DE_5)    // %
#define DE_AMPR S(DE_6)    // &
#define DE_SLSH S(DE_7)    // /
#define DE_LPRN S(DE_8)    // (
#define DE_RPRN S(DE_9)    // )
#define DE_EQL  S(DE_0)    // =
#define DE_QUES S(DE_SS)   // ?
#define DE_GRV  S(DE_ACUT) // ` (dead)
#define DE_ASTR S(DE_PLUS) // *
#define DE_QUOT S(DE_HASH) // '
#define DE_RABK S(DE_LABK) // >
#define DE_SCLN S(DE_COMM) // ;
#define DE_COLN S(DE_DOT)  // :
#define DE_UNDS S(DE_MINS) // _

#define PC_LCBR ALGR(DE_7)    // {
#define PC_LBRC ALGR(DE_8)    // [
#define PC_RBRC ALGR(DE_9)    // ]
#define PC_RCBR ALGR(DE_0)    // }
#define PC_BSLS ALGR(DE_SS)   // (backslash)
#define PC_AT   ALGR(DE_Q)    // @
#define PC_EURO ALGR(DE_E)    // €
#define PC_TILD ALGR(DE_PLUS) // ~
#define PC_PIPE ALGR(DE_LABK) // |
#define PC_MICR ALGR(DE_M)    // µ

#define MAC_LCBR A(DE_8)      // {
#define MAC_LBRC A(DE_5)      // [
#define MAC_RBRC A(DE_6)      // ]
#define MAC_RCBR A(DE_9)      // }
#define MAC_BSLS S(A(DE_7))   // (backslash)
#define MAC_AT   A(DE_L)      // @
#define MAC_EURO A(DE_E)      // €
#define MAC_TILD A(DE_N)      // ~ (dead)
#define MAC_PIPE A(DE_7)      // |
#define MAC_MICR A(DE_M)      // µ

