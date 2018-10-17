// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-NumPad.h"
#include "Kaleidoscope-LED-Stalker.h"
/* #include "Kaleidoscope-LED-ActiveModColor.h" */
#include "Kaleidoscope-USB-Quirks.h"
/* #include "Kaleidoscope-OneShot.h" */
/* #include "Kaleidoscope-Unicode.h" */

enum {
       MENTER_ONCE,
       MUNDERSCORE,
       MEMOJI_SHRUG,
       MEMOJI_THINKING,
       MEMOJI_KISS,
       MEMOJI_BEER,
       MEMOJI_CHEERS,
       MEMOJI_HAMSICK,
       MEMOJI_ANARCHY,
       MSCROLL_LEFT,
       MSCROLL_RIGHT
     };

enum { QWERTY, EMOJI, NUMPAD, FUNCTION, WORD_EDIT, CLIPBOARD };

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (Key_mouseBtnL,           Key_1, Key_2, Key_3, Key_4, Key_5, Key_mouseBtnR,
   Key_Tab,                 Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Backtick,
   Key_LeftControl,         Key_A, Key_S, Key_D, Key_F, Key_G,
   ShiftToLayer(CLIPBOARD), Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   M(MUNDERSCORE),          Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   LALT(Key_Spacebar), Key_6, Key_7, Key_8,     Key_9,      Key_0,         LockLayer(NUMPAD),
   Key_Home,           Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
                       Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   ___,                Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,
   ShiftToLayer(WORD_EDIT), Key_Enter, Key_Spacebar, Key_RightAlt,
   ShiftToLayer(FUNCTION)),

  [EMOJI] =  KEYMAP_STACKED
  (___, ___,               ___,             ___,              ___, ___,                ___,
   ___, ___,               ___,             ___,              ___, M(MEMOJI_THINKING), ___,
   ___, M(MEMOJI_ANARCHY), M(MEMOJI_SHRUG), ___,              ___, ___,
   ___, ___,               ___,             M(MEMOJI_CHEERS), ___, M(MEMOJI_BEER),     ___,
   ___, ___, ___, ___,
   ___,

   ___, ___,               ___, ___, ___, ___,  ___,
   ___, ___,               ___, ___, ___, ___,  ___,
        M(MEMOJI_HAMSICK), ___, M(MEMOJI_KISS), ___, ___, ___,
   ___, ___,               ___, ___, ___, ___,  ___,
   ___, ___, ___, ___,
   ___),

  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___,                Key_Equals,  Key_KeypadMultiply, Key_KeypadDivide, ___, ___,
   ___, ___,                Key_Keypad7, Key_Keypad8,        Key_Keypad9,      ___, ___,
        Key_KeypadAdd,      Key_Keypad4, Key_Keypad5,        Key_Keypad6,      ___, ___,
   ___, Key_KeypadSubtract, Key_Keypad1, Key_Keypad2,        Key_Keypad3,      ___, ___,
   ShiftToLayer(WORD_EDIT), Key_Enter, Key_Keypad0, Key_KeypadDot,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (M(MENTER_ONCE),     Key_F1,        Key_F2,        Key_F3,               Key_F4,                Key_F5,                XXX,
   LSHIFT(Key_Equals), LSHIFT(Key_1), LSHIFT(Key_2), Key_LeftParen,        Key_RightParen,        Key_Pipe,              Key_mouseWarpNE,
   Key_Equals,         LSHIFT(Key_3), LSHIFT(Key_4), Key_LeftCurlyBracket, Key_RightCurlyBracket, Key_Minus,
   Key_End,            LSHIFT(Key_5), LSHIFT(Key_6), Key_LeftBracket,      Key_RightBracket,      LSHIFT(Key_Backtick),  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          LSHIFT(Key_7),          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, LALT(Key_Enter), Key_Enter, ___,
   ___),

  [WORD_EDIT] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___,   ___, ___,
   ___, ___, ___, ___, ___,   ___, ___,
   ___, ___, ___, ___, ___,   ___,
   ___, ___, ___, ___, ___,   ___, ___,
   ___, LCTRL(Key_Backspace), ___, ___,
   ___,

   ___,     ___,                  ___,                  ___,                ___,                   ___, ___,
   Key_End, LALT(Key_LeftArrow),  LALT(Key_DownArrow),  LALT(Key_UpArrow),  LALT(Key_RightArrow),  ___, ___,
            LCTRL(Key_LeftArrow), LCTRL(Key_DownArrow), LCTRL(Key_UpArrow), LCTRL(Key_RightArrow), ___, ___,
   ___,     M(MSCROLL_LEFT),      Key_mouseScrollDn,    Key_mouseScrollUp,  M(MSCROLL_RIGHT),      ___, ___,
   ___, ___, ___, ___,
   ___),

  [CLIPBOARD] =  KEYMAP_STACKED
  (___, ___,              ___,             ___,              ___,               ___, ___,
   ___, ___,              ___,             ___,              ___,               ___, ___,
   ___, ___,              ___,             ___,              ___,               ___,
   ___, Consumer_AC_Undo, Consumer_AC_Cut, Consumer_AC_Copy, Consumer_AC_Paste, ___, ___,
   ___,                   ___,             ___,              ___,
   ___,

   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___),

  /* [NEW_LAYER] =  KEYMAP_STACKED */
  /* (___, ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, */
  /*  ___, */

  /*  ___, ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, ___, ___, ___, */
  /*       ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, ___, ___, ___, */
  /*  ___, ___, ___, ___, */
  /*  ___), */
)


