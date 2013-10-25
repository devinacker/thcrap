/**
  * Win32 UTF-8 wrapper
  *
  * ----
  *
  * gdi32.dll functions.
  */

#include "win32_utf8.h"

HFONT WINAPI CreateFontU(
	__in int cHeight,
	__in int cWidth,
	__in int cEscapement,
	__in int cOrientation,
	__in int cWeight,
	__in DWORD bItalic,
	__in DWORD bUnderline,
	__in DWORD bStrikeOut,
	__in DWORD iCharSet,
	__in DWORD iOutPrecision,
	__in DWORD iClipPrecision,
	__in DWORD iQuality,
	__in DWORD iPitchAndFamily,
	__in_opt LPCSTR pszFaceName
)
{
	HFONT ret;
	WCHAR_T_DEC(pszFaceName);
	WCHAR_T_CONV(pszFaceName);
	ret = CreateFontW(
		cHeight, cWidth, cEscapement, cOrientation, cWeight, bItalic,
		bUnderline, bStrikeOut, iCharSet, iOutPrecision, iClipPrecision,
		iQuality, iPitchAndFamily, pszFaceName_w
	);
	VLA_FREE(pszFaceName_w);
	return ret;
}

BOOL APIENTRY GetTextExtentPoint32U(
	__in HDC hdc,
	__in_ecount(c) LPCSTR lpString,
	__in int c,
	__out LPSIZE psizl
)
{
	BOOL ret;
	FixedLengthStringConvert(lpString, c);
	ret = GetTextExtentPoint32W(hdc, lpString_w, wcslen(lpString_w), psizl);
	VLA_FREE(lpString_w);
	return ret;
}

BOOL WINAPI TextOutU(
	__in HDC hdc,
	__in int x,
	__in int y,
	__in_ecount(c) LPCSTR lpString,
	__in int c
)
{
	BOOL ret;
	FixedLengthStringConvert(lpString, c);
	ret = TextOutW(hdc, x, y, lpString_w, wcslen(lpString_w));
	VLA_FREE(lpString_w);
	return ret;
}
