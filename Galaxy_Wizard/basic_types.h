#pragma once

using DWORD = signed __int64;

const DWORD Pawn_Value = 200;
const DWORD King_Value = 500 * Pawn_Value;
const DWORD Queen_Value = 11 * Pawn_Value;
const DWORD Rook_Value = 6 * Pawn_Value;
const DWORD Bishop_Value = DWORD(4.5 * Pawn_Value);
const DWORD Knight_Value = 4 * Pawn_Value;