/* static void shrug() { */
/*   Unicode.type(0xaf); */
/*   Macros.play(MACRO(Tc(Backslash), */
/*                     D(RightShift), */
/*                     Tc(Minus), */
/*                     Tc(9), */
/*                     U(RightShift))); */
/*   Unicode.type(0x30c4); */
/*   Macros.play(MACRO(D(RightShift), */
/*                     Tc(0), */
/*                     Tc(Minus), */
/*                     U(RightShift), */
/*                     Tc(Slash))); */
/*   Unicode.type(0xaf); */
/* } */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    switch (macroIndex) {
      case MENTER_ONCE:
        Macros.play(MACRODOWN(T(Enter)));
        break;
      case MUNDERSCORE:
        Macros.play(MACRODOWN(D(LeftShift), T(Minus), U(LeftShift)));
        break;
      case MEMOJI_SHRUG:
        /* shrug(); */
        break;
      // NOTE: For Emojis you want the UTF16-BE (Big-Endian) hex
      case MEMOJI_THINKING:
        /* Unicode.type(0xD83EDD14); */
        break;
      case MEMOJI_KISS:
        /* Unicode.type(0xD83DDE18); */
        break;
      case MEMOJI_BEER:
        /* Unicode.type(0xD83CDF7A); */
        break;
      case MEMOJI_CHEERS:
        /* Unicode.type(0xD83CDF7B); */
        break;
      case MEMOJI_HAMSICK:
        /* Unicode.type(0x262D); */
        break;
      case MEMOJI_ANARCHY:
        /* Unicode.type(0x24B6); */
        break;
    }

  } else if (keyIsPressed(keyState)) {
    switch (macroIndex) {
      case MSCROLL_LEFT:
        handleKeyswitchEvent(Key_LeftShift, Macros.row, Macros.col, keyState);
        handleKeyswitchEvent(Key_mouseScrollDn, Macros.row, Macros.col, keyState);
        break;

      case MSCROLL_RIGHT:
        handleKeyswitchEvent(Key_LeftShift, Macros.row, Macros.col, keyState);
        handleKeyswitchEvent(Key_mouseScrollUp, Macros.row, Macros.col, keyState);
        break;
    }
  }

  return MACRO_NONE;
}

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in changing some settings of the keyboard, such as the default layer (via the `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
  /* Unicode, */
  /* OneShot, */
  StalkerEffect,
  NumPad,
  Macros,
  MouseKeys,
  USBQuirks
);

void setup() {
  Kaleidoscope.setup();

  NumPad.numPadLayer = NUMPAD;
  StalkerEffect.variant = STALKER(BlazingTrail);
  StalkerEffect.activate();
}

void loop() {
  Kaleidoscope.loop();
}
