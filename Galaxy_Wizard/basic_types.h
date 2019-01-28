#pragma once

using WORD = signed __int32;

const WORD Pawn_Value = 200;
const WORD King_Value = 500 * Pawn_Value;
const WORD Queen_Value = 11 * Pawn_Value;
const WORD Rook_Value = 6 * Pawn_Value;
const WORD Bishop_Value = WORD(4.5 * Pawn_Value);
const WORD Knight_Value = 4 * Pawn_Value;
