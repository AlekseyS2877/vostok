/*  Abstract syntax tree support for Oberon-07
 *  Copyright (C) 2016  ComdivByZero
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#if !defined(HEADER_GUARD_TranslatorLimits)
#define HEADER_GUARD_TranslatorLimits


/* Сканер *)
	(* длина имени */
#define TranslatorLimits_MaxLenName_cnst 63
/* длина содержимого строки, не включая завершающего 0 */
#define TranslatorLimits_MaxLenString_cnst 255
/* длина строкового представления числа */
#define TranslatorLimits_MaxLenNumber_cnst 63
/* количество пустых символов между значащими */
#define TranslatorLimits_MaxBlankChars_cnst 1023
/* Модуль *)
	(* Кол-во ипортированных модулей */
#define TranslatorLimits_MaxImportedModules_cnst 127
/* Кол-во именованных постоянных */
#define TranslatorLimits_MaxGlobalConsts_cnst 2047
/* Кол-во типов */
#define TranslatorLimits_MaxGlobalTypes_cnst 127
/* Кол-во переменных */
#define TranslatorLimits_MaxGlobalVars_cnst 255
/* Кол-во переменных, перечисленных через запятую */
#define TranslatorLimits_MaxVarsSeparatedByComa_cnst 31
/* Кол-во процедур */
#define TranslatorLimits_MaxGlobalProcedures_cnst 1023
/* Количество символов исходного кода модуля в Utf8 */
#define TranslatorLimits_MaxModuleTextSize_cnst 262143
/* Типы *)
	(* Размерность массива */
#define TranslatorLimits_MaxArrayDimension_cnst 7
/* Количество переменных в структуре */
#define TranslatorLimits_MaxVarsInRecord_cnst 255
/* Глубина расширения структур */
#define TranslatorLimits_MaxRecordExt_cnst 15
/* Процедура *)
	(* Количество параметров */
#define TranslatorLimits_MaxParams_cnst 15
/* Количество именованных постоянных */
#define TranslatorLimits_MaxConsts_cnst 255
/* Количество переменных */
#define TranslatorLimits_MaxVars_cnst 31
/* Количество линейно вложенных функций */
#define TranslatorLimits_MaxProcedures_cnst 31
/* Глубина вложенности функций */
#define TranslatorLimits_MaxDeepProcedures_cnst 7
/* Количество линейно вложенных операторов */
#define TranslatorLimits_MaxStatements_cnst 255
/* Вложенность операторов */
#define TranslatorLimits_MaxDeepStatements_cnst 15
/* Веток IF {ELSIF} ELSE */
#define TranslatorLimits_MaxIfBranches_cnst 255
/* Выражения *)
	(* Цепочка селекторов */
#define TranslatorLimits_MaxSelectors_cnst 63
/* Количество подвыражений в одной сумме */
#define TranslatorLimits_MaxTermsInSum_cnst 255
/* Количество подвыражений в умножении */
#define TranslatorLimits_MaxFactorsInTerm_cnst 255

static inline void TranslatorLimits_init(void) { ; }
#endif
